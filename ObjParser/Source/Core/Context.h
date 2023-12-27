#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Logging.h"
#include <string>

class Context
{
public:
	Context(int width, int height, std::string name);
	~Context();

	GLFWwindow* MainWindow;

	void ResizeWindow(int width, int height);

	int GetScreenWidth() { return _screenWidth; };
	int GetScreenHeight() { return _screenHeight; };
	bool IsRendering() { return !glfwWindowShouldClose(MainWindow); };
private:
	int _screenWidth;
	int _screenHeight;
};

