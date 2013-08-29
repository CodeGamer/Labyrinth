#pragma once

#include "Vector4D.h"
#include "Vector3D.h"
#include "Vector2D.h"
#include "Matrix.h"
#include <stdlib.h>
#include <time.h>



class CMath{
public:

	//Vector 4D
	static void Vector4DMultiplyComponentwise(CVector4D& target, CVector4D& vector1, CVector4D& vector2){
		target.x = vector1.x*vector2.x;
		target.y = vector1.y*vector2.y;
		target.z = vector1.z*vector2.z;
		target.w = vector1.w*vector2.w;
	}
	static void Vector4DDivideComponentwise(CVector4D& target, CVector4D& vector1, CVector4D& vector2){
		target.x = vector1.x/vector2.x;
		target.y = vector1.y/vector2.y;
		target.z = vector1.z/vector2.z;
		target.w = vector1.w/vector2.w;
	}

	static void Vector4DProjectAonB(CVector4D& target, CVector4D& a, CVector4D& b){
		target.equate(b);
		target*= (a*b)/(b.getSquaredLength());
	}

	static void Vector4DComputePerpendicularPartOfAonB(CVector4D& target, CVector4D& a, CVector4D& b){
		Vector4DProjectAonB(target,a,b);
		target.flip();
		target += a;
	}

	static float Vector4DGetSquaredDistanceBetweenPoints(CVector4D& point1, CVector4D& point2){
		float dx = point1.x - point2.x;
		float dy = point1.y - point2.y;
		float dz = point1.z - point2.z;
		float dw = point1.w - point2.w;
		return dx*dx + dy*dy + dz*dz + dw*dw;
	}

	static float Vector4DGetDistanceBetweenPoints(CVector4D& point1, CVector4D& point2){
		return sqrtf(Vector4DGetSquaredDistanceBetweenPoints(point1,point2));
	}
	static float Vector4DGetCosAngle(CVector4D& vector1, CVector4D& vector2){
		return (vector1*vector2)/(sqrtf(vector1.getSquaredLength()*vector2.getSquaredLength()));
	}
	static float Vector4DGetAngle(CVector4D& vector1, CVector4D& vector2){
		return acos(Vector4DGetCosAngle(vector1,vector2));
	}

	//Vector 3D

	static void Vector3DCrossProduct(CVector3D& target, CVector3D& vector1, CVector3D& vector2){
		target.x = vector1.y*vector2.z - vector1.z*vector2.y;
		target.y = vector1.z*vector2.x - vector1.x*vector2.z;
		target.z = vector1.x*vector2.y - vector1.y*vector2.x;
	}
	static void Vector3DMultiplyComponentwise(CVector3D& target, CVector3D& vector1, CVector3D& vector2){
		target.x = vector1.x*vector2.x;
		target.y = vector1.y*vector2.y;
		target.z = vector1.z*vector2.z;
	}
	static void Vector3DDivideComponentwise(CVector3D& target, CVector3D& vector1, CVector3D& vector2){
		target.x = vector1.x/vector2.x;
		target.y = vector1.y/vector2.y;
		target.z = vector1.z/vector2.z;
	}

	static void Vector3DProjectAonB(CVector3D& target, CVector3D& a, CVector3D& b){
		target.equate(b);
		target*= (a*b)/(b.getSquaredLength());
	}

	static void Vector3DComputePerpendicularPartOfAonB(CVector3D& target, CVector3D& a, CVector3D& b){
		Vector3DProjectAonB(target,a,b);
		target.flip();
		target += a;
	}

	static float Vector3DGetSquaredDistanceBetweenPoints(CVector3D& point1, CVector3D& point2){
		float dx = point1.x - point2.x;
		float dy = point1.y - point2.y;
		float dz = point1.z - point2.z;
		return dx*dx + dy*dy + dz*dz;
	}

