#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "Triangle.h"

int main()
{
    Triangle myTriangle;

    try
    {
        myTriangle.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}