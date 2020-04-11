//
//  Class.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 05.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>

#ifndef Class_hpp
#define Class_hpp

class Test
{
public:
    Test() = delete; // удалить конструктор
    Test(int a, int b);
    ~Test();
    std::string GetName() { return "Entity"; }
    virtual std::string GetName2() { return "Entity"; }
};


class Player : public Test
{
private:
    std::string m_Name;
public:
    Player(const std::string& name)
        : m_Name(name), Test(5,6) {}
    std::string GetName() { return m_Name; }
    std::string GetName2() override { return m_Name; }
};

#endif /* Class_hpp */


int main() {
    Test a(5,6); //stack allocated

    Test *e = new Test(5,6);
    std::cout << e->GetName() << std::endl; // Entity

    Player *p = new Player("Name");
    std::cout << p->GetName() << std::endl; // Name

    Test *tt = p;
    std::cout << tt->GetName() << std::endl; // Entity

    Test *tt2 = p;
    std::cout << tt2->GetName2() << std::endl; // Name
}
