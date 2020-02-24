//
//  Log.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 04/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#ifndef Log_h
#define Log_h

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

#pragma GCC visibility push(default)

namespace Ural {
	class Log {
	public:
		static void Init();
		
		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}

#define UL_CORE_FATAL(...) Ural::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define UL_CORE_ERROR(...) Ural::Log::GetCoreLogger()->error(__VA_ARGS__)
#define UL_CORE_WARN(...) Ural::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define UL_CORE_INFO(...) Ural::Log::GetCoreLogger()->info(__VA_ARGS__)
#define UL_CORE_TRACE(...) Ural::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define UL_FATAL(...) Ural::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define UL_ERROR(...) Ural::Log::GetClientLogger()->error(__VA_ARGS__)
#define UL_WARN(...) Ural::Log::GetClientLogger()->warn(__VA_ARGS__)
#define UL_INFO(...) Ural::Log::GetClientLogger()->info(__VA_ARGS__)
#define UL_TRACE(...) Ural::Log::GetClientLogger()->trace(__VA_ARGS__)

#pragma GCC visibility pop

#endif /* Log_h */
