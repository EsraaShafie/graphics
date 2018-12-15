#include "Engine.h"

EulerCamera Camera;
bool isCameraModifed = true;
bool isGLFWInitialized = false, isGLEWInitialized = false;

GLFWwindow* Engine::CreateWindow(int width, int height, const char* title)
{
	glewExperimental = true;
	if (!isGLFWInitialized)
	{
		isGLFWInitialized = true;
		glfwInit();
	}
	Camera.Walk(-2.0f);
	Camera.SetPerspectiveProjection(75.0f, (float)width / height, 0.01f, 100.0f);
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(window);
	Input::SetWindow(window);
	if (!isGLEWInitialized)
	{
		isGLEWInitialized = true;
		glewInit();
	}
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS); 
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glfwSetKeyCallback(window, &Input::KeyCallBack);
	//glfwSetMouseButtonCallback(window, &MouseClicked);
	return window;
}
void Engine::SetClearColor(const glm::vec3& color)
{
	glClearColor(color.x, color.y, color.z, 1);
}
void Engine::ClearWindow()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
EulerCamera& Engine::GetCamera()
{
	isCameraModifed = true;
	return Camera;
}
void Engine::Draw(Drawable& obj)
{
	if (isCameraModifed)
	{
		Camera.UpdateViewMatrix();
		isCameraModifed = false;
	}
	obj.Draw(Camera.GetProjectionMatrix(), Camera.GetViewMatrix());
}