//
//  TypePuning.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>

struct Entity
{
    int x,y;
};

int main()
{
    int a = 50;
    double value = a; // implicit conversion
    double valu2e = (double)a; // explicit conversion

    double value3 = *(double*)&a; // &a + 4 bytes
    double& value4 = *(double*)&a; // reference
    value4 = 0.0; // 8 bytes
    std::cout << value << std::endl;

    Entity e = { 5, 8 };

    int* position = (int*)&e; // struct converted into array
    std::cout << position[0] << ", " << position[1] << std::endl;


    int y = *(int*)((char*)&e + 4);
}
