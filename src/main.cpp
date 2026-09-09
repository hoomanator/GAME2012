#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include<iostream>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


int main(void)
{
	constexpr int SCREEN_WIDTH = 1280;
	constexpr int SCREEN_HEIGHT = 720;

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello OpenGL", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Load OpenGL 4.6*/
	gladLoadGL();

	glfwSetKeyCallback(window, key_callback);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	const char* name = glfwGetKeyName(key, scancode);
	if (action == GLFW_PRESS)
	{
		printf("%s\n", name);
	}

	//if (key == GLFW_KEY_E && action == GLFW_PRESS)
	//    activate_airship();
}