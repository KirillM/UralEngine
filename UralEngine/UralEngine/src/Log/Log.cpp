//
//  Log.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 04/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#include "Log.hpp"
//#include "spdlog/sinks/stdout_color_sinks.h"

namespace Ural {
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

//	void Log::Init()
//	{
//		spdlog::set_pattern("%^[%T] %n: %v%$");
//		s_CoreLogger = spdlog::stdout_color_mt("URAL");
//		s_CoreLogger->set_level(spdlog::level::trace);
//		s_ClientLogger = spdlog::stdout_color_mt("APP");
//		s_ClientLogger->set_level(spdlog::level::trace);
//	}

//	void Log::test()
//	{
//		printf("test2\n");
////		spdlog::set_pattern("%^[%T] %n: %v%$");
////		s_CoreLogger = spdlog::stdout_color_mt("URAL");
////		s_CoreLogger->set_level(spdlog::level::trace);
////		s_ClientLogger = spdlog::stdout_color_mt("APP");
////		s_ClientLogger->set_level(spdlog::level::trace);
//	}

}
