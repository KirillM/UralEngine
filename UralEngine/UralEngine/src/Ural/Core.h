//
//  Core.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 01/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#ifndef Core_h
#define Core_h

#ifdef UL_PLATFORM_MAC
    #define GL_SILENCE_DEPRECATION

	#ifdef UL_BUILD_DLYB
		#define URAL_API
	#else
		#define URAL_API
	#endif
#elif UL_PLATFORM_IOS
    #define GLES_SILENCE_DEPRECATION
    #define URAL_API
	//#error Ural only supports Mac!
#endif

#endif /* Core_h */

#define BIT(x) (1 << x)

#ifdef UL_ENABLED_ASSERTS
	#define UL_ASSERT(exp, ...) { if (!(exp)) { UL_ERROR("Assertion Failed: {0}", __VA_ARGS__); /*__debugbreak();*/ } }
	#define UL_CORE_ASSERT(exp, ...) { if (!(exp)) { UL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); /*__debugbreak();*/ } }
#else
	#define UL_ASSERT(exp, ...)
	#define UL_CORE_ASSERT(exp, ...)
#endif

#define UL_BIND_EVENT_FN(fn) std::bind(&ImGuiLayer::fn, this, std::placeholders::_1)
//#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
