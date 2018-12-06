#include "Engine.h"

GLFWwindow* MainWindow;

int main()
{
	MainWindow = Engine::CreateWindow(800, 600, "Minecraft");
	RectangleShape s1, s2;
	s1.SetColor(vec3(1.0f, 1.0f, 0.5f));
	s2.SetColor(vec3(0.5f, 1.0f, 1.0f));
	Engine::SetClearColor(vec3(1.0f, 0.5f, 1.0f));
	//Engine::GetCamera().
	do
	{
		glfwPollEvents();
		//Logic
		s1.Translate(vec3(0.001f, 0.0f, 0.0f));
		s2.Translate(vec3(-0.001f, 0.0f, 0.0f));
		//Rendering
		Engine::ClearWindow();
		Engine::Draw(s1);
		Engine::Draw(s2);
		glfwSwapBuffers(MainWindow);
	} while (glfwWindowShouldClose(MainWindow) == 0);
	glfwTerminate();
	return 0;
}
