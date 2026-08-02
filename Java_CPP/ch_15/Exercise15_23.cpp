#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <exception>
#include <memory>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

class StopSignApp
{
public:
    void Render()
    {
        ImGui::Begin("Auto Resize Stop Sign Window");

        ImVec2 windowSize = ImGui::GetWindowSize();
        float currentWidth = windowSize.x > 0 ? windowSize.x : originalWidth;
        float currentHeight = windowSize.y > 0 ? windowSize.y : originalHeight;

        ImGui::Text("Window Size: %.0fx%.0f", currentWidth, currentHeight);

        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        ImVec2 p = ImGui::GetCursorScreenPos();
        
        float canvasWidth = std::max(100.0f, currentWidth - 40.0f);
        float canvasHeight = std::max(100.0f, currentHeight - 100.0f);
        
        ImVec2 center = ImVec2(p.x + canvasWidth * 0.5f, p.y + canvasHeight * 0.5f);
        float radius = std::min(canvasWidth, canvasHeight) * 0.4f;

        std::vector<ImVec2> points;
        points.reserve(8);
        for (int i = 0; i < 8; i++)
        {
            float angle = 2.0f * i * 3.14159265358979323846f / 8.0f + (22.5f * 3.14159265358979323846f / 180.0f);
            points.push_back(ImVec2(center.x + radius * std::cos(angle), center.y - radius * std::sin(angle)));
        }

        draw_list->AddConvexPolyFilled(points.data(), static_cast<int>(points.size()), IM_COL32(255, 0, 0, 255));

        std::string stopText = "STOP";
        ImVec2 textSize = ImGui::CalcTextSize(stopText.c_str());
        
        ImGui::SetCursorScreenPos(ImVec2(center.x - textSize.x * 0.5f, center.y - textSize.y * 0.5f));
        ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 1.0f), "%s", stopText.c_str());

        ImGui::End();
    }

private:
    float originalWidth = 200.0f;
    float originalHeight = 200.0f;
};

static void glfw_error_callback(int error, const char* description)
{
    std::fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

struct GlfwWindowDeleter 
{
    void operator()(GLFWwindow* window) const 
    {
        if (window) 
        {
            glfwDestroyWindow(window);
        }
    }
};

struct ImGuiContextDeleter 
{
    void operator()(ImGuiContext* ctx) const 
    {
        if (ctx) 
        {
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext(ctx);
        }
    }
};

struct GlfwSystemDeleter
{
    ~GlfwSystemDeleter()
    {
        glfwTerminate();
    }
};

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        glfwSetErrorCallback(glfw_error_callback);
        if (!glfwInit())
        {
            throw std::runtime_error("Failed to initialize GLFW.");
        }

        GlfwSystemDeleter glfwSystemCleaner;

        const char* glsl_version = "#version 130";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

        std::unique_ptr<GLFWwindow, GlfwWindowDeleter> window(
            glfwCreateWindow(800, 600, "Exercise 15_23 - Auto Resize Stop Sign", nullptr, nullptr)
        );

        if (!window)
        {
            throw std::runtime_error("Failed to create GLFW window.");
        }

        glfwMakeContextCurrent(window.get());
        glfwSwapInterval(1);

        IMGUI_CHECKVERSION();
        std::unique_ptr<ImGuiContext, ImGuiContextDeleter> imguiCtx(ImGui::CreateContext());
        ImGuiIO& io = ImGui::GetContext().IO; 
        (void)io;

        ImGui::StyleColorsDark();

        if (!ImGui_ImplGlfw_InitForOpenGL(window.get(), true) || !ImGui_ImplOpenGL3_Init(glsl_version))
        {
            throw std::runtime_error("Failed to initialize ImGui implementations.");
        }

        StopSignApp app;

        while (!glfwWindowShouldClose(window.get()))
        {
            glfwPollEvents();

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            app.Render();

            ImGui::Render();
            int display_w, display_h;
            glfwGetFramebufferSize(window.get(), &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(window.get());
        }
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