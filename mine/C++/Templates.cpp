//
//  Templates.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include <string>

void Print(int value)
{
    std::cout << value << std::endl;
}

void Print(float value)
{
    std::cout << value << std::endl;
}

void Print(std::string value)
{
    std::cout << value << std::endl;
}


template<typename T> // typename = class
void Print(T value)
{
    std::cout << value << std::endl;
}


template<typename T, int N>
class Array
{
private:
    T m_Array[N];
public:
    T GetSize() const { return N;}
};

int main()
{
    Print(5);
    Print(5.5f);
    Print("Hello");

    Print<int>(5);
    Print<std::string>("test");

    Array<int, 5> array;
}
