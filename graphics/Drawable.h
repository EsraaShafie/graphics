#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "EulerCamera/EulerCamera.h"

#ifndef DRAWABLE_CLASS
#define DRAWABLE_CLASS

using namespace glm;

class Drawable
{
protected:
	EulerCamera* BoundCamera;
	vec3 ForwardVector;
	mediump_mat4 ModelMatrix;
	mediump_vec3 postion, rotation, scale, color;
public:
	Drawable();
	void Translate(const vec3& distance);
	void Rotate(const vec3& angles);
	void Scale(const vec3& scale);
	void SetColor(const vec3& color);
	void SetPosition(const vec3& Position);
	const vec3& GetPosition();
	const vec3& GetRotation();
	const vec3& GetScale();
	const vec3& GetColor();
	const mat4& GetModelMatrix();
	void SetModelMatrix(const mat4&);
	virtual void Draw(const mat4& ProjectionMatrix, const mat4& ViewMatrix,
					  const vec3& EyePos, const vec3& LightPos, const vec3& Ambient) = 0;
};

#endif