//
//  Application.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 01/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log/Log.h"

namespace Ural {

	Application::Application()
	
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	Application::~Application()
	{
		
	}

	void Application::OnEvent(Event& e)
	{
		UL_CORE_INFO("az {0}", e);
	}
		
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		UL_TRACE(e);
		
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}
