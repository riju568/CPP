#include <iostream>
#include <cmath>
#include <exception>
#include <stdexcept>
#include <string>
#include <numbers>
#include <ctime>

#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

static void GlfwErrorCallback(int error_code, const char* description)
{
    std::cerr << "GLFW Error " << error_code << ": " << description << '\n';
}

int main()
{
    glfwSetErrorCallback(GlfwErrorCallback);

    if (!glfwInit())
    {
        return 1;
    }

    const char* glsl_version = nullptr;

#if defined(__APPLE__)
    glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#else
    glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif

    GLFWwindow* window = glfwCreateWindow(450, 400, "Exercise_16_07", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    std::time_t t = std::time(nullptr);
    std::tm* current_time = std::localtime(&t);

    int hour = current_time->tm_hour;
    int minute = current_time->tm_min;
    int second = current_time->tm_sec;

    try
    {
        while (!glfwWindowShouldClose(window))
        {
            glfwPollEvents();

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            int window_w = 0;
            int window_h = 0;
            glfwGetFramebufferSize(window, &window_w, &window_h);

            ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
            ImGui::SetNextWindowSize(ImVec2(static_cast<float>(window_w), static_cast<float>(window_h)));
            ImGui::Begin("ClockPane", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

            ImVec2 p0 = ImGui::GetCursorScreenPos();
            ImVec2 size = ImGui::GetContentRegionAvail();
            
            float footer_height = ImGui::GetFrameHeightWithSpacing() + 10.0f;
            size.y -= footer_height;
            if (size.x < 100.0f) size.x = 100.0f;
            if (size.y < 100.0f) size.y = 100.0f;

            ImVec2 center = ImVec2(p0.x + size.x / 2.0f, p0.y + size.y / 2.0f);
            float radius = std::fmin(size.x, size.y) * 0.8f * 0.5f;

            ImDrawList* draw_list = ImGui::GetWindowDrawList();
            
            draw_list->AddCircleFilled(center, radius, IM_COL32(255, 255, 255, 255));
            draw_list->AddCircle(center, radius, IM_COL32(0, 0, 0, 255), 0, 2.0f);

            draw_list->AddText(ImVec2(center.x - 7.0f, center.y - radius + 5.0f), IM_COL32(0, 0, 0, 255), "12");
            draw_list->AddText(ImVec2(center.x + radius - 15.0f, center.y - 7.0f), IM_COL32(0, 0, 0, 255), "3");
            draw_list->AddText(ImVec2(center.x - 4.0f, center.y + radius - 18.0f), IM_COL32(0, 0, 0, 255), "6");
            draw_list->AddText(ImVec2(center.x - radius + 7.0f, center.y - 7.0f), IM_COL32(0, 0, 0, 255), "9");

            const float pi = std::numbers::pi_v<float>;

            float s_len = radius * 0.8f;
            float s_angle = second * (2.0f * pi / 60.0f);
            ImVec2 s_end(center.x + s_len * std::sin(s_angle), center.y - s_len * std::cos(s_angle));
            draw_list->AddLine(center, s_end, IM_COL32(255, 0, 0, 255), 1.5f);

            float m_len = radius * 0.65f;
            float m_angle = minute * (2.0f * pi / 60.0f);
            ImVec2 m_end(center.x + m_len * std::sin(m_angle), center.y - m_len * std::cos(m_angle));
            draw_list->AddLine(center, m_end, IM_COL32(0, 0, 255, 255), 2.5f);

            float h_len = radius * 0.5f;
            float h_angle = ((hour % 12) + minute / 60.0f) * (2.0f * pi / 12.0f);
            ImVec2 h_end(center.x + h_len * std::sin(h_angle), center.y - h_len * std::cos(h_angle));
            draw_list->AddLine(center, h_end, IM_COL32(0, 255, 0, 255), 3.5f);

            ImGui::Dummy(size);
            ImGui::Separator();
            ImGui::Spacing();

            ImGui::PushItemWidth(window_w / 5.0f);
            
            ImGui::Text("Hour"); ImGui::SameLine();
            ImGui::InputInt("##h", &hour, 0, 0); ImGui::SameLine();
            
            ImGui::Text("Minute"); ImGui::SameLine();
            ImGui::InputInt("##m", &minute, 0, 0); ImGui::SameLine();
            
            ImGui::Text("Second"); ImGui::SameLine();
            ImGui::InputInt("##s", &second, 0, 0);
            
            ImGui::PopItemWidth();

            ImGui::End();

            ImGui::Render();
            glViewport(0, 0, window_w, window_h);
            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(window);
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "An unknown non-standard exception occurred.\n";
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}