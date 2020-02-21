//
//  Core.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 01/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#ifndef Core_h
#define Core_h

#include <stdio.h>

#ifdef UL_PLATFORM_MAC
    #define GL_SILENCE_DEPRECATION

	#ifdef UL_BUILD_DLYB
		#define URAL_API
	#else
		#define URAL_API
	#endif
#else
	#error Ural only supports Mac!
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

