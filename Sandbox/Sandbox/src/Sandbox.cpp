//
//  main.cpp
//  Sandbox
//
//  Created by Кирилл Мезрин on 30/11/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include "Ural.hpp"

class Sandbox : public Ural::Application {
	
};

Ural::Application* Ural::CreateApplication()
{
	return new Sandbox();
}
