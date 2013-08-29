#pragma once
#include "UsefulMath.h"
class CCamera{
public:
	CCamera(CVector3D& position, float alpha, float beta);

	void setAngle(float alpha, float beta);
	
	void setPosition(CVector3D& position);

	void move(CVector3D& direction);

	float getX(void){
		return position.x;
	}

	float getY(void){
		return position.y;
	}

	float getZ(void){
		return position.z;
	}

	float getAlpha(void){
		return alpha;
	}
	float getBeta(void){
		return beta;
	}

	void rotate(float dAlpha, float dBeta);

	void moveForwards(float amount);
	void moveSidewards(float amount);
	void moveVertical(float amount);
	public:

	CMatrix* getMatrix(void){
		return &matrix;
	}

	

protected:
	void updateTranslation(void);
protected:
	CMatrix matrix;
	float alpha, beta;
	CVector3D position;
	float maxAngle,minAngle;
};