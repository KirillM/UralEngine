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
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Ural {
	class Log {
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


#endif /* Log_hpp */
