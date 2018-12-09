#include "Drawable.h"
#include "shader.hpp"

using namespace glm;

Drawable::Drawable()
{
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
	ModelMatrix *= rotate(angle.x, vec3(0.0f, 1.0f, 0.0f));
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