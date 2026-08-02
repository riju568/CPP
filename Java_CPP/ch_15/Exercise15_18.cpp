#include <iostream>
#include <exception>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


int main()
{
    try
    {

        if (!glfwInit())
        {
            std::cerr << "Error: Failed to initialize GLFW.\n";
            return 3;
        }


        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
#endif
        constexpr float WINDOW_WIDTH = 600.0f;
        constexpr float WINDOW_HEIGHT = 600.0f;

        GLFWwindow* window = glfwCreateWindow(
            static_cast<int>(WINDOW_WIDTH),
            static_cast<int>(WINDOW_HEIGHT),
            "Move a rectangle using mouse (Dear ImGui)",
            nullptr, nullptr
        );

        if (!window)
        {
            glfwTerminate();
            std::cerr << "