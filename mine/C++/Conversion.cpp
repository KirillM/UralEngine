//
//  Conversion.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 06.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    Entity(const std::string& name) : m_Name(name), m_Age(-1) {}
    explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {} //disables implicit conversion
};

void PrintEntity(const Entity& entity)
{

}

int main()
{
    PrintEntity(22); // implicit conversion
    PrintEntity(std::string("Test"));
    PrintEntity(Entity("Test"));
    Entity a(std::string("Test"));
    Entity a1 = "Test"; // implicit conversion
    Entity b(22);
    Entity b2 = 22; // implicit conversion
}

