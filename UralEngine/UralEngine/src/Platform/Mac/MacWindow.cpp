//
//  MacWindow.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#include "MacWindow.h"
#include "Log/Log.h"

#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

#include "Platform/OpenGL/OpenGLContext.h"
// GLFW_INCLUDE_NONE

namespace Ural {

	static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char* description)
    {
        UL_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

	Window* Window::Create(const WindowsProps& props)
	{
		return new MacWindow(props);
	}

	MacWindow::MacWindow(const WindowsProps& props)
	{
		Init(props);
	}

	MacWindow::~MacWindow()
	{
		ShutDown();
	};

	void MacWindow::Init(const WindowsProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		UL_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();


            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            
			UL_CORE_ASSERT(success, "Could not initialized GLFW!");
            glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

        //////
//        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
//        glfwWindowHint(GLFW_DECORATED, GL_TRUE);
//        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GL_TRUE); // Only on latest versions
        ///////
//        int count;
//        GLFWmonitor **monitors = glfwGetMonitors(&count);
//        const GLFWvidmode *mode = glfwGetVideoMode(monitors[1]);
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
//                m_Window = glfwCreateWindow(mode->width, mode->height, m_Data.Title.c_str(), monitors[1], nullptr);

        m_Context = new OpenGLContext(m_Window);
        m_Context->Init();

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
        
		
		// Set GLFW Callbacks
		
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;
			
			WindowResizeEvent event(width, height);
			data.Callback(event);
		});
		
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.Callback(event);
		});
		
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key ,int scancode, int action ,int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action) {
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.Callback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.Callback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.Callback(event);
					break;
				}
			}
		});

        glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keyCode)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            KeyTypedEvent event(keyCode);
            data.Callback(event);
        });
		
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action) {
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent event(button);
						data.Callback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent event(button);
						data.Callback(event);
						break;
					}
				}
		});
		
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.Callback(event);
		});
		
		
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event((float)xPos, (float)yPos);
			data.Callback(event);
		});
 	}

	void MacWindow::ShutDown()
	{
		glfwDestroyWindow(m_Window);
	}

	void MacWindow::OnUpdate()
	{
		glfwPollEvents();
        m_Context->SwapBuffers();
	}

	void MacWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		
		m_Data.VSync = enabled;
	}

	bool MacWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}
