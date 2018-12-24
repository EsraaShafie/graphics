#pragma once
#include <gl/glew.h>
#include <gl/glfw3.h>
#include <glm/glm.hpp>
class Light
{
	GLuint AmbientLightID;
	GLuint LightPositionID;
	GLuint EyePositionID;
	glm::vec3 ambientLight;
	glm::vec3 lightPosition;

public:
	Light();
	~Light();

private:

};

Light::Light()
{
}

Light::~Light()
{
}
