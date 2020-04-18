//
//  FPointers.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include <vector>

void HelloWorld(int a)
{
    std::cout << "Test" << a << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for (int value : values)
        func(value);
}

void PrintValue(int value)
{
    std::cout << value << std::endl;
}

int main()
{
    typedef void(*HelloWorldFn)(int);
    HelloWorld(5);
    void(*function2)(int);


    auto function = HelloWorld; // implicit conversion for &
    auto function3 = &HelloWorld;
    function(5);
    function(5);

    function2 = function;

    HelloWorldFn fn = HelloWorld;

    ForEach({1,4,5,6,7}, PrintValue);

    ForEach({1,4,5,6,7}, [](int value) {
        std::cout << value << std::endl;
    });

}
