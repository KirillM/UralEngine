//
//  Application.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 01/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#ifndef Application_h
#define Application_h

#include "Core.h"
#include "Platform/Window/Window.h"
#include "Layers/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Time/TimeStep.h"

#pragma GCC visibility push(default)

namespace Ural {
	class URAL_API Application {
	public:
        Application();
		virtual ~Application();
		
		void Run();
		
		void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        static inline Application& Get() { return *s_Instance; }
        inline Window& GetWindow() { return *m_Window; }

	private:
        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent &e);
    private:
		std::unique_ptr<Window> m_Window = nullptr;
		bool m_Running = true;
        bool m_Minimized = false;
        LayerStack m_LayerStack;
        //TimeStep m_Timestep;
        float m_LastFrameTime = 0.0f;
        
    private:
        static Application* s_Instance;
	};

	// Реализована в клиенте
	Application *CreateApplication();
}

#pragma GCC visibility pop

#endif /* Application_h */
