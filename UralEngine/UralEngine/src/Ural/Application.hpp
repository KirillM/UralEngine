//
//  Application.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 01/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#ifndef Application_hpp
#define Application_hpp

#include "Core.h"

#pragma GCC visibility push(default)

namespace Ural {
	class URAL_API Application {
	public:
		Application();
		virtual ~Application();
		
		void Run();
	};

	// Реализована в клиенте
	Application *CreateApplication();
}

#pragma GCC visibility pop

#endif /* Application_hpp */
