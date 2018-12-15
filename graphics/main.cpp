#include "Engine.h"

GLFWwindow* MainWindow;

int main()
{
	const char* sameface[6] = 
	{
		"grass-texture_1000x.jpeg",
		"grass-texture_1000x.jpeg",
		"grass-texture_1000x.jpeg",
		"grass-texture_1000x.jpeg",
		"grass-texture_1000x.jpeg",
		"grass-texture_1000x.jpeg"
	};
	MainWindow = Engine::CreateWindow(1280, 720, "Minecraft");
	//RectangleShape s1, s2;
	//s1.SetColor(vec3(1.0f, 1.0f, 0.5f));
	//s2.SetColor(vec3(0.5f, 1.0f, 1.0f));
	Engine::SetClearColor(vec3(1.0f, 0.5f, 1.0f));
	Engine::GetCamera().Walk(-4.0f);
	CubeShape s1[10];
	Hero hero;
	hero.Translate(vec3(0.0f, 0.0f, -1.0f));
	hero.Translate(vec3(0.0f, 1.5f, 0.0f));
	hero.Scale(vec3(0.3f, 0.3f, 0.3f));
	//s1.SetColor(glm::vec3(0.5f, 0.5f, 0.5f));
	//s1.Rotate(glm::vec3(45.0f, 0.0f, 0.0f));
	s1[0].Translate(vec3(0.0f, -1.0f, 0.0f));
	s1[0].SetTexture(sameface);
	for (int i = 1; i < 10; i++)
	{
		s1[i].SetTexture(sameface);
		s1[i].Translate(s1[i - 1].GetPosition() + glm::vec3(0.0f, 0.0f, 3.0f));
	}
	//s2.Translate(vec3(-0.4f, 0.0f, 0.0f));
     //s1.Scale(vec3(0.4f, 0.0f, 0.0f));
	//s2.Scale(vec3(-0.4f, 0.0f, 0.0f));;
	do
	{
		glfwPollEvents();
		//Logic
		glm::vec2 delta = Input::GetMouseDelta();
		//Engine::GetCamera().
		Engine::GetCamera().Pitch(-delta.y * 0.005f);
		Engine::GetCamera().Yaw(-delta.x * 0.005f);
		if (Input::IsKeyPressed(GLFW_KEY_SPACE))
		{
			Engine::GetCamera().Fly(0.05f);
		}
		if (Input::IsKeyPressed(GLFW_KEY_LEFT_SHIFT))
		{
			Engine::GetCamera().Fly(-0.05f);
		}
		if (Input::IsKeyPressed(GLFW_KEY_UP))
		{
			Engine::GetCamera().Walk(0.05f);
		}
		if (Input::IsKeyPressed(GLFW_KEY_DOWN))
		{
			Engine::GetCamera().Walk(-0.05f);
		}
		if (Input::IsKeyPressed(GLFW_KEY_RIGHT))
		{
			Engine::GetCamera().Strafe(0.05f);
		}
		if (Input::IsKeyPressed(GLFW_KEY_LEFT))
		{
			Engine::GetCamera().Strafe(-0.05f);
		}
		//s1.Translate(vec3(0.001f, 0.0f, 0.0f));
		//s2.Translate(vec3(-0.001f, 0.0f, 0.0f));
		//Rendering
		Engine::ClearWindow();
		for (int i = 0; i < 10; i++)
		{
			Engine::Draw(s1[i]);
		}
		
		Engine::Draw(hero);
		glfwSwapBuffers(MainWindow);
	} while (glfwWindowShouldClose(MainWindow) == 0);
	glfwTerminate();
	return 0;
}
