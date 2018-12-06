#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "Drawable.h"
#include <GL/glew.h>

using namespace glm;

class RectangleShape : public Drawable
{
private:
	float verts[12] =
	{
		-0.4f, +0.4f, +0.0f,
		-0.4f, -0.4f, +0.0f,
		+0.4f, -0.4f, +0.0f,
		+0.4f, +0.4f, +0.0f,
	};
	GLuint bufferID, programID, mvpID, colorID;
public:
	RectangleShape();
	void Draw(const mat4& ProjectionMatrix, const mat4& ViewMatrix) const;
};