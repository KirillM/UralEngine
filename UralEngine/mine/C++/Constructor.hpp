//
//  Constructor.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 05.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//


#ifndef Constructor_hpp
#define Constructor_hpp

#include <iostream>
#include <string>

class exap
{
public:
    //&exap() {}
    exap(int x): m_X(x) {}
private:
    int m_X;
};

class Entity
{
private:
    int m_Score;
    std::string m_Name;
    const int m_Trs; // константы можно инициализировать только через list
    exap ex;
public:
    Entity()
        : m_Name("Unknown"), m_Score(0), m_Trs(0)  // инициализируются в порядке объявления в классе : сначала int потом string
    {
        //m_Name = "Unknown";
        ex = exap(8); // инициализируется два раза, даже если не указано в списке
    }

    Entity()
        : m_Score(0)
    {
        // в первый раз с default constructor string'a
        m_Name = "Unknown"; // инициалтзируется второй раз все равно
    }

    Entity(const std::string& name) : m_Name(name)
    {
        //m_Name = name;
    }
    const std::string& GetName() const { return m_Name; }
};

#endif /* Constructor_hpp */

int main()
{
    Entity e0;
    std::cout << e0.GetName() << std::endl;

    Entity e1("Entity");
    std::cout << e1.GetName() << std::endl;
}
