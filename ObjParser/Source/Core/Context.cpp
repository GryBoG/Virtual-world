#pragma once

#include "Context.h"

Context::Context(int width, int height, std::string name)
{
	// Initialize GLFW
	glfwInit();

	// Create context
	MainWindow = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
	if (MainWindow == NULL)
	{
		PRINT("Failed to create GLFW window");
		glfwTerminate();
	}
	glfwMakeContextCurrent(MainWindow); // make context on current thread
	PRINT("CONTEXT >> Created a " << width << "x" << height << " window.");
	_screenWidth = width;
	_screenHeight = height;

	// Window hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	// 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// initialize glad before making any opengl calls
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		PRINT("Failed to initialize GLAD");
	}

	// Window settings
	glViewport(0, 0, 800, 600);

	// OpenGL settings
	glEnable(GL_DEPTH_TEST);

	PRINT("CONTEXT >> Vendor: " << glGetString(GL_VENDOR));
	PRINT("CONTEXT >> Renderer: " << glGetString(GL_RENDERER));
	PRINT("CONTEXT >> OpenGL version: " << glGetString(GL_VERSION));
	PRINT("CONTEXT >> GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION));
}

Context::~Context()
{
}

void Context::ResizeWindow(int width, int height)
{
	glfwSetWindowSize(MainWindow, width, height);
	glfwGetWindowSize(MainWindow, &_screenWidth, &_screenHeight);
	PRINT("CONTEXT >> Resized window to: " << width << "x" << height);
}

