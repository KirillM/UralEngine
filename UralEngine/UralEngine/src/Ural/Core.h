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
