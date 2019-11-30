//
//  UralStatic.cpp
//  UralStatic
//
//  Created by Кирилл Мезрин on 30/11/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include "UralStatic.hpp"
#include "UralStaticPriv.hpp"

void UralStatic::HelloWorld(const char * s)
{
    UralStaticPriv *theObj = new UralStaticPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void UralStaticPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

