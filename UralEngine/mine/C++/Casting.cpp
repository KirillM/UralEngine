//
//  Casting.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>

class Base
{
public:
    Base() {}
    ~Base() {}
};

class Derived : public Base
{
public:
    Derived() {}
    ~Derived() {}
};

class AnotherClass : public Base
{
public:
    AnotherClass() {}
    ~AnotherClass() {}
};


class Enitity
{
public:
    virtual void PrintName() {} //to have vtable
};

class Player : public Enitity
{

};

class Enemy : public Enitity
{

};

int main()
{
    double value = 5.25;
    double a = (int)(value +  5.3);

    // syntax sugar, compile time checks
    double s = static_cast<int>(value) + 5.3; // c++ style cast

    //as c-style puning
    AnotherClass* x = reinterpret_cast<AnotherClass*>(&value);

    Derived *derived = new Derived();

    Base *base = derived;

    // runtime checks
    AnotherClass *ac = dynamic_cast<AnotherClass*>(base);
    if (!ac) {

    }


    Player *player = new Player();
    Enitity *e = player;
    Enitity *e1 = new Enemy();
    Player *p = e;
    Player *p1 = (Player*)e1;
    Player *p2 = static_cast<Player*>(e1);
    Player *p3 = dynamic_cast<Player*>(e1); // must have vtable
// must have rtti: runtime type information : runtime information about all classes in memory

}
