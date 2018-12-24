#pragma once
#include "CubeShape.h"

class Enemy : public Drawable
{
private:
	CubeShape  Body;
public:
	Enemy();
	void Draw(const mat4& ProjectionMatrix, const mat4& ViewMatrix,
		const vec3& EyePos, const vec3& LightPos, const vec3& Ambient);
	CubeShape& GetBody();
};