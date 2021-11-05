#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <cstdlib>
#include <stdexcept>

class Triangle
{
	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 600;

	const uint32_t VERSION_MAJOR = 1;
	const uint32_t VERSION_MINOR = 0;
	const uint32_t VERSION_PATCH = 0;

	GLFWwindow* mainWindow;
	VkInstance instance;

public:
	void run();

private:

	void initWindow();
	void initVulkan();
	void mainLoop();
	void cleanup();

	void createInstance();
};