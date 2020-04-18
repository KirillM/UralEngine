//
//  Const.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 05.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "Const.hpp"

class Entity
{
private:
    int m_X, m_y;
    int* x, y; // x - pointer, y - integer
    int* a, *b; // оба - pointers
    mutable int var; // позволяет изменяться в const методах
public:
    const int* const GetX2() const
    {
        return &m_X;
    }

    const int GetX3() const
    {
        return m_X;
    }

    int GetX() const // метод не будет менять содержимое класса
    {
        var = 2;
        return m_X;
    }

    int GetX() // обычно 2 версии метода 1 const другой нет
    {
        return m_X;
    }

    void SetX(int x)
    {
        m_X = x;
    }
};

void PrintEntity(const Entity& e)
{
    std::cout << e.GetX() << std::endl; //  зависит от const в методе
}

int main()
{

    Entity e;
    e.GetX();

    const Entity e2{};
    e2.GetX3(); // можно вызывать константные методы


    int x = 8;
    auto f = [=]() mutable //&x - by reference, & - everyting by ref, x - by value, = - everything by value
    {
        x++; // при mutable можно менять
        std::cout << x << std::endl;
    };

    f();
    //x == 8

    // при [&]
    f();
    // x == 9

    const int MAX_AGE = 90;

    const int* a = new int; // не могу менять содержимое
    int const* a1 = new int;

    int * const b = new int; // не могу менять адрес

    const int* const c = new int; // не могу менять ничего
}
