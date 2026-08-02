#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <exception>
#include <cmath>
#include <algorithm>

static void glfw_error_callback(int error, const char* description)
{
    std::fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main()
{
    try
    {
        glfwSetErrorCallback(glfw_error_callback);
        if (!glfwInit())
            return 1;

        const char* glsl_version = "#version 130";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

        GLFWwindow* window = glfwCreateWindow(800, 600, "Exercise 15_21 - Cross Platform ImGui", nullptr, nullptr);
        if (window == nullptr)
            return 1;
        
        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetContext().IO; (void)io;

        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);

        float p1_x = 240.0f, p1_y = 165.0f;
        float p2_x = 340.0f, p2_y = 165.0f;
        float p3_x = 260.0f, p3_y = 265.0f;

        float cx = 300.0f;
        float cy = 200.0f;
        float mainRadius = 100.0f;

        while (!glfwWindowShouldClose(window))
        {
            glfwPollEvents();

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            ImGui::Begin("Triangle Angle Calculator");

            ImGui::Text("Drag points or use sliders to change triangle vertices along/near the circle.");
            ImGui::SliderFloat("Point 1 X", &p1_x, cx - mainRadius, cx + mainRadius);
            ImGui::SliderFloat("Point 1 Y", &p1_y, cy - mainRadius, cy + mainRadius);
            ImGui::SliderFloat("Point 2 X", &p2_x, cx - mainRadius, cx + mainRadius);
            ImGui::SliderFloat("Point 2 Y", &p2_y, cy - mainRadius, cy + mainRadius);
            ImGui::SliderFloat("Point 3 X", &p3_x, cx - mainRadius, cx + mainRadius);
            ImGui::SliderFloat("Point 3 Y", &p3_y, cy - mainRadius, cy + mainRadius);

            double a = std::sqrt(std::pow(p3_x - p2_x, 2) + std::pow(p3_y - p2_y, 2));
            double b = std::sqrt(std::pow(p3_x - p1_x, 2) + std::pow(p3_y - p1_y, 2));
            double c = std::sqrt(std::pow(p2_x - p1_x, 2) + std::pow(p2_y - p1_y, 2));

            double angle0 = 0.0, angle1 = 0.0, angle2 = 0.0;
            if (b * c != 0.0) angle0 = std::acos(std::clamp((a * a - b * b - c * c) / (-2 * b * c), -1.0, 1.0));
            if (a * c != 0.0) angle1 = std::acos(std::clamp((b * b - a * a - c * c) / (-2 * a * c), -1.0, 1.0));
            if (a * b != 0.0) angle2 = std::acos(std::clamp((c * c - b * b - a * a) / (-2 * a * b), -1.0, 1.0));

            ImGui::Text("Angle at Point 1: %.2f degrees", angle0 * 180.0 / 3.14159265358979323846);
            ImGui::Text("Angle at Point 2: %.2f degrees", angle1 * 180.0 / 3.14159265358979323846);
            ImGui::Text("Angle at Point 3: %.2f degrees", angle2 * 180.0 / 3.14159265358979323846);

            ImGui::End();

            ImGui::Render();
            int display_w, display_h;
            glfwGetFramebufferSize(window, &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(window);
        }

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(window);
        glfwTerminate();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}