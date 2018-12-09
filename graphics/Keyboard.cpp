#include "Keyboard.h"
#include <map>

std::map<int, bool> KeyMap;
glm::vec2 LastMousePos;
GLFWwindow* CurrentWindow;
void Input::KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	KeyMap[key] = (action != GLFW_RELEASE);
}
bool Input::IsKeyPressed(int key)
{
	return KeyMap[key];
}
const glm::vec2& Input::GetMouseDelta()
{
	glm::vec2 Pos = LastMousePos;
	double x, y;
	glfwGetCursorPos(CurrentWindow, &x, &y);
	LastMousePos = glm::vec2(x, y);
	return LastMousePos - Pos;
}
void Input::SetWindow(GLFWwindow* window)
{
	CurrentWindow = window;
}