	static float Vector3DGetDistanceBetweenPoints(CVector3D& point1, CVector3D& point2){
		return sqrtf(Vector3DGetSquaredDistanceBetweenPoints(point1,point2));
	}
	static float Vector3DGetCosAngle(CVector3D& vector1, CVector3D& vector2){
		return (vector1*vector2)/(sqrtf(vector1.getSquaredLength()*vector2.getSquaredLength()));
	}
	static float Vector3DGetAngle(CVector3D& vector1, CVector3D& vector2){
		return acos(Vector3DGetCosAngle(vector1,vector2));
	}

	//Vector 2D

	static void Vector2DMultiplyComponentwise(CVector2D& target, CVector2D& vector1, CVector2D& vector2){
		target.x = vector1.x*vector2.x;
		target.y = vector1.y*vector2.y;
	}
	static void Vector2DDivideComponentwise(CVector2D& target, CVector2D& vector1, CVector2D& vector2){
		target.x = vector1.x/vector2.x;
		target.y = vector1.y/vector2.y;
	}

	static void Vector2DProjectAonB(CVector2D& target, CVector2D& a, CVector2D& b){
		target.equate(b);
		target*= (a*b)/(b.getSquaredLength());
	}
	static void Vector2DComputePerpendicularPartOfAonB(CVector2D& target, CVector2D& a, CVector2D& b){
		Vector2DProjectAonB(target,a,b);
		target.flip();
		target += a;
	}

	static float Vector2DGetSquaredDistanceBetweenPoints(CVector2D& point1, CVector2D& point2){
		float dx = point1.x - point2.x;
		float dy = point1.y - point2.y;
		return dx*dx + dy*dy;
	}

	static float Vector2DGetDistanceBetweenPoints(CVector2D& point1, CVector2D& point2){
		return sqrtf(Vector2DGetSquaredDistanceBetweenPoints(point1,point2));
	}
	static float Vector2DGetCosAngle(CVector3D& vector1, CVector3D& vector2){
		return (vector1*vector2)/(sqrtf(vector1.getSquaredLength()*vector2.getSquaredLength()));
	}
	static float Vector2DGetAngle(CVector3D& vector1, CVector3D& vector2){
		return acos(Vector3DGetCosAngle(vector1,vector2));
	}


	//Transformationsmatrizen


	static void MatrixIdentity(CMatrix& target){
		target.setValues(1,0,0,0,
						 0,1,0,0,
						 0,0,1,0,
						 0,0,0,1);
	}
	static void MatrixScaling(CMatrix& target,float s){
		target.setValues(s,0,0,0,
						 0,s,0,0,
						 0,0,s,0,
						 0,0,0,1);
	}
	static void MatrixScaling(CMatrix& target,float sX,float sY, float sZ){
		target.setValues(sX,0,0,0,
						 0,sY,0,0,
						 0,0,sZ,0,
						 0,0,0,1);
	}
	static void MatrixTranslation(CMatrix& target,float dX,float dY, float dZ){
		target.setValues(1,0,0,0,
						 0,1,0,0,
						 0,0,1,0,
						 dX,dY,dZ,1);
	}
	static void MatrixRotationX(CMatrix& target,float alpha){
		float cosAlpha = cos(alpha);
		float sinAlpha = sin(alpha);
		target.setValues(1,    0   ,     0   ,0,
						 0,cosAlpha,-sinAlpha,0,
						 0,sinAlpha,cosAlpha,0,
						 0,    0   ,    0   ,1);
	}
	static void MatrixRotationY(CMatrix& target,float alpha){
		float cosAlpha = cos(alpha);
		float sinAlpha = sin(alpha);
		target.setValues(cosAlpha ,0,sinAlpha,0,
						     0    ,1,    0   ,0,
						 -sinAlpha,0,cosAlpha,0,
						      0   ,0,    0   ,1);
	}
	static void MatrixRotationZ(CMatrix& target,float alpha){
		float cosAlpha = cos(alpha);
		float sinAlpha = sin(alpha);
		target.setValues(cosAlpha,-sinAlpha,0,0,
						 sinAlpha,cosAlpha,0,0,
						 0,0,1,0,
						 0,0,0,1);
	}
	static void MatrixRotationAxis(CMatrix& target,CVector3D& normalizedRotationAxis, float alpha){
		float cosAlpha = cos(alpha);
		float sinAlpha = sin(alpha);
		float oneMinusCosinus = 1.0f-cosAlpha;
		float temp1 = normalizedRotationAxis.x*normalizedRotationAxis.y*oneMinusCosinus;
		float temp2 = normalizedRotationAxis.x*normalizedRotationAxis.z*oneMinusCosinus;
		float temp3 = normalizedRotationAxis.y*normalizedRotationAxis.z*oneMinusCosinus;
		target.setValues(cosAlpha + normalizedRotationAxis.x*normalizedRotationAxis.x*oneMinusCosinus,temp1-normalizedRotationAxis.z*sinAlpha,temp2+normalizedRotationAxis.y*sinAlpha,0,
						 temp1+normalizedRotationAxis.z*sinAlpha,cosAlpha+normalizedRotationAxis.y*normalizedRotationAxis.y*oneMinusCosinus,temp3-normalizedRotationAxis.x*sinAlpha,0,
						 temp2 - normalizedRotationAxis.y*sinAlpha,temp3 + normalizedRotationAxis.x*sinAlpha,cosAlpha + normalizedRotationAxis.z*normalizedRotationAxis.z*oneMinusCosinus,0,
						 0,0,0,1);
	}
	
