#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <exception>
#include <memory>
#include <stdexcept>
#include <vector>
#include <random>
#include <string>

class AdditionQuizApp
{
public:
    AdditionQuizApp()
    {
        GenerateNewProblem();
    }

    void Render()
    {
        ImGui::Begin("Addition Quiz App");

        ImGui::Text("What is %d + %d?", number1, number2);

        ImGui::InputInt("Your Answer", &userAnswer);

        if (ImGui::Button("Submit"))
        {
            if (userAnswer == number1 + number2)
            {
                message = "You got it!";
                isCorrect = true;
            }
            else
            {
                isCorrect = false;
                bool alreadyGuessed = false;
                for (int guess : guesses)
                {
                    if (guess == userAnswer)
                    {
                        alreadyGuessed = true;
                        break;
                    }
                }

                if (alreadyGuessed)
                {
                    message = "You already entered " + std::to_string(userAnswer) + ". Wrong answer. Try again.";
                }
                else
                {
                    guesses.push_back(userAnswer);
                    message = "Wrong answer. Try again.";
                }
            }
        }

        if (isCorrect)
        {
            ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "%s", message.c_str());
            if (ImGui::Button("Next Problem"))
            {
                GenerateNewProblem();
            }
        }
        else
        {
            if (!message.empty())
            {
                ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", message.c_str());
            }
        }

        ImGui::End();
    }

private:
    void GenerateNewProblem()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 9);
        number1 = dis(gen);
        number2 = dis(gen);
        userAnswer = 0;
        guesses.clear();
        message.clear();
        isCorrect = false;
    }

    int number1 = 0;
    int number2 = 0;
    int userAnswer = 0;
    std::vector<int> guesses;
    std::string message;
    bool isCorrect = false;
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
            glfwCreateWindow(800, 600, "Exercise 11_16 - Addition Quiz", nullptr, nullptr)
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

Exercise11_16 implementation[cite: 15] ported as a single-file C++ Dear ImGui application:
        AdditionQuizApp app;

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