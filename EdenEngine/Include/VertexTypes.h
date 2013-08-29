#pragma once
#include "Vector2D.h"
#include "Vector3D.h"
#include "Vector4D.h"

struct VERTEX_COLOR{
	CVector3D position;
	CVector4D color;
};

struct VERTEX_TEXTURE{
	CVector3D position;
	CVector2D texCoordinates;
};