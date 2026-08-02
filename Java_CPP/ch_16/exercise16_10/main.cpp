#include <iostream>
#include <exception>
#include <stdexcept>

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

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui Cross-Platform Application", nullptr, nullptr);
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
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    bool show_demo_window = true;
    bool show_another_window = false;
    float clear_color[4] = {0.45f, 0.55f, 0.60f, 1.00f};
    float counter_value = 0.0f;
    int click_count = 0;

    try
    {
        while (!glfwWindowShouldClose(window))
        {
            glfwPollEvents();

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            if (show_demo_window)
            {
                ImGui::ShowDemoWindow(&show_demo_window);
            }

            {
                ImGui::Begin("Application Control Panel");

                ImGui::Text("Cross-Platform C++ Application using Dear ImGui");
                ImGui::Separator();

                ImGui::Checkbox("Show Demo Window", &show_demo_window);
                ImGui::Checkbox("Show Extra Window", &show_another_window);

                ImGui::SliderFloat("Slider Value", &counter_value, 0.0f, 100.0f);
                ImGui::ColorEdit4("Background Color", clear_color);

                if (ImGui::Button("Increment Counter"))
                {
                    click_count++;
                }
                ImGui::SameLine();
                ImGui::Text("Click Count = %d", click_count);

                ImGui::Text("Frame Rate: %.1f FPS", io.Framerate);
                ImGui::End();
            }

            if (show_another_window)
            {
                ImGui::Begin("Extra Window", &show_another_window);
                ImGui::Text("Hello from another window!");
                if (ImGui::Button("Close"))
                {
                    show_another_window = false;
                }
                ImGui::End();
            }

            ImGui::Render();
            int display_w = 0;
            int display_h = 0;
            glfwGetFramebufferSize(window, &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(clear_color[0] * clear_color[3], clear_color[1] * clear_color[3], clear_color[2] * clear_color[3], clear_color[3]);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(window);
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred.\n";
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}