#include<stdio.h>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

//Window Dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main()
{

	//Initialise GLFW
	if (!glfwInit())
	{
		printf("GLFW Initialization Failed");
		glfwTerminate();
		return 1;
	}

	// Setup GLFW window properties
	//Opengl version

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//Core profile = no backwards compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Allow forward comatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test WINDOW", NULL, NULL);
	if (!mainWindow)
	{
		printf("GLFW wndow creation failed");
		glfwTerminate();
		return 1;
	}

		//get Buffer size information
		int bufferWidth, bufferHeight;
		glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

		// set context for GLEW to use
		glfwMakeContextCurrent(mainWindow);

		//Allow modern extension features
		glewExperimental = GL_TRUE;

		if (glewInit() != GLEW_OK)
		{
			printf("GLEW Initialization failed!");
			glfwDestroyWindow(mainWindow);
			glfwTerminate();
			return 1;
		}

		//Setup Viewport size
		glViewport(0, 0, bufferWidth, bufferHeight);

		// Loop until window closed
		while (!glfwWindowShouldClose(mainWindow))
		{

			//Gwt+Handle user input event

			glfwPollEvents();
			
			//Clear window

			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers(mainWindow);

		}
		return 0;
}