	static void MatrixViewTransformation(CMatrix& target,CVector3D& position,CVector3D& normalizedLookingDirection,CVector3D& upVector){
		CVector3D rightDirection;
		Vector3DCrossProduct(rightDirection,upVector,normalizedLookingDirection);
		rightDirection.normalize();
		Vector3DCrossProduct(upVector,normalizedLookingDirection,rightDirection);
		MatrixWorldToLokale(target,position,rightDirection,upVector,normalizedLookingDirection);
	}

	static void MatrixLokaleToWorld(CMatrix& target, CVector3D& position,CVector3D& right, CVector3D& up, CVector3D& ahead){
		target.setValues(
		right.x,right.y,right.z,0,
		up.x   ,up.y   ,up.z   ,0,
		ahead.x,ahead.y,ahead.z,0,
		position.x,position.y,position.z,1.0f
		);
	}

	static void MatrixWorldToLokale(CMatrix& target, CVector3D& position,CVector3D& right, CVector3D& up, CVector3D& ahead){
		target.setValues(
			right.x, up.x, ahead.x,0,
			right.y, up.y, ahead.y,0,
			right.z, up.z, ahead.z,0,
			-(position*right),-(position*up),-(position*ahead),1.0f);
		
	}

	static void MatrixProjectionTransformation(CMatrix& target,float halfHorizontalViewAngle, float screenWidth, float screenHeight,float nearPlane, float farPlane){
		float diff = nearPlane - farPlane;
		float b = tan(halfHorizontalViewAngle)*nearPlane;
		float h = b*screenHeight/screenWidth;
		
		target.setValues(nearPlane/b,0,0,0,
						 0,nearPlane/h,0,0,
						 0,0,-farPlane/diff,1,
						 0,0,nearPlane*farPlane/diff,0);
	}

	
	static void TransformPosition(CVector3D& target, CVector3D& source, CMatrix& transMatrix){
		target.setValues(source.x*transMatrix.m11 + source.y*transMatrix.m21 + source.z*transMatrix.m31 + transMatrix.m41,
						 source.x*transMatrix.m12 + source.y*transMatrix.m22 + source.z*transMatrix.m32 + transMatrix.m42,
						 source.x*transMatrix.m13 + source.y*transMatrix.m23 + source.z*transMatrix.m33 + transMatrix.m43);
	}

	static void TransformDirection(CVector3D& target, CVector3D& source, CMatrix& transMatrix){
		target.setValues(source.x*transMatrix.m11 + source.y*transMatrix.m21 + source.z*transMatrix.m31,
						 source.x*transMatrix.m12 + source.y*transMatrix.m22 + source.z*transMatrix.m32,
						 source.x*transMatrix.m13 + source.y*transMatrix.m23 + source.z*transMatrix.m33);
	}

