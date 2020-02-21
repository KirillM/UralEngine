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
#include <GLFW/glfw3.h>

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
		UL_CORE_INFO("event {0}", e);

        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));

        UL_CORE_TRACE("{0}", e);

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
        {
            (*--it)->OnEvent(e);
            if (e.Handled)
                break;
        }
	}
		
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		UL_TRACE(e);
		
		while (m_Running)
		{
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

    void Application::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer *layer)
    {
        m_LayerStack.PushOverlay(layer);
    }
}
