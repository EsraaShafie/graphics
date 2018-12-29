#include "Engine.h"

GLFWwindow* MainWindow;

bool IsCollied(Drawable &Object_A, Drawable &Object_B)
{
	//Get Position Vector of The First Object..
	glm::vec3 Position_A = Object_A.GetPosition();

	//Get Scale Vector of The First Object..
	glm::vec3 Scale_A = Object_A.GetScale();

	//Get Position Vector of The Second Object..
	glm::vec3 Position_B = Object_B.GetPosition();

	//Get Scale Vector of The Second Object..
	glm::vec3 Scale_B = Object_B.GetScale();


	Scale_A.x *= 0.5;
	Scale_A.y *= 0.5;
	Scale_A.z *= 0.5;
	//Scale_B.x *= 3.0f;
	//Scale_B.y *= 3.0f;
	//Scale_B.z *= 3.0f;

    //Apply AABB Algorithm (Axis Aligned Bounding Box)..
    return (   abs(Position_A.x-Position_B.x)<Scale_A.x+Scale_B.x
            && abs(Position_A.y-Position_B.y)<Scale_A.y+Scale_B.y 
            && abs(Position_A.z-Position_B.z)<Scale_A.z+Scale_B.z );
}
int main()
{
	MainWindow = Engine::CreateWindow(1280, 720, "Minecraft");
	Engine::SetClearColor(vec3(0.4667f, 0.909f, 0.976f));
	std::vector<CubeShape*> Land;
	LandGenerator::StartGeneration(vec3(0.0f, 0.0f, 0.0f));
	Hero hero;
	Tree t;
	Enemy e;
	e.Translate(vec3(5.0f, 2.0f, 0.0f));
	t.Translate(vec3(0.0f, 2.0f, 5.0f));

	vec3 CamLastPos = Engine::GetCamera().GetEyePosition();
	glfwSetInputMode(MainWindow, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	float direction = 1.0f;
	do
	{
		glfwPollEvents();
		//Logic
		if(e.GetPosition().x >= 5.0f || e.GetPosition().x <= -5.0f)
		{
			direction *= -1;
		}
		e.Translate(vec3(0.1f * direction, 0.0f, 0.0f));

		glm::vec2 delta = Input::GetMouseDelta();
		Engine::GetCamera().Pitch(-delta.y * 0.005f);
		Engine::GetCamera().Yaw(-delta.x * 0.005f);
		Engine::GetCamera().UpdateViewMatrix();
	    hero.Rotate(vec3(0.0f, -delta.x * 0.28656f, 0.0f));

		vec3 HeroLastPos = hero.GetPosition();

		if (Input::IsKeyPressed(GLFW_KEY_UP))
		{
			hero.Translate(vec3(0.0f, 0.0f, 0.75f));
			if(IsCollied(hero, t) || IsCollied(hero, e))
			{
				hero.Translate(vec3(0.0f, 0.0f, -0.75f));
			}
		}
		if (Input::IsKeyPressed(GLFW_KEY_DOWN))
		{
			hero.Translate(vec3(0.0f, 0.0f, -0.75f));
			if(IsCollied(hero, t) || IsCollied(hero, e))
			{
				hero.Translate(vec3(0.0f, 0.0f, 0.75f));
			}
		}
		if (Input::IsKeyPressed(GLFW_KEY_RIGHT))
		{
			hero.Translate(vec3(-0.75f, 0.0f, 0.0f));
			if(IsCollied(hero, t) || IsCollied(hero, e))
			{
				hero.Translate(vec3(0.75f, 0.0f, 0.0f));
			}
		}
		if (Input::IsKeyPressed(GLFW_KEY_LEFT))
		{
			hero.Translate(vec3(0.75f, 0.0f, 0.0f));
			if(IsCollied(hero, t) || IsCollied(hero, e))
			{
				hero.Translate(vec3(-0.75f, 0.0f, 0.0f));
			}
		}
		if(IsCollied(hero, e))
		{
			hero.Translate(vec3(0.0f, 0.0f, -1.0f));
		}

		float temp = Engine::GetCamera().mAngleY;
		//Engine::GetCamera().mAngleY = 0;
		//Engine::GetCamera().UpdateViewMatrix();
		vec3 v = vec3(hero.GetModelMatrix() * vec4(hero.GetHead().GetPosition(), 1));
		Engine::GetCamera().SetEyePosition(v + 0.5f * Engine::GetCamera().mDirection);
		Engine::GetCamera().SetEyePosition(v - 2.0f * Engine::GetCamera().mDirection);

		Engine::GetCamera().mAngleY = temp;
		Engine::GetCamera().UpdateViewMatrix();

		if((int)Engine::GetCamera().GetEyePosition().x != (int)CamLastPos.x || 
		   (int)Engine::GetCamera().GetEyePosition().z != (int)CamLastPos.z)
		{
			CamLastPos = Engine::GetCamera().GetEyePosition();
			LandGenerator::UpdatePosition(CamLastPos);
		}
		//Rendering
		Engine::ClearWindow();
		Engine::Draw(hero);
		Engine::Draw(t);
		Engine::Draw(e);
		LandGenerator::FlushLand(Land);
		for(auto i : Land)
		{
			Engine::Draw(*i);
		}
		glfwSwapBuffers(MainWindow);
	} while (glfwWindowShouldClose(MainWindow) == 0);
	glfwSetInputMode(MainWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	LandGenerator::ClearLand();
	for(auto i : Land)
	{
		delete i;
	}
	glfwTerminate();
	return 0;
}