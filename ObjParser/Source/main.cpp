#pragma once

#include <vector>

#include <GLM/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Core/Reader.h"
#include "Core/ModelLoader.h"
#include "Core/Texture.h"

#include "Core/Context.h"
#include "Core/Material.h"
#include "Core/Shader.h"
#include "Core/VertexArrayObject.h"
#include "Core/VertexBufferObject.h"
#include "Core/IndexBuffer.h"

void processInput(GLFWwindow *window, glm::mat4 &model, glm::vec3 &lightPos);

int main()
{
	PRINT(std::endl << "MAIN >> Initialization..." << std::endl);
	Context context(800, 600, "PROJECT1");

	ModelLoader cube("Resources/Models", "Teapot.obj");
	ModelLoader lightSource("Resources/Models", "cube.obj");

	glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
	glm::vec3 lightPosition(10.0f, 0, 0.0f);
	glm::vec3 cameraPosition(0.0f, 10.0f, 50.0f);

	VertexArrayObject VAO;
	VertexBufferObject VBO(cube.GetVertexData());
	IndexBuffer IBO(cube.GetIndexData());

	VAO.AddBuffer(&VBO, AttribPointerLayout{ 0, 3, 8, 0 }); // Index, size, stride, offset
	VAO.AddBuffer(&VBO, AttribPointerLayout{ 1, 2, 8, 3 }); // Index, size, stride, offset
	VAO.AddBuffer(&VBO, AttribPointerLayout{ 2, 3, 8, 5 }); // Index, size, stride, offset

	Shader cubeShader(Reader::Open("Resources/Shaders/Default_VS.glsl").c_str(), Reader::Open("Resources/Shaders/Default_FS.glsl").c_str());
	cubeShader.Use();
	cubeShader.GetActiveUniformList();

	Material cubeMat(cube.material, cubeShader);

	// Create transformations
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	Texture textureTest("Resources/Images/test.png");
	textureTest.Bind();
	cubeShader.SetUniform1i("tex", 0);


	glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	//model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
	//model = glm::scale(model, glm::vec3(8.0f, 8.0f, 8.0f));

	view = glm::lookAt(
		cameraPosition,
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);

	projection = glm::perspective(glm::radians(45.0f), (float)context.GetScreenWidth() / (float)context.GetScreenHeight(), 0.1f, 100.0f);

	cubeShader.SetUniform3fv("lightColor", lightColor);
	cubeShader.SetUniform3fv("lightPosition", lightPosition);
	cubeShader.SetUniform3fv("viewPos", cameraPosition);
	cubeShader.SetUniformMat4fv("model", model);
	cubeShader.SetUniformMat4fv("projection", projection);
	cubeShader.SetUniformMat4fv("view", view);

	VAO.Unbind();
	IBO.Unbind();
	VBO.Unbind();

	// New VAO for light source
	VertexArrayObject VAO2;
	VertexBufferObject VBO2(lightSource.GetVertexData());
	IndexBuffer IBO2(lightSource.GetIndexData());
	VAO2.AddBuffer(&VBO2, AttribPointerLayout{ 0, 3, 8, 0 }); // Index, size, stride, offset

	Shader lightSourceShader(Reader::Open("Resources/Shaders/LightSource_VS.glsl").c_str(), Reader::Open("Resources/Shaders/LightSource_FS.glsl").c_str());
	lightSourceShader.Use();
	lightSourceShader.SetUniform3fv("color", lightColor);

	// Create transformations
	glm::mat4 model2 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	model2 = glm::translate(model2, lightPosition);

	lightSourceShader.SetUniformMat4fv("projection", projection);
	lightSourceShader.SetUniformMat4fv("view", view);

	VAO2.Unbind();
	IBO2.Unbind();
	VBO2.Unbind();

	PRINT(std::endl << "MAIN >> Rendering..." << std::endl);


	const double targetFPS = 30.0;
	const double targetFrameTime = 1.0 / targetFPS;

	while (context.IsRendering())
	{
		// Record the start time of the frame
		double startTime = glfwGetTime();

		processInput(context.MainWindow, model2, lightPosition);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		// Draw target object
		cubeShader.Use();
		model = glm::rotate(model, glm::radians(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		cubeShader.SetUniform3fv("lightPosition", lightPosition);
		cubeShader.SetUniformMat4fv("model", model);
		VAO.Bind();
		glDrawElements(GL_TRIANGLES, cube.GetIndexData().size(), GL_UNSIGNED_INT, nullptr);

		// Draw light source
		lightSourceShader.Use();
		lightSourceShader.SetUniformMat4fv("model", model2);
		VAO2.Bind();
		glDrawElements(GL_TRIANGLES, lightSource.GetIndexData().size(), GL_UNSIGNED_INT, nullptr);

		glfwSwapBuffers(context.MainWindow);

		// Calculate the elapsed time for the frame
		double endTime = glfwGetTime();
		double elapsedTime = endTime - startTime;

		// Check if we need to wait to achieve the target frame rate
		if (elapsedTime < targetFrameTime)
		{
			// Calculate the time to sleep
			double sleepTime = targetFrameTime - elapsedTime;

			// Convert sleep time to milliseconds
			int sleepMilliseconds = static_cast<int>(sleepTime * 1000.0);

			// Use glfwWaitEventsTimeout to sleep and handle events
			glfwWaitEventsTimeout(sleepTime - 0.001); // subtract a small amount to ensure slight overshoot
		}

		glfwPollEvents(); // checks events
	}

	glfwTerminate(); // clean glfw resources
	PRINT(std::endl << "MAIN >> Terminating..." << std::endl);

	return 0;
}

// TODO work on lightpos
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window, glm::mat4 &model, glm::vec3 &lightpos)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	 //TODO refactor
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -1.0f));
		lightpos += glm::vec3(0.0f, 0.0f, -1.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		model = glm::translate(model, glm::vec3(-1.0f, 0.0f, 0.0f));
		lightpos = lightpos + glm::vec3(-1.0f, 0.0f, 0.0f);
	}	
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 1.0f));
		lightpos = lightpos + glm::vec3(0.0f, 0.0f, 1.0f);
	}	
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		model = glm::translate(model, glm::vec3(1.0f, 0.0f, 0.0f));
		lightpos = lightpos + glm::vec3(1.0f, 0.0f, 0.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		model = glm::translate(model, glm::vec3(0.0f, 1.0f, 0.0f));
		lightpos = lightpos + glm::vec3(0.0f, 1.0f, 0.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		model = glm::translate(model, glm::vec3(0.0f, -1.0f, 0.0f));
		lightpos = lightpos + glm::vec3(0.0f, -1.0f, 0.0f);
	}

}