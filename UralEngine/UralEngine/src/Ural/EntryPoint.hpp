//
//  EntryPoint.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 30/11/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#ifndef EntryPoint_hpp
#define EntryPoint_hpp

#include "Application.hpp"

#ifdef UL_PLATFORM_MAC

extern Ural::Application* Ural::CreateApplication();

int main(int argc, const char * argv[]) {
	printf("Hello world\n");
	auto app = Ural::CreateApplication();
	app->Run();
	delete app;
}

#endif

#endif /* EntryPoint_hpp */
