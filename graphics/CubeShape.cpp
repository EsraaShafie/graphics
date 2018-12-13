#include "CubeShape.h"
#include "shader.hpp"


using namespace glm;

GLuint CubeShape::programID = 0;

CubeShape::CubeShape() : Drawable()
{
	mtexture.resize(6);
	for (int i = 0; i < 6; i++)
	{
		mtexture[i] = nullptr;
	}
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	if (programID == 0)
	{
		programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");
	}
	mvpID = glGetUniformLocation(programID, "MVP");
	colorID = glGetUniformLocation(programID, "Color");
}
void CubeShape::SetTexture(const char** TextureName)
{
	for (auto i : mtexture)
	{
		if (i != nullptr)
		{
			delete i;
		}
	}
	mtexture.clear();
	for (int i = 0; i < 6; i++)
	{
		Texture* t = new Texture(TextureName[i], 0);
		mtexture.push_back(t);
	}
}
void CubeShape::Draw(const mat4& ProjectionMatrix, const mat4& ViewMatrix)
{
	glUseProgram(programID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float) * 3));
	mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
	glUniformMatrix4fv(mvpID, 1, GL_FALSE, &MVP[0][0]);
	glUniform3fv(colorID, 1, &color[0]);
	for (int i = 0; i < 24; i += 4)
	{
		if (mtexture[i / 4] != nullptr)
		{
			mtexture[i / 4]->Bind();
		}
		glDrawArrays(GL_TRIANGLE_FAN, i, 4);
	}
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(2);

}
