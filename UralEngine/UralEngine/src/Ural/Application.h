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
#include "Events/ApplicationEvent.h"

#pragma GCC visibility push(default)

namespace Ural {
	class URAL_API Application {
	public:
		Application();
		virtual ~Application();
		
		void Run();
		
		void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> m_Window = nullptr;
		bool m_Running = true;
		float t = 0;
	};

	// Реализована в клиенте
	Application *CreateApplication();
}

#pragma GCC visibility pop

#endif /* Application_h */
