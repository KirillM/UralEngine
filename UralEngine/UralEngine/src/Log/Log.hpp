//
//  Log.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 04/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#ifndef Log_hpp
#define Log_hpp

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#pragma GCC visibility push(default)

namespace Ural {
	class Log {
	public:
		
//		inline static std::shared_ptr<spdlog::logger>& test() {
//			printf("test\n");
//			return s_CoreLogger;
//		}
		
//		static void test();
		
		static void Init()
		{
			spdlog::set_pattern("%^[%T] %n: %v%$");
			s_CoreLogger = spdlog::stdout_color_mt("URAL");
			s_CoreLogger->set_level(spdlog::level::trace);
			s_ClientLogger = spdlog::stdout_color_mt("APP");
			s_ClientLogger->set_level(spdlog::level::trace);
		}
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#pragma GCC visibility pop

#endif /* Log_hpp */
