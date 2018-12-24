#include "Engine.h"

Tree::Tree()
{

	const char* RootTextures[] =
	{
	"bark__1__seamless__mp.jpg",	
	"bark__1__seamless__mp.jpg",
	"bark__1__seamless__mp.jpg",
	"bark__1__seamless__mp.jpg",
	"bark__1__seamless__mp.jpg",
	"bark__1__seamless__mp.jpg",

	};
	const char* GreenTextures[] =
	{
		"grass-texture_1000x.jpeg",
		"grass-texture_1000x.jpeg",
		"grass-texture_1000x.jpeg",
		"grass-texture_1000x.jpeg",
		"grass-texture_1000x.jpeg",
		"grass-texture_1000x.jpeg",

	};

	Root.SetTexture(RootTextures);
	Treee.SetTexture(GreenTextures);
	//Body.Scale(vec3(2.0f, 2.8f, 1.6f));
	Root.Scale(vec3(1.0f, 3.0f, 1.0f));
	//Body.Translate(vec3(0.0f, 0.12f, 0.0f));
	Root.Translate(vec3(0.0f,0.8f,5.0f));
}
void Tree::Draw(const mat4& ProjectionMatrix, const mat4& ViewMatrix,
	const vec3& EyePos, const vec3& LightPos, const vec3& Ambient)
{
	CubeShape* Parts[] = { &Treee, &Root };
	for (auto i : Parts)
	{
		mat4 m = i->GetModelMatrix();
		i->SetModelMatrix(ModelMatrix * m);
		Engine::Draw(*i);
		i->SetModelMatrix(m);//model matrix relative to the hero 
	}
}

CubeShape & Tree::GetRoot()
{
	return Root;
}
CubeShape & Tree::GetTree()
{
	return Treee;
}