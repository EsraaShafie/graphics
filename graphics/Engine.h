#include <iostream>
#include <gl/glew.h>
#include <gl/glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "shader.hpp"
#include "Drawable.h"
#include "RectangleShape.h"
#include "EulerCamera\EulerCamera.h"
#include "CubeShape.h"
#include "Keyboard.h"
#include "Hero.h"
#include "Enemy.h"
#include "Tree.h"

namespace Engine
{
	GLFWwindow* CreateWindow(int width, int height, const char* title);
	void Draw(Drawable& obj);
	void ClearWindow();
	void SetClearColor(const glm::vec3& color);
	EulerCamera& GetCamera();
}