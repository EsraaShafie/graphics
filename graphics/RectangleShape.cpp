#include "RectangleShape.h"
#include "shader.hpp"

using namespace glm;

RectangleShape::RectangleShape() : Drawable()
{
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");
	mvpID = glGetUniformLocation(programID, "MVP");
	colorID = glGetUniformLocation(programID, "Color");
	mtexture = new Texture("uvtemplate.bmp", 0);
}
void RectangleShape::SetTexture(const char* TextureName)
{
	if (mtexture != nullptr)
	{
		delete mtexture;
	}
	mtexture = new Texture(TextureName, 0);
}
void RectangleShape::Draw(const mat4& ProjectionMatrix, const mat4& ViewMatrix) const
{
	glUseProgram(programID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float) * 3));
	mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
	glUniformMatrix4fv(mvpID, 1, GL_FALSE, &MVP[0][0]);
	glUniform3fv(colorID, 1, &color[0]);
	mtexture->Bind();
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(2);
}
RectangleShape::~RectangleShape()
{
	if (mtexture != nullptr)
	{
		delete mtexture;
	}
}