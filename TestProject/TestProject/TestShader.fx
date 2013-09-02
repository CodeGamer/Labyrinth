
matrix worldMatrix;
matrix viewMatrix;
matrix projectionMatrix;

matrix matrix2D;

Texture2D currentTexture;

struct ColorVertexInput{
	float3 position : POSITION;
	float4 color : COLOR;
};

struct ColorPixelInput{
	float4 position : SV_POSITION;
	float4 color : COLOR;
};



ColorPixelInput colorVertexShader(ColorVertexInput input){
	ColorPixelInput output;
	output.position = mul(mul(mul(float4(input.position,1.0f),worldMatrix),viewMatrix),projectionMatrix);
	output.color = input.color;
	return output;
}

float4 colorPixelShader(ColorPixelInput input):SV_TARGET{
	return input.color;
}

SamplerState DefaultSampler{
	FILTER = MIN_MAG_MIP_LINEAR;
	AddressU = Wrap;
	AddressV = Wrap;
};

struct TextureVertexInput{
	float3 position : POSITION;
	float2 textureCoordinates : TEXCOORD;
};

struct TexturePixelInput{
	float4 position : SV_POSITION;
	float2 textureCoordinates : TEXCOORD;
};

TexturePixelInput textureVertexShader(TextureVertexInput input){
	TexturePixelInput output;
	output.position = mul(mul(mul(float4(input.position,1.0f),worldMatrix),viewMatrix),projectionMatrix);
	output.textureCoordinates = input.textureCoordinates;
	return output;
}

float4 texturePixelShader(TexturePixelInput input):SV_TARGET{
	float4 color = currentTexture.Sample(DefaultSampler,input.textureCoordinates);
	clip(color.g - 0.25f);
	return color;
}

technique10 colorTechnique{
	pass pass0{
		SetVertexShader(CompileShader(vs_4_0, colorVertexShader()));
		SetPixelShader(CompileShader(ps_4_0, colorPixelShader()));
		SetGeometryShader(NULL);
	}	
}

technique10 textureTechnique{
	pass pass0{
		SetVertexShader(CompileShader(vs_4_0, textureVertexShader()));
		SetPixelShader(CompileShader(ps_4_0, texturePixelShader()));
		SetGeometryShader(NULL);
	}	
}

struct BillBoardInput{
	float4 position: POSITION;
	float2 halfSize: SIZE;
};


[maxvertexcount(4)]
void billBoardGeometryShader(point BillBoardInput input[1], inout TriangleStream<TexturePixelInput> outputStream){
		TexturePixelInput output;
		float3 right = (viewMatrix._m00_m10_m20)*input[0].halfSize.x;
		float3 up;
		if(input[0].position.w == 0){
			up = (viewMatrix._m01_m11_m21)*input[0].halfSize.y;
		}else{
			up = float3(0,input[0].halfSize.y,0);
		}
		output.position = mul(mul(float4(-up-right+input[0].position.xyz,1.0f),viewMatrix),projectionMatrix);
		output.textureCoordinates = float2(0,1.0f);
		outputStream.Append(output);

		output.position = mul(mul(float4(up-right+input[0].position.xyz,1.0f),viewMatrix),projectionMatrix);
		output.textureCoordinates = float2(0,0);
		outputStream.Append(output);

		output.position = mul(mul(float4(-up+right+input[0].position.xyz,1.0f),viewMatrix),projectionMatrix);
		output.textureCoordinates = float2(1.0f,1.0f);
		outputStream.Append(output);

		output.position = mul(mul(float4(up+right+input[0].position.xyz,1.0f),viewMatrix),projectionMatrix);
		output.textureCoordinates = float2(1.0f,0);
		outputStream.Append(output);
}

BillBoardInput billBoardVertexShader(BillBoardInput input){
	BillBoardInput output;
	
	output.position = input.position;
	output.halfSize = input.halfSize;
	return output;
}

technique10 billBoardTechnique{
	pass pass0{
		SetVertexShader(CompileShader(vs_4_0, billBoardVertexShader()));
		SetGeometryShader(CompileShader(gs_4_0, billBoardGeometryShader()));
		SetPixelShader(CompileShader(ps_4_0, texturePixelShader()));
	}	
}

[maxvertexcount(4)]
void texture2DGeometryShader(point BillBoardInput input[1], inout TriangleStream<TexturePixelInput> outputStream){
		TexturePixelInput output;
		float2 right = input[0].position.zw*input[0].halfSize.x;
		float2 down = float2(input[0].position.w,-input[0].position.z)*input[0].halfSize.y;

		output.position = float4(input[0].position.xy + down,0.5f,1.0f);
		output.textureCoordinates = float2(0,1.0f);
		outputStream.Append(output);

		output.position = float4(input[0].position.xy,0.5f,1.0f);
		output.textureCoordinates = float2(0,0);
		outputStream.Append(output);

		output.position = float4(input[0].position.xy + down + right,0.5f,1.0f);
		output.textureCoordinates = float2(1.0f,1.0f);
		outputStream.Append(output);

		output.position = float4(input[0].position.xy + right,0.5f,1.0f);
		output.textureCoordinates = float2(1.0f,0);
		outputStream.Append(output);
}

technique10 image2DTechnique{
	pass pass0{
		SetVertexShader(CompileShader(vs_4_0, billBoardVertexShader()));
		SetGeometryShader(CompileShader(gs_4_0, texture2DGeometryShader()));
		SetPixelShader(CompileShader(ps_4_0, texturePixelShader()));
	}	
}