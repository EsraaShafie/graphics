#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

#ifndef DRAWABLE_CLASS
#define DRAWABLE_CLASS

using namespace glm;

class Drawable
{
protected:
	mediump_mat4 ModelMatrix;
	mediump_vec3 postion, rotation, scale, color;
public:
	Drawable();
	void Translate(const vec3& distance);
	void Rotate(const vec3& angles);
	void Scale(const vec3& scale);
	void SetColor(const vec3& color);
	const vec3& GetPosition();
	const vec3& GetRotation();
	const vec3& GetScale();
	const vec3& GetColor();
	virtual void Draw(const mat4& ProjectionMatrix, const mat4& ViewMatrix) const = 0;
};

#endif