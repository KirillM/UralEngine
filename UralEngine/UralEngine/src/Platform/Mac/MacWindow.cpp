//
//  MacWindow.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#include "MacWindow.h"
#include "Ural/Core.h"
#include "Log/Log.h"

namespace Ural {
	static bool s_GLFWInitialized = false;
	
	Window* Window::Create(const WindowsProps& props)
	{
		return (Window*) new MacWindow(props);
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
			UL_CORE_ASSERT(success, "Culd not initialized GLFW!");
			
			s_GLFWInitialized = true;
		}
		
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
 	}

	void MacWindow::ShutDown()
	{
		glfwDestroyWindow(m_Window);
	}

	void MacWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
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
