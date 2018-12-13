#include "Engine.h"

Hero::Hero()
{
	const char* FaceTextures[] =
	{
		"FaceFront.png",
		"FaceRight.jpg",
		"FaceBack.jpg",
		"FaceLeft.jpg",
		"FaceTop.jpg",
		"FaceTop.jpg"
	};
	const char* ArmTextures[] = 
	{
		"Arm.png",
		"Arm.png",
		"Arm.png",
		"Arm.png",
		"Arm.png",
		"Arm.png",
	};
	const char* BodyTextures[] = 
	{
		"BodyFront.png",
		"Body.png",
		"Body.png",
		"Body.png",
		"Body.png",
		"Body.png",
	};
	const char* LegLeftTextures[] = 
	{
		"LegLeft.png",
		"LegNormal.png",
		"LegNormal.png",
		"LegNormal.png",
		"LegNormal.png",
		"LegNormal.png",
	};
	Head.SetTexture(FaceTextures);
	LeftArm.SetTexture(ArmTextures);
	RightArm.SetTexture(ArmTextures);
	Body.SetTexture(BodyTextures);
	LeftLeg.SetTexture(LegLeftTextures);
	Head.Translate(vec3(0.0f, 3.0f, 0.0f));
	LeftArm.Scale(vec3(0.5f, 2.0f, 0.6f));
	RightArm.Scale(vec3(0.5f, 2.0f, 0.6f));
	LeftArm.Translate(vec3(-3.0f, 0.0f, 0.0f));
	Body.Scale(vec3(1.0f, 1.8f, 0.6f));
	RightArm.Translate(vec3(3.0f, 0.0f, 0.0f));
	Body.Translate(vec3(0.0f, 0.12f, 0.0f));
	LeftLeg.Scale(vec3(0.5f, 2.0f, 0.6f));
	RightLeg.Scale(vec3(0.5f, 2.0f, 0.6f));
	LeftLeg.Translate(vec3(-1.0f, -1.78f, 0.0f));
	RightLeg.Translate(vec3(1.0f, -1.78f, 0.0f));
}
void Hero::Draw(const mat4& ProjectionMatrix, const mat4& ViewMatrix)
{
	CubeShape* Parts[] = { &LeftArm, &RightArm, &Body, &Head, &LeftLeg, &RightLeg };
	for (auto i : Parts)
	{
		mat4 m = i->GetModelMatrix();
		i->SetModelMatrix(ModelMatrix * m);
		Engine::Draw(*i);
		i->SetModelMatrix(m);
	}
}
CubeShape & Hero::GetLeftArm()
{
	return LeftArm;
}
CubeShape & Hero::GetRightArm()
{
	return RightArm;
}
CubeShape & Hero::GetLeftLeg()
{
	return LeftLeg;
}
CubeShape & Hero::GetRightLeg()
{
	return RightLeg;
}
CubeShape & Hero::GetHead()
{
	return Head;
}
CubeShape & Hero::GetBody()
{
	return Body;
}
