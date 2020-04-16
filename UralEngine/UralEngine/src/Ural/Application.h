//
//  Application.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 01/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#ifndef Application_h
#define Application_h

#include "Surface/Device/Window.h"
#include "Layers/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#pragma GCC visibility push(default)

namespace Ural {
	class URAL_API Application {
	public:
		virtual ~Application() = default;
		
		virtual void Run() = 0;
		
		virtual void OnEvent(Event& e) = 0;

        virtual void PushLayer(Layer* layer) = 0;
        virtual void PushOverlay(Layer* layer) = 0;

        static inline Application& Get() { return *s_Instance; }
    protected:
        static Application* s_Instance;
	};

	// Реализована в клиенте
	Application *CreateApplication();
}

#pragma GCC visibility pop

#endif /* Application_h */
