#pragma once
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "Drawable.h"
#include <GL/glew.h>
#include "texture.h"
#include <vector>

using namespace glm;


class CubeShape : public Drawable
{ 
private:
	
	float verts[192] =
	{
		//front
		-1.0f, -1.0f, 1.0f, //Vertex 0
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f,//uv
		+1.0f, -1.0f, 1.0f,  //v1
		0.0f, 0.0f, 1.0f,
		+1.0f, 0.0f,
		+1.0f, +1.0f, 1.0f,   //v3
		0.0f, 0.0f, 1.0f,
		+1.0f, +1.0f,
		-1.0f, +1.0f, 1.0f,  //v2
		0.0f, 0.0f, 1.0f,
		 0.0f, +1.0f,
		//right
		1.0f, -1.0f, 1.0f,  //...
		1.0f, 0.0f, 0.0f,
		0.0f, 0.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		+1.0f, 0.0f,
		1.0f, 1.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		+1.0f, +1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, +1.0f,
		//back
		1.0f, -1.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f,
		-1.0f, -1.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		+1.0f, 0.0f,
		-1.0f, 1.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		+1.0f, +1.0f,
		1.0f, 1.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, +1.0f,
		//left
		-1.0f, -1.0f, -1.0f,
		-1.0f, 0.0f, 0.0f,
		+1.0f, 0.0f,
		-1.0f, -1.0f, 1.0f,
		-1.0f, 0.0f, 0.0f,
		0.0f, 0.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 0.0f, 0.0f,
		0.0f, +1.0f,
		-1.0f, 1.0f, -1.0f,
		-1.0f, 0.0f, 0.0f,
		+1.0f, +1.0f,
		//bottom
		-1.0f, -1.0f, -1.0f,
		0.0f, -1.0f, 0.0f,
		+1.0f, 0.0f,
		1.0f, -1.0f, -1.0f,
		0.0f, -1.0f, 0.0f,
		+1.0f, +1.0f,
		1.0f, -1.0f, 1.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, +1.0f,
		-1.0f, -1.0f, 1.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, 0.0f,
		//top
		-1.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, +1.0f,
		1.0f, 1.0f, -1.0f,
		0.0f, 1.0f, 0.0f,
		+1.0f, +1.0f,
		-1.0f, 1.0f, -1.0f,
		0.0f, 1.0f, 0.0f,
		+1.0f, 0.0f,
	};
	GLuint VertexArrayID, bufferID, mvpID, colorID, modelMatrixID, eyeID, lightID, ambientID;
	std::vector<Texture*> mtexture;
	static GLuint programID;
public:
	CubeShape();
    void Draw(const mat4& ProjectionMatrix, const mat4& ViewMatrix,
		      const vec3& EyePos, const vec3& LightPos, const vec3& Ambient);
	void SetTexture(const char** TextureName);
};
