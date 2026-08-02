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
#include <chrono>
#include <ctime>

class ClockApp
{
public:
    ClockApp()
    {
        UpdateCurrentTime();
    }

    void Render()
    {
        ImGui::Begin("Clock Eventing App");

        if (ImGui::Button("Start"))
        {
            isRunning = true;
        }
        ImGui::SameLine();
        if (ImGui::Button("Stop"))
        {
            isRunning = false;
        }

        if (isRunning)
        {
            UpdateCurrentTime();
        }

        ImVec2 p = ImGui::GetCursorScreenPos();
        ImVec2 windowSize = ImGui::GetContentRegionAvail();
        float radius = std::min(windowSize.x, windowSize.y) * 0.45f;
        ImVec2 center = ImVec2(p.x + windowSize.x * 0.5f, p.y + windowSize.y * 0.5f);

        if (radius > 0.0f)
        {
            ImDrawList* draw_list = ImGui::GetWindowDrawList();
            
            draw_list->AddCircleFilled(center, radius, IM_COL32(255, 255, 255, 255));
            draw_list->AddCircle(center, radius, IM_COL32(0, 0, 0, 255), 0, 2.0f);

            float secAngle = (second - 15.0f) * (3.14159265358979323846f / 30.0f);
            ImVec2 secEnd(center.x + std::cos(secAngle) * radius * 0.8f, center.y + std::sin(secAngle) * radius * 0.8f);
            draw_list->AddLine(center, secEnd, IM_COL32(255, 0, 0, 255), 1.0f);

            float minAngle = (minute - 15.0f) * (3.14159265358979323846f / 30.0f);
            ImVec2 minEnd(center.x + std::cos(minAngle) * radius * 0.65f, center.y + std::sin(minAngle) * radius * 0.65f);
            draw_list->AddLine(center, minEnd, IM_COL32(0, 0, 255, 255), 2.0f);

            float hourAngle = (hour + minute / 60.0f - 3.0f) * (3.14159265358979323846f / 6.0f);
            ImVec2 hourEnd(center.x + std::cos(hourAngle) * radius * 0.5f, center.y + std::sin(hourAngle) * radius * 0.5f);
            draw_list->AddLine(center, hourEnd, IM_COL32(0, 255, 0, 255), 3.0f);
        }

        ImGui::End();
    }

private:
    void UpdateCurrentTime()
    {
        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        struct tm* tm_info = std::localtime(&t);
        
        if (tm_info)
        {
            hour = tm_info->tm_hour % 12;
            minute = tm_info->tm_min;
            second = tm_info->tm_sec;
        }
    }

    bool isRunning = true;
    int hour = 0;
    int minute = 0;
    int second = 0;
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
            glfwCreateWindow(800, 600, "Exercise 15_32 - Clock Eventing App", nullptr, nullptr)
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

        ClockApp app;

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