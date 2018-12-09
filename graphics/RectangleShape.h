#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "Drawable.h"
#include <GL/glew.h>
#include "texture.h"
using namespace glm;


class RectangleShape : public Drawable
{
private:
	float verts[20] =
	{
		-0.4f, +0.4f, +0.0f,
		-1.0f, +1.0f,//uv
		-0.4f, -0.4f, +0.0f,
		-1.0f, -1.0f,
		+0.4f, -0.4f, +0.0f,
		+1.0f, -1.0f,
		+0.4f, +0.4f, +0.0f,
		+1.0f, +1.0f
	};
	GLuint bufferID, programID, mvpID, colorID;
	Texture* mtexture;
public:
	RectangleShape();
	void Draw(const mat4& ProjectionMatrix, const mat4& ViewMatrix) const;
	void SetTexture(const char* TextureName);
	~RectangleShape();
};