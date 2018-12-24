#include "Drawable.h"
#include "shader.hpp"

#define PI 3.14159265359f

using namespace glm;

Drawable::Drawable()
{
	this->BoundCamera = nullptr;
	this->color = vec3(1.0f, 1.0f, 1.0f); //by default color is white
	this->postion = vec3(0.0f, 0.0f, 0.0f);
	this->scale = vec3(1.0f);
	this->rotation = vec3(0.0f, 0.0f, 0.0f);
	this->ModelMatrix = mat4(1.0f);
}
void Drawable::Translate(const vec3& distance)
{
	ModelMatrix *= translate(distance);
	postion += distance;
}
void Drawable::Rotate(const vec3& angle)
{
	ModelMatrix[3][0] = ModelMatrix[3][1] = ModelMatrix[3][2] = 0;
	ModelMatrix *= rotate(angle.y, vec3(0.0f, 1.0f, 0.0f));
	ModelMatrix *= rotate(angle.z, vec3(0.0f, 0.0f, 1.0f));
	ModelMatrix *= rotate(angle.x, vec3(1.0f, 0.0f, 0.0f));
	ModelMatrix[3].x = postion.x;
	ModelMatrix[3].y = postion.y;
	ModelMatrix[3].z = postion.z;
	rotation += angle;
}
void Drawable::Scale(const vec3& scale)
{
	ModelMatrix *= glm::scale(scale);
	this->scale += scale;
}
void Drawable::SetColor(const vec3& color)
{
	this->color = color;
}
const vec3& Drawable::GetPosition()
{
	return postion;
}
const vec3& Drawable::GetRotation()
{
	return rotation;
}
const vec3& Drawable::GetScale()
{
	return scale;
}
const vec3& Drawable::GetColor()
{
	return color;

}
const mat4& Drawable::GetModelMatrix()
{
	return ModelMatrix;
}
void Drawable::SetModelMatrix(const mat4& m)
{
	ModelMatrix = m;
}
