#pragma once

class CMatrix{
public:
	union{
		struct{
			float m11,m12,m13,m14;
			float m21,m22,m23,m24;
			float m31,m32,m33,m34;
			float m41,m42,m43,m44;
		};
		float components[4][4];
	};

	CMatrix(void):
			m11(0),m12(0),m13(0),m14(0),
			m21(0),m22(0),m23(0),m24(0),
			m31(0),m32(0),m33(0),m34(0),
			m41(0),m42(0),m43(0),m44(0){};

	CMatrix(float m11,float m12,float m13,float m14,
			float m21,float m22, float m23, float m24,
			float m31, float m32, float m33,float m34,
			float m41, float m42, float m43,float m44):
			m11(m11),m12(m12),m13(m13),m14(m14),
			m21(m21),m22(m22),m23(m23),m24(m24),
			m31(m31),m32(m32),m33(m33),m34(m34),
			m41(m41),m42(m42),m43(m43),m44(m44){};

	CMatrix(CMatrix& matrix):
			m11(matrix.m11),m12(matrix.m12),m13(matrix.m13),m14(matrix.m14),
			m21(matrix.m21),m22(matrix.m22),m23(matrix.m23),m24(matrix.m24),
			m31(matrix.m31),m32(matrix.m32),m33(matrix.m33),m34(matrix.m34),
			m41(matrix.m41),m42(matrix.m42),m43(matrix.m43),m44(matrix.m44){};

	void transpose(void){
		setValues(m11,m21,m31,m41,
			      m12,m22,m32,m42,
				  m13,m23,m33,m43,
				  m14,m24,m34,m44);
	}

	void add(CMatrix& matrix){
		m11 += matrix.m11;m12 += matrix.m12;m13 += matrix.m13;m14 += matrix.m14;
		m21 += matrix.m21;m22 += matrix.m22;m23 += matrix.m23;m24 += matrix.m24;
		m31 += matrix.m31;m32 += matrix.m32;m33 += matrix.m33;m34 += matrix.m34;
		m41 += matrix.m41;m42 += matrix.m42;m43 += matrix.m43;m44 += matrix.m44;
	}
	void operator += (CMatrix& matrix){
		add(matrix);
	}

	void subtract(CMatrix& matrix){
		m11 -= matrix.m11;m12 -= matrix.m12;m13 -= matrix.m13;m14 -= matrix.m14;
		m21 -= matrix.m21;m22 -= matrix.m22;m23 -= matrix.m23;m24 -= matrix.m24;
		m31 -= matrix.m31;m32 -= matrix.m32;m33 -= matrix.m33;m34 -= matrix.m34;
		m41 -= matrix.m41;m42 -= matrix.m42;m43 -= matrix.m43;m44 -= matrix.m44;
	}

	void operator -= (CMatrix& matrix){
		subtract(matrix);
	}

	void multiply(CMatrix& matrix){
		setValues(
			m11*matrix.m11 + m12*matrix.m21 + m13*matrix.m31 + m14*matrix.m41,m11*matrix.m12 + m12*matrix.m22 + m13*matrix.m32 + m14*matrix.m42,m11*matrix.m13 + m12*matrix.m23 + m13*matrix.m33 + m14*matrix.m43,m11*matrix.m14 + m12*matrix.m24 + m13*matrix.m34 + m14*matrix.m44,
			m21*matrix.m11 + m22*matrix.m21 + m23*matrix.m31 + m24*matrix.m41,m21*matrix.m12 + m22*matrix.m22 + m23*matrix.m32 + m24*matrix.m42,m21*matrix.m13 + m22*matrix.m23 + m23*matrix.m33 + m24*matrix.m43,m21*matrix.m14 + m22*matrix.m24 + m23*matrix.m34 + m24*matrix.m44,
			m31*matrix.m11 + m32*matrix.m21 + m33*matrix.m31 + m34*matrix.m41,m31*matrix.m12 + m32*matrix.m22 + m33*matrix.m32 + m34*matrix.m42,m31*matrix.m13 + m32*matrix.m23 + m33*matrix.m33 + m34*matrix.m43, m31*matrix.m14 + m32*matrix.m24 + m33*matrix.m34 + m34*matrix.m44,
			m41*matrix.m11 + m42*matrix.m21 + m43*matrix.m31 + m44*matrix.m41,m41*matrix.m12 + m42*matrix.m22 + m43*matrix.m32 + m44*matrix.m42, m41*matrix.m13 + m42*matrix.m23 + m43*matrix.m33 + m44*matrix.m43, m41*matrix.m14 + m42*matrix.m24 + m43*matrix.m34 + m44*matrix.m44
		);
	}

	void operator *= (CMatrix& matrix){
		multiply(matrix);
	}

	void setValues(float m11,float m12,float m13,float m14,
				   float m21,float m22,float m23, float m24,
				   float m31, float m32, float m33,float m34,
				   float m41, float m42, float m43,float m44){
	this->m11=m11;this->m12=m12;this->m13=m13;this->m14=m14;
	this->m21=m21;this->m22=m22;this->m23=m23;this->m24=m24;
	this->m31=m31;this->m32=m32;this->m33=m33;this->m34=m34;
	this->m41=m41;this->m42=m42;this->m43=m43;this->m44=m44;
	}

	void equate(CMatrix& matrix){
		this->m11=matrix.m11;this->m12=matrix.m12;this->m13=matrix.m13;this->m14=matrix.m14;
		this->m21=matrix.m21;this->m22=matrix.m22;this->m23=matrix.m23;this->m24=matrix.m24;
		this->m31=matrix.m31;this->m32=matrix.m32;this->m33=matrix.m33;this->m34=matrix.m34;
		this->m41=matrix.m41;this->m42=matrix.m42;this->m43=matrix.m43;this->m44=matrix.m44;
	}

	CMatrix& operator = (CMatrix& matrix){
		equate(matrix);
		return *this;
	}

	bool operator == (CMatrix& matrix){
		return (m11 == matrix.m11)&&(m12 == matrix.m12)&&(m13 == matrix.m13)&&(m14 == matrix.m14)&&
			   (m21 == matrix.m21)&&(m22 == matrix.m22)&&(m23 == matrix.m23)&&(m24 == matrix.m24)&&
			   (m31 == matrix.m31)&&(m32 == matrix.m32)&&(m33 == matrix.m33)&&(m34 == matrix.m34)&&
			   (m41 == matrix.m41)&&(m42 == matrix.m42)&&(m43 == matrix.m43)&&(m44 == matrix.m44);
	}

	float operator () (unsigned int row, unsigned int column){
		return components[row][column];
	}

protected:

protected:

};