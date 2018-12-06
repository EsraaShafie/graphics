#include <iostream>
#include <gl/glew.h>
#include <gl/glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "shader.hpp"
#include "Drawable.h"
#include "RectangleShape.h"
#include "FPCamera.h"

namespace Engine
{
	GLFWwindow* CreateWindow(int width, int height, const char* title);
	void Draw(const Drawable& obj);
	void ClearWindow();
	void SetClearColor(const glm::vec3& color);
	FPCamera& GetCamera();
}