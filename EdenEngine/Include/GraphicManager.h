#pragma once
#include "Effect.h"
#include "Buffer.h"
#include "UsefulMath.h"
#include "VertexTypes.h"
#include "Direct3DInitializer.h"
#include "Texture.h"

enum VERTEX_TYPE{VERTEX_TYPE_COLOR,VERTEX_TYPE_TEXTURE,VERTEX_TYPE_NONE};

struct BILLBOARD_DATA{
	CVector4D position;
	CVector2D halfSize;
};

class CGraphicManager{
public:
	CGraphicManager(CDirect3DInitializer* direct3DInitializer, float halfHorizontalViewAngle, int screenWidth, int screenHeight, float nearPlane, float farPlane);
	virtual ~CGraphicManager(void);

	void setWorldMatrix(CMatrix* pWorldMatrix);
	void setViewMatrix(CMatrix* pViewMatrix);
	void setProjectionMatrix(CMatrix* pProjectionMatrix);

	void drawVertices(UINT startIndex, UINT numIndices, VERTEX_TYPE type);

	void setTexture(ID3D10ShaderResourceView* texture);

	void start2DRendering();

	void stop2DRendering();

	void drawImage(ID3D10ShaderResourceView* texture, float x, float y, float width, float height, float rotAngle, float rotCenterX, float rotCenterY, bool relCoordinates);

	void drawImage(CTexture* texture, float x, float y, float width, float height, float rotAngle, float rotCenterX, float rotCenterY, bool relCoordinates);

	void drawImage(CTexture* texture, float x, float y, float rotAngle, float rotCenterX, float rotCenterY, bool relCoordinates);

	void startBillBoardRendering();

	void stopBillBoardRendering();

	void drawBillBoard(ID3D10ShaderResourceView* texture, float x, float y, float z, float halfWidth, float halfHeight, bool verticalOnly);

	void acticateInputLayout(VERTEX_TYPE type);

public:
	ID3D10Device* getDevice(void){
		return device;
	}

	CEffect* getDefaultEffect(void){
		return defaultEffect;
	}

protected:

	ID3D10EffectMatrixVariable* effectWorldMatrix;
	ID3D10EffectMatrixVariable* effectViewMatrix;
	ID3D10EffectMatrixVariable* effectProjectionMatrix;
	ID3D10EffectMatrixVariable* effectMatrix2D;

	ID3D10DepthStencilState* depthStencilState2D;
	
	ID3D10DepthStencilState* oldDepthStencilState;
	UINT oldStencilRef;

	CEffect* defaultEffect;

	ID3D10ShaderResourceView* currentTexture;
	ID3D10EffectShaderResourceVariable* effectTextureVariable;

	CBuffer* pointVertexBuffer;
	ID3D10Device* device;

	D3D10_PRIMITIVE_TOPOLOGY oldPrimitiveTopology;

	float doubleInvScreenWidth, doubleInvScreenHeight;

	CDirect3DInitializer* direct3DInitializer;

	VERTEX_TYPE selectedInputLayout;

	ID3D10InputLayout* oldInputLayout;

protected:
	void initMatrixes(float halfHorizontalViewAngle,float aspect, float screenWidth,float screenHeight, float farPlane);
	
	void initBuffers();

	void createDepthStencilState2D();
};