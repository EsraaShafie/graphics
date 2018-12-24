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
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 3));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 6));
	if (programID == 0)
	{
		programID = LoadShaders("LightVertex.vertex", "LightFragment.fragment");
	}
	mvpID = glGetUniformLocation(programID, "MVP");
	modelMatrixID = glGetUniformLocation(programID, "ModelMatrix");
	colorID = glGetUniformLocation(programID, "Color");
	lightID = glGetUniformLocation(programID, "LightPos");
	eyeID = glGetUniformLocation(programID, "EyePos");
	ambientID = glGetUniformLocation(programID, "ambient");
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
void CubeShape::Draw(const mat4& ProjectionMatrix, const mat4& ViewMatrix,
					 const vec3& EyePos, const vec3& LightPos, const vec3& Ambient)
{
	glBindVertexArray(VertexArrayID);
	glUseProgram(programID);
	mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
	glUniformMatrix4fv(modelMatrixID, 1, GL_FALSE, &ModelMatrix[0][0]);
	glUniformMatrix4fv(mvpID, 1, GL_FALSE, &MVP[0][0]);
	glUniform3fv(colorID, 1, &color[0]);
	glUniform3fv(lightID, 1, &LightPos[0]);
	glUniform3fv(eyeID, 1, &EyePos[0]);
	glUniform3fv(ambientID, 1, &Ambient[0]);
	for (int i = 0; i < 24; i += 4)
	{
		if (mtexture[i / 4] != nullptr)
		{
			mtexture[i / 4]->Bind();
		}
		glDrawArrays(GL_TRIANGLE_FAN, i, 4);
	}
}
