#pragma once
#include "CubeShape.h"

class Hero : public Drawable
{
private:
	CubeShape LeftArm, RightArm, LeftLeg, RightLeg, Head, Body;
public:
	Hero();
	void Draw(const mat4& ProjectionMatrix, const mat4& ViewMatrix,
		      const vec3& EyePos, const vec3& LightPos, const vec3& Ambient);
	CubeShape& GetLeftArm();
	CubeShape& GetRightArm();
	CubeShape& GetLeftLeg();
	CubeShape& GetRightLeg();
	CubeShape& GetHead();
	CubeShape& GetBody();
};