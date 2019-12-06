//
//  Application.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 01/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#include "Application.hpp"

#include "Events/ApplicationEvent.h"
#include "Log/Log.hpp"

namespace Ural {
	Application::Application()
	{
		
	}
	Application::~Application()
	{
		
	}
		
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		UL_TRACE(e);
		
		while (true);
	}
}
