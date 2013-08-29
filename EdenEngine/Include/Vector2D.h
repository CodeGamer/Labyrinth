#pragma once
#include <cmath>


class CVector2D{
public:
	union{
		struct{
			float x,y;
		};
		float components[2];
	};

	CVector2D():x(0),y(0){
	
	}
	CVector2D(float x, float y):x(x),y(y){
	
	}

	CVector2D(CVector2D& vector):x(vector.x),y(vector.y){
	
	}
	
	
	float getSquaredLength(void){
		return x*x + y*y;
	}

	float getLength(void){
		return sqrtf(getSquaredLength());
	}

	void normalize(void){
		if(!((x == y)&& (y == 0)))
			divide(getLength());
	}
	void setLength(float length){
		normalize();
		multiply(length);
	}
	void flip(void){
		x = -x;
		y = -y;
	}

	void equate(CVector2D& vector){
		x = vector.x;
		y = vector.y;
	}
	
	CVector2D& operator = (CVector2D& vector){
		equate(vector);
		return *this;
	}

	void setValues(float x, float y){
		this->x = x;
		this->y = y;
	}



	void add(CVector2D& vector){
		x += vector.x;
		y += vector.y;
	}

	void operator += (CVector2D& vector){
		add(vector);
	}

	void subtract(CVector2D& vector){
		x -= vector.x;
		y -= vector.y;
	}

	void operator -= (CVector2D& vector){
		subtract(vector);
	}

	void multiply(float scalar){
		x *= scalar;
		y *= scalar;
	}

	void operator *= (float scalar){
		multiply(scalar);
	}

	void divide(float scalar){
		x /= scalar;
		y /= scalar;
	}
	void operator /= (float scalar){
		divide(scalar);
	}

	bool equals(CVector2D& vector){
		return (x == vector.x) && (y == vector.y);
	}

	bool isNullVector(void){
		return (x == 0)&&(y == 0);
	}

	void addScaled(CVector2D& vector, float s){
		x += vector.x*s;
		y += vector.y*s;
	}

	bool operator == (CVector2D& vector){
		return equals(vector);
	}

	bool operator != (CVector2D& vector){
		return !equals(vector);
	}

	float dotProduct(CVector2D& vector){
		return x*vector.x + y*vector.y;
	}
	
	float operator * (CVector2D& vector){
		return dotProduct(vector);
	}
	float operator() (unsigned int index){
		return components[index];
	}

};

