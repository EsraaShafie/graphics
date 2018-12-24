#pragma once
#include "CubeShape.h"

class Tree : public Drawable
{
private:
	CubeShape Treee, Root;
public:
	Tree();
	void Draw(const mat4& ProjectionMatrix, const mat4& ViewMatrix,
		const vec3& EyePos, const vec3& LightPos, const vec3& Ambient);
	CubeShape& GetTree();
	CubeShape& GetRoot();
};