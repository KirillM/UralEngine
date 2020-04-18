//
//  Static.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 05.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

static int a = 5;

static void test()
{
    return;
}

class CS
{
private:
    static int s_Instance ;

    static void func()
    {
        static char st = 0;
    }
};
