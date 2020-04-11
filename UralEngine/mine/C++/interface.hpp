//
//  interface.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 05.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef interface_hpp
#define interface_hpp

#include <stdio.h>

class Printable
{
public:
    virtual std::string GetClassName() = 0; // pure virtual
};

class Entity : public Printable
{
public:
    virtual std::string GetName() { return "Entity"; }
    std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity
{
public:
    Player(const std::string& name) : m_Name(name) {}
    std::string GetName() override  { return m_Name; }
    std::string GetClassName() override { return "Player"; }
private:
    std::string m_Name;
};


int main()
{

}

#endif /* interface_hpp */
