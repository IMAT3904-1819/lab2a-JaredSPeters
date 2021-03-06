// Lab2.cpp : Defines the entry point for the console application.
//

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(int argc, char* argv[])
{
	//initialise window and let GLFW know that is should target version 4.3
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	GLFWwindow* window = glfwCreateWindow(800, 600,
		"OpeningAWindow", nullptr, nullptr);
		if (window == nullptr)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return -1;
		}

	//make new window our current context, then try to initialise GLAD
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialise GLAD" << std::endl;
		return -1;
	}

	//until we receive a message to close the program
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.09f, 0.66f, 0.99f, 1.0f);
		//Convert RGB value to OpenGL float (https://openglcolor.mpeters.me/)
		glClear(GL_COLOR_BUFFER_BIT);

		//swap buffers i.e draw to screen
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//cleanup
	glfwTerminate();
	return 0;
}


