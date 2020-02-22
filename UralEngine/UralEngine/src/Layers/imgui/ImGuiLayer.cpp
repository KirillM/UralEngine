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
//        ImGui::CreateContext();
//        ImGui::StyleColorsDark();
//
//        ImGuiIO& io = ImGui::GetIO();
//        //io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());
//        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
//        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
//
//        // Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array.
//        io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
//        io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
//        io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
//        io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
//        io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
//        io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
//        io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
//        io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
//        io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
//        io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
//        io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
//        io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
//        io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
//        io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
//        io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
//        io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
//        io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
//        io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
//        io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
//        io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
//        io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
//        io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;
//
//        ImGui_ImplOpenGL3_Init("#version 330");

        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_ViewPortsEnable;
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsClassic();

        // Setup Platform/Renderer bindings
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 330");
    }
    void ImGuiLayer::OnDetach()
    {

    }

    void ImGuiLayer::OnUpdate()
    {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::Get();

        int w, h;
        int display_w, display_h;
        w = app.GetWindow().GetWidth();
        h = app.GetWindow().GetHeight();

        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        glfwGetFramebufferSize(window, &display_w, &display_h);
        io.DisplaySize = ImVec2((float)w, (float)h);

        if (w > 0 && h > 0)
            io.DisplayFramebufferScale = ImVec2((float)display_w / w, (float)display_h / h);


        float time = (float)glfwGetTime();
        io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
        m_Time = time;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool bWindowSizeInit = false;
        
        ImGui::Begin( "MainWindow" , 0 , ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar );

        ImGui::SetWindowSize( ImVec2( (float)display_w , (float)display_h ) );

        if ( !bWindowSizeInit )
        {
            ImGui::SetWindowPos( ImVec2( 0 , 0 ) );
            bWindowSizeInit = true;
        }

        ImGui::Text( "Application average %.3f ms/frame (%.1f FPS)" , 1000.0f / ImGui::GetIO().Framerate , ImGui::GetIO().Framerate );

        ImGui::End();

        glViewport( 0 , 0 , display_w , display_h );
        glClear( GL_COLOR_BUFFER_BIT );

        static bool show = true;
        ImGui::ShowDemoWindow(&show);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
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