	static void TransformViewToScreen(CVector3D& target, CVector3D& source, CMatrix& projectionMatrix){
		target.setValues(source.x*projectionMatrix.m11/source.z,
						 source.y*projectionMatrix.m22/source.z,
						 (projectionMatrix.m33 + projectionMatrix.m43)/source.z);
	}

	static void MatrixInvertWorldMatrix(CMatrix& target, CMatrix& source){
		float det1 = source.m22*source.m33-source.m23*source.m32;
		float det2 = source.m21*source.m33-source.m23*source.m31;
		float det3 = source.m21*source.m32-source.m22*source.m31;
		float determinant = source.m11*det1-source.m12*det2+source.m13*det3;
		float temp1 = (source.m32*source.m43-source.m33*source.m42)/determinant;
		float temp2 = (source.m31*source.m43-source.m33*source.m41)/determinant;
		float temp3 = (source.m31*source.m42-source.m32*source.m41)/determinant;
		target.setValues(det1/determinant,-(source.m12*source.m33-source.m13*source.m32)/determinant,(source.m12*source.m23 - source.m13*source.m22)/determinant,0,
						 -det2/determinant,(source.m11*source.m33-source.m13*source.m31)/determinant,-(source.m11*source.m23 - source.m13*source.m21)/determinant,0,
						 det3/determinant,-(source.m11*source.m32 - source.m12*source.m31)/determinant,(source.m11*source.m22 - source.m12*source.m21)/determinant,0,
						 -source.m21*temp1 + source.m22*temp2-source.m23*temp3,source.m11*temp1-source.m12*temp2+source.m13*temp3,-(source.m11*(source.m22*source.m43 - source.m23*source.m42) - source.m12*(source.m21*source.m43-source.m23*source.m41)+ source.m13*(source.m21*source.m42 - source.m22*source.m41))/determinant,1);
	}

	static void MatrixInvertPureTransRotMatrix(CMatrix& target, CMatrix& transRotMatrix){
		target.setValues(transRotMatrix.m11,transRotMatrix.m21,transRotMatrix.m31,0,
						 transRotMatrix.m12,transRotMatrix.m22,transRotMatrix.m32,0,
						 transRotMatrix.m13,transRotMatrix.m23,transRotMatrix.m33,0,
						-transRotMatrix.m41*transRotMatrix.m11-transRotMatrix.m42*transRotMatrix.m12-transRotMatrix.m43*transRotMatrix.m13,-transRotMatrix.m41*transRotMatrix.m21-transRotMatrix.m42*transRotMatrix.m22-transRotMatrix.m43*transRotMatrix.m23,-transRotMatrix.m41*transRotMatrix.m31-transRotMatrix.m42*transRotMatrix.m32-transRotMatrix.m43*transRotMatrix.m33,1);
	}

	static void TransformFromWorldToLocale(CVector3D& target, CVector3D& source,CMatrix& pureTransRotMatrix){
		target.setValues(source.x*pureTransRotMatrix.m11+source.y*pureTransRotMatrix.m12+source.z*pureTransRotMatrix.m13 - pureTransRotMatrix.m41,source.x*pureTransRotMatrix.m21+source.y*pureTransRotMatrix.m22+source.z*pureTransRotMatrix.m23 - pureTransRotMatrix.m42,source.z*pureTransRotMatrix.m31+source.y*pureTransRotMatrix.m32+source.z*pureTransRotMatrix.m33 - pureTransRotMatrix.m43);
	}

	static void RandomInitialize(void){
		time_t t;
		time(&t);
		srand(t);
	}
	
	static float RandomFloat(float minValue, float maxValue){
		float result = minValue + (maxValue-minValue)*((float)rand()/(float)(RAND_MAX));
		return result;
	}

	static int RandomInteger(int minValue, int maxValue){
		return (int)(RandomFloat((float)minValue,(float)maxValue)+0.5f);
	}



	const static float PI;
protected:

protected:

};

