OpenGL

How to set up OpenGL with GLFW and Glad
Create an empty c++ project. Make sure the project and solution files are in the same folder
create three folders: inc, src, lib folders
Download GLFW binaries: https://www.glfw.org/download.html
We use static library - copy glfw3.lib under lib folder
Copy the entire GLFW folder under include to include folder
Project Properties C++ —> General —> Additional Include Dependencies: ./inc    (make sure you put it for “all configuration”)
Project Properties C++ —> Linker—>General —> Additional libraries: ./lib   (make sure you put it for “all configuration”)
Linker —> Input —> Additional dependencies glfw3.lib

Download Glad
https://glad.dav1d.de/

Use api/gl Version 4.6
Use “Core” profile
And hit generate

Unzip the glad.zip
Copy glad.c to your src folder
Copy glad and KHR folders under inc folder.


Go to https://www.glfw.org/documentation.html

Notice that I am adding glad.h otherwise the program assumes the older version if OpenGL from 90s not OpenGL 4.6!


#include "glad/glad.h"
#include "GLFW/glfw3.h"


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    //make sure you add this	
    gloadLoadGL();	

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}


2. Make  a different resolution

constexpr int SCREEN_WIDTH = 1280;

constexpr int SCREEN_HEIGHT = 720;

window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

3. Add glclearcolor to change the background
while (!glfwWindowShouldClose(window))
    {
        /* Render here */
	glClearColor(0.22f, 049f, 0.17f,1.0f)
        glClear(GL_COLOR_BUFFER_BIT);

1. From the main menu, git. -> create git repository
2. Create a push (make the private unboxed if you want to make it public)
3. Get the Github.com to see if your application is there
4. Download it, and run it to make sure everything is working

4. Try the input guide. https://www.glfw.org/docs/latest/input_guide.html

Key input
If you wish to be notified when a physical key is pressed or released or when it repeats, set a key callback.
glfwSetKeyCallback(window, key_callback);
The callback function receives the keyboard key, platform-specific scancode, key action and modifier bits.
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
        activate_airship();
}


Put callback function at the bottom of the program and declare the signature at the top of the program

#include <iostream>

make sure you have this after the glloadglad
glfwSetKeyCallback(window, key_callback);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    const char* name = glfwGetKeyName (key,scancode);
    printf("%s\n", name);
    //if (key == GLFW_KEY_E && action == GLFW_PRESS)
    //    activate_airship();
}