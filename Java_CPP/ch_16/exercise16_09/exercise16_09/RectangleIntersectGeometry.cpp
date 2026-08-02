#include <iostream>
#include <cmath>
#include <exception>
#include <stdexcept>
#include <string>

#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

struct RectData
{
    float cx;
    float cy;
    float w;
    float h;
};

bool CheckOverlap(const RectData& r1, const RectData& r2)
{
    float dx = std::abs(r1.cx - r2.cx);
    float dy = std::abs(r1.cy - r2.cy);
    return (dx <= (r1.w + r2.w) / 2.0f) && (dy <= (r1.h + r2.h) / 2.0f);
}

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

    GLFWwindow* window = glfwCreateWindow(800, 600, "Exercise_16_09", nullptr, nullptr);
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

    RectData rect1 = { 252.0f, 110.0f, 52.0f, 60.0f };
    RectData rect2 = { 100.0f, 66.0f, 80.0f, 56.0f };
    
    int dragging_rect = 0;

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
            ImGui::Begin("Main Content", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);

            bool intersects = CheckOverlap(rect1, rect2);
            std::string intersect_text = "Two rectangles intersect? ";
            intersect_text += (intersects ? "Yes" : "No");
            
            ImGui::TextUnformatted(intersect_text.c_str());
            ImGui::Separator();

            ImVec2 canvas_p0 = ImGui::GetCursorScreenPos();
            ImVec2 canvas_size = ImGui::GetContentRegionAvail();
            canvas_size.y -= 150.0f;
            if (canvas_size.x < 50.0f) canvas_size.x = 50.0f;
            if (canvas_size.y < 50.0f) canvas_size.y = 50.0f;
            ImVec2 canvas_p1 = ImVec2(canvas_p0.x + canvas_size.x, canvas_p0.y + canvas_size.y);

            ImDrawList* draw_list = ImGui::GetWindowDrawList();
            draw_list->AddRectFilled(canvas_p0, canvas_p1, IM_COL32(50, 50, 50, 255));
            draw_list->AddRect(canvas_p0, canvas_p1, IM_COL32(255, 255, 255, 255));

            ImGui::InvisibleButton("canvas", canvas_size);
            bool is_active = ImGui::IsItemActive();

            ImVec2 origin(canvas_p0.x, canvas_p0.y);

            ImVec2 r1_min(origin.x + rect1.cx - rect1.w / 2.0f, origin.y + rect1.cy - rect1.h / 2.0f);
            ImVec2 r1_max(origin.x + rect1.cx + rect1.w / 2.0f, origin.y + rect1.cy + rect1.h / 2.0f);
            
            ImVec2 r2_min(origin.x + rect2.cx - rect2.w / 2.0f, origin.y + rect2.cy - rect2.h / 2.0f);
            ImVec2 r2_max(origin.x + rect2.cx + rect2.w / 2.0f, origin.y + rect2.cy + rect2.h / 2.0f);

            if (is_active && ImGui::IsMouseClicked(ImGuiMouseButton_Left))
            {
                if (io.MousePos.x >= r1_min.x && io.MousePos.x <= r1_max.x &&
                    io.MousePos.y >= r1_min.y && io.MousePos.y <= r1_max.y)
                {
                    dragging_rect = 1;
                }
                else if (io.MousePos.x >= r2_min.x && io.MousePos.x <= r2_max.x &&
                         io.MousePos.y >= r2_min.y && io.MousePos.y <= r2_max.y)
                {
                    dragging_rect = 2;
                }
                else
                {
                    dragging_rect = 0;
                }
            }

            if (is_active && ImGui::IsMouseDragging(ImGuiMouseButton_Left) && dragging_rect != 0)
            {
                if (dragging_rect == 1)
                {
                    rect1.cx += io.MouseDelta.x;
                    rect1.cy += io.MouseDelta.y;
                }
                else if (dragging_rect == 2)
                {
                    rect2.cx += io.MouseDelta.x;
                    rect2.cy += io.MouseDelta.y;
                }
            }

            if (!is_active)
            {
                dragging_rect = 0;
            }

            draw_list->AddRect(r1_min, r1_max, IM_COL32(255, 0, 0, 255), 0.0f, 0, 2.0f);
            draw_list->AddRect(r2_min, r2_max, IM_COL32(0, 255, 0, 255), 0.0f, 0, 2.0f);

            ImGui::Spacing();
            ImGui::Columns(2, "inputs");
            
            ImGui::Text("Enter rectangle 1 info:");
            ImGui::InputFloat("Center X##1", &rect1.cx);
            ImGui::InputFloat("Center Y##1", &rect1.cy);
            ImGui::InputFloat("Width##1", &rect1.w);
            ImGui::InputFloat("Height##1", &rect1.h);
            
            ImGui::NextColumn();
            
            ImGui::Text("Enter rectangle 2 info:");
            ImGui::InputFloat("Center X##2", &rect2.cx);
            ImGui::InputFloat("Center Y##2", &rect2.cy);
            ImGui::InputFloat("Width##2", &rect2.w);
            ImGui::InputFloat("Height##2", &rect2.h);
            
            ImGui::Columns(1);
            ImGui::Spacing();

            if (ImGui::Button("Redraw Rectangles"))
            {
                if (rect1.w < 1.0f) rect1.w = 1.0f;
                if (rect1.h < 1.0f) rect1.h = 1.0f;
                if (rect2.w < 1.0f) rect2.w = 1.0f;
                if (rect2.h < 1.0f) rect2.h = 1.0f;
            }

            ImGui::End();

            ImGui::Render();
            glViewport(0, 0, window_w, window_h);
            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
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