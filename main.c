#include <stdio.h>
#include <stdlib.h>

#include "include/glad/glad.h"
#include <GLFW/glfw3.h>

size_t WIDTH, HEIGHT;

int init() {
	int init = glfwInit();
	if (init) {
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	
	}
	return init;
}

void error(const char *errorstr) {
	printf("%s\n", errorstr);
	glfwTerminate();
}

void viewport_resize_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

GLFWwindow *load_window_context(char *name, int width, int height) {
	GLFWwindow* window = glfwCreateWindow(width, height, name, NULL, NULL);
	if (window == NULL) {
		error("Error while creating window");
		return NULL;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
		error("Error while loading GLAD procs");
		return NULL;
	}

	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(window, viewport_resize_callback);
	return window;	
}

void setWindowDimensions(char *width, char *height) {
	WIDTH = atoi(width);
	HEIGHT = atoi(height);
}

int main (int argc, char *argv[]) {
	if (!init()) {
		return 1;
	}
	
	setWindowDimensions(argv[1], argv[2]);

	GLFWwindow *window = load_window_context("Hello World", WIDTH, HEIGHT);
	if (window == NULL) {
		return 1;
	}

	float triangle_vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);

	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
