#include "Triangle.h"

void Triangle::run()
{
	initWindow();
	initVulkan();
	mainLoop();
	cleanup();
}

void Triangle::initWindow()
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "My First Vulkan App", nullptr, nullptr);
}

void Triangle::initVulkan()
{
	createInstance();
}

void Triangle::mainLoop()
{
	while (!glfwWindowShouldClose(mainWindow))
	{
		glfwPollEvents();
	}
}

void Triangle::cleanup()
{
	vkDestroyInstance(instance, nullptr);

	glfwDestroyWindow(mainWindow);	//glfwCreateWindow();

	glfwTerminate();	//glfwInit();
}

void Triangle::createInstance()
{
	// Application Info Struct

	VkApplicationInfo appInfo{};

	appInfo.apiVersion = VK_MAKE_VERSION(VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);

	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "My Triangle";

	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 0);

	appInfo.apiVersion = VK_API_VERSION_1_0;

	// Instance Create Info Struct

	VkInstanceCreateInfo createInfo{};

	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	// Extensions necessary

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;

	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;
	createInfo.enabledLayerCount = 0;

	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
		throw std::runtime_error("Failed to create Vulkan Instance!\n");
}