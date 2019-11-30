//
//  Ural.cpp
//  Ural
//
//  Created by Кирилл Мезрин on 30/11/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include "Ural.hpp"
#include "UralPriv.hpp"

void Ural::HelloWorld(const char * s)
{
    UralPriv *theObj = new UralPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void UralPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

