//
//  EntryPoint.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 30/11/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#ifndef EntryPoint_h
#define EntryPoint_h

#ifdef UL_PLATFORM_MAC

extern Ural::Application* Ural::CreateApplication();

int main(int argc, const char * argv[]) {
	
	
	Ural::Log::Init();
	UL_CORE_WARN("Initialezed Log");
	UL_INFO("INFO {0}", Ural::EventCategory::EventCategoryMouse);
	auto app = Ural::CreateApplication();
	app->Run();
	delete app;
}

#endif

#endif /* EntryPoint_h */
