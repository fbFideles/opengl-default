#include <stdio.h>

#include "include/glad/glad.h"
#include <GLFW/glfw3.h>

#define WIDTH 800
#define HEIGHT 600

int init() {
	int init = glfwInit();
	if (init) {
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	
	}
	return init;
}

void viewport_resize_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void error(const char *errorstr) {
	printf("%s\n", errorstr);
	glfwTerminate();
}

int main (int argc, char *argv[])
{
	if (!init()) {
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Hello World", NULL, NULL);
	if (window == NULL) {
		error("Error while creating window");
		return 1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
	{
		error("Error while loading GLAD procs");
		return 1;
	}

	glViewport(0, 0, WIDTH, HEIGHT);
	glfwSetFramebufferSizeCallback(window, viewport_resize_callback);
	
	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
