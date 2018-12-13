#include "Engine.h"

Hero::Hero()
{
	const char* FaceTextures[] =
	{
		"FaceFront.png",
		"FaceRight.png",
		"FaceBack.jpg",
		"FaceLeft.jpg",
		"FaceTop.jpg",
		"FaceTop.jpg"
	};
	Head.SetTexture(FaceTextures);
	Head.Translate(vec3(0.0f, 3.0f, 0.0f));
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