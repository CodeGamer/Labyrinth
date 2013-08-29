#pragma once
#include <cmath>


class CVector4D{
public:
	union{
		struct{
			float x,y,z,w;
		};
		float components[4];
	};

	CVector4D():x(0),y(0),z(0),w(0){
	
	}
	CVector4D(float x, float y, float z, float w):x(x),y(y),z(z),w(w){
	
	}

	CVector4D(CVector4D& vector):x(vector.x),y(vector.y),z(vector.z),w(vector.w){
	
	}
	
	
	float getSquaredLength(void){
		return x*x + y*y + z*z + w*w;
	}

	float getLength(void){
		return sqrtf(getSquaredLength());
	}

	void normalize(void){
		if(!((x == y)&&(y==z) && (z == w) && (w == 0)))
			divide(getLength());
	}
	void setLength(float length){
		normalize();
		multiply(length);
	}
	void flip(void){
		x = -x;
		y = -y;
		z = -z;
		w = -w;
	}

	void equate(CVector4D& vector){
		x = vector.x;
		y = vector.y;
		z = vector.z;
		w = vector.w;
	}

	void setValues(float x, float y, float z, float w){
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	CVector4D& operator = (CVector4D& vector){
		equate(vector);
		return *this;
	}

	void add(CVector4D& vector){
		x += vector.x;
		y += vector.y;
		z += vector.z;
		w += vector.w;
	}

	void operator += (CVector4D& vector){
		add(vector);
	}

	void subtract(CVector4D& vector){
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		w -= vector.w;
	}

	void operator -= (CVector4D& vector){
		subtract(vector);
	}

	void multiply(float scalar){
		x *= scalar;
		y *= scalar;
		z *= scalar;
		w *= scalar;
	}

	void operator *= (float scalar){
		multiply(scalar);
	}

	void divide(float scalar){
		x /= scalar;
		y /= scalar;
		z /= scalar;
		w /= scalar;
	}
	void operator /= (float scalar){
		divide(scalar);
	}
	
	float dotProduct(CVector4D& vector){
		return x*vector.x + y*vector.y + z*vector.z + w*vector.w;
	}
	
	bool isNullVector(void){
		return (x == 0)&&(y == 0)&&(z==0)&&(w==0);
	}

	void addScaled(CVector4D& vector, float s){
		x += vector.x*s;
		y += vector.y*s;
		z += vector.z*s;
		w+= vector.w*s;
	}

	float operator * (CVector4D& vector){
		return dotProduct(vector);
	}
	float operator() (unsigned int index){
		return components[index];
	}

	bool equals(CVector4D& vector){
		return (x == vector.x) && (y == vector.y) && (z == vector.z) && (w == vector.w);
	}

	bool operator == (CVector4D& vector){
		return equals(vector);
	}

	bool operator != (CVector4D& vector){
		return !equals(vector);
	}

};