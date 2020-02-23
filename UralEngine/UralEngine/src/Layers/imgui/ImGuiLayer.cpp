//
//  ImGuiLayer.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 22.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "ImGuiLayer.h"

#include <imgui.h>
//#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
//#define IMGUI_IMPL_API
#include "examples/imgui_impl_opengl3.cpp"
#include "examples/imgui_impl_glfw.cpp"

#include <GLFW/glfw3.h>
#include "Ural/Application.h"
#include "Platform/Mac/MacWindow.h"
#include <glad/glad.h>

namespace Ural {
    ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
    {

    }
    ImGuiLayer::~ImGuiLayer()
    {

    }

    void ImGuiLayer::OnAttach()
    {
         IMGUI_CHECKVERSION();
         ImGui::CreateContext();
         ImGuiIO& io = ImGui::GetIO(); (void)io;
         io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
         //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
         io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
         io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
         io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
         io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
         //io.ConfigViewportsNoAutoMerge = true;
         //io.ConfigViewportsNoTaskBarIcon = true;

         // Setup Dear ImGui style
         ImGui::StyleColorsDark();
         //ImGui::StyleColorsClassic();

         // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
         ImGuiStyle& style = ImGui::GetStyle();
         if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
         {
             style.WindowRounding = 0.0f;
             style.Colors[ImGuiCol_WindowBg].w = 1.0f;
         }

        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
         // Setup Platform/Renderer bindings
         ImGui_ImplGlfw_InitForOpenGL(window, true);
         ImGui_ImplOpenGL3_Init("#version 330");
    }
    void ImGuiLayer::OnDetach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::OnUpdate()
    {
//        ImGuiIO& io = ImGui::GetIO();
//        Application& app = Application::Get();
//
//        int w, h;
//        int display_w, display_h;
//        w = app.GetWindow().GetWidth();
//        h = app.GetWindow().GetHeight();
//
//        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
//        glfwGetFramebufferSize(window, &display_w, &display_h);
//        io.DisplaySize = ImVec2((float)w, (float)h);
//
//        if (w > 0 && h > 0)
//            io.DisplayFramebufferScale = ImVec2((float)display_w / w, (float)display_h / h);
//
//
//        float time = (float)glfwGetTime();
//        io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
//        m_Time = time;
//
//        ImGui_ImplOpenGL3_NewFrame();
//        ImGui::NewFrame();
//
//        static bool bWindowSizeInit = false;
//
//        ImGui::Begin( "MainWindow" , 0 , ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
//            ImGuiWindowFlags_NoCollapse |
//            ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar );
//
//        ImGui::SetWindowSize( ImVec2( (float)display_w , (float)display_h ) );
//
//        if ( !bWindowSizeInit )
//        {
//            ImGui::SetWindowPos( ImVec2( 0 , 0 ) );
//            bWindowSizeInit = true;
//        }
//
//        ImGui::Text( "Application average %.3f ms/frame (%.1f FPS)" , 1000.0f / ImGui::GetIO().Framerate , ImGui::GetIO().Framerate );
//
//        ImGui::End();
//
//        glViewport( 0 , 0 , display_w , display_h );
//        glClear( GL_COLOR_BUFFER_BIT );
//
//        static bool show = true;
//        ImGui::ShowDemoWindow(&show);
//
//        ImGui::Render();
//        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        Begin();
        OnImGuiRender();
        End();
    }
    void ImGuiLayer::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<MouseButtonPressedEvent>(UL_BIND_EVENT_FN(OnMouseButtonPressedEvent));
        dispatcher.Dispatch<MouseButtonReleasedEvent>(UL_BIND_EVENT_FN(OnMouseButtonReleasedEvent));
        dispatcher.Dispatch<MouseMovedEvent>(UL_BIND_EVENT_FN(OnMouseMovedEvent));
        dispatcher.Dispatch<MouseScrolledEvent>(UL_BIND_EVENT_FN(OnMouseScrolledEvent));
        dispatcher.Dispatch<KeyPressedEvent>(UL_BIND_EVENT_FN(OnKeyPressedEvent));
        dispatcher.Dispatch<KeyReleasedEvent>(UL_BIND_EVENT_FN(OnKeyReleasedEvent));
        dispatcher.Dispatch<KeyTypedEvent>(UL_BIND_EVENT_FN(OnKeyTypedEvent));
        dispatcher.Dispatch<WindowResizeEvent>(UL_BIND_EVENT_FN(OnWindowResizedEvent));
    }

    void ImGuiLayer::OnImGuiRender()
    {
        static bool show = true;
        ImGui::ShowDemoWindow(&show);
    }

    void ImGuiLayer::Begin()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiLayer::End()
    {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::Get();
        io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

        //Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }

    bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[e.GetMouseButton()] = true;

        return false;
    }
    bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[e.GetMouseButton()] = false;

        return false;
    }
    bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MousePos = ImVec2(e.GetX(), e.GetY());

        return false;
    }
    bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseWheelH += e.GetXOffset();
        io.MouseWheel += e.GetYOffset();

        return false;
    }
    bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.KeysDown[e.GetKeyCode()] = true;

        return false;
    }
    bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.KeysDown[e.GetKeyCode()] = false;

        io.KeyCtrl  = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
        io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
        io.KeyAlt   = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
        io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
        return false;
    }
    bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        int keyCode = e.GetKeyCode();
        if (keyCode > 0 && keyCode < 0x10000)
            io.AddInputCharacter((unsigned short)keyCode);
        
        return false;
    }
    bool ImGuiLayer::OnWindowResizedEvent(WindowResizeEvent& e)
    {

        int w, h;
        int display_w, display_h;
        w = e.GetWidth();
        h = e.GetHeight();
        
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        glfwGetFramebufferSize(window, &display_w, &display_h);

        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(w, h);
        io.DisplayFramebufferScale = ImVec2((float)display_w / w, (float)display_h / h);
        //io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        ImGui::SetNextWindowSize(io.DisplaySize);
        
        glViewport(0, 0, (float)display_w, (float)display_h);
        return false;
    }
}
