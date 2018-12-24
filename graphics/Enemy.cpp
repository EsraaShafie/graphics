#include "Engine.h"

Enemy::Enemy()
{
	
	const char* BodyTextures[] =
	{
		"Papai-noel-skin_front.png",
		"red.jpg",
		"Papai-noel-skin-back.png",
		"red.jpg",
		"red.jpg",
		"red.jpg"
    };
	
	
	Body.SetTexture(BodyTextures);
	
	//Body.Scale(vec3(2.0f, 2.8f, 1.6f));
	
	//Body.Translate(vec3(0.0f, 0.12f, 0.0f));
	
}
void Enemy::Draw(const mat4& ProjectionMatrix, const mat4& ViewMatrix,
	const vec3& EyePos, const vec3& LightPos, const vec3& Ambient)
{
	CubeShape* Part= { &Body };

		mat4 m = Part->GetModelMatrix();
		Part->SetModelMatrix(ModelMatrix * m);
		Engine::Draw(*Part);
		Part->SetModelMatrix(m);//model matrix relative to the hero 
	
}

CubeShape & Enemy::GetBody()
{
	return Body;
}
