#pragma once
#include <cmath>


class CVector3D{
public:
	union{
		struct{
			float x,y,z;
		};
		float components[3];
	};

	CVector3D():x(0),y(0),z(0){
	
	}
	CVector3D(float x, float y, float z):x(x),y(y),z(z){
	
	}

	CVector3D(CVector3D& vector):x(vector.x),y(vector.y),z(vector.z){
	
	}
	
	
	float getSquaredLength(void){
		return x*x + y*y + z*z;
	}

	float getLength(void){
		return sqrtf(getSquaredLength());
	}

	void normalize(void){
		if(!((x == y)&&(y==z) && (z == 0)))
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
	}

	void equate(CVector3D& vector){
		x = vector.x;
		y = vector.y;
		z = vector.z;
	}

	void setValues(float x, float y, float z){
		this->x = x;
		this->y = y;
		this->z = z;
	}

	CVector3D& operator = (CVector3D& vector){
		equate(vector);
		return *this;
	}

	void add(CVector3D& vector){
		x += vector.x;
		y += vector.y;
		z += vector.z;
	}

	void operator += (CVector3D& vector){
		add(vector);
	}

	void subtract(CVector3D& vector){
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
	}

	void operator -= (CVector3D& vector){
		subtract(vector);
	}

	void multiply(float scalar){
		x *= scalar;
		y *= scalar;
		z *= scalar;
	}

	void operator *= (float scalar){
		multiply(scalar);
	}

	void divide(float scalar){
		x /= scalar;
		y /= scalar;
		z /= scalar;
	}
	void operator /= (float scalar){
		divide(scalar);
	}
	
	bool equals(CVector3D& vector){
		return (x == vector.x) && (y == vector.y) && (z == vector.z);
	}

	bool isNullVector(void){
		return (x == 0)&&(y == 0)&&(z==0);
	}

	void addScaled(CVector3D& vector, float s){
		x += vector.x*s;
		y += vector.y*s;
		z += vector.z*s;
	}

	bool operator == (CVector3D& vector){
		return equals(vector);
	}

	bool operator != (CVector3D& vector){
		return !equals(vector);
	}

	float dotProduct(CVector3D& vector){
		return x*vector.x + y*vector.y + z*vector.z;
	}
	
	float operator * (CVector3D& vector){
		return dotProduct(vector);
	}
	float operator() (unsigned int index){
		return components[index];
	}

};

