//
//  UInions.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>

struct Vector2
{
    float x,y;
};
struct Vector4
{
    union
    {
        struct
        {
            float x, y, z, w;
        }
        struct
        {
            Vector2 a, b;
        }
    }
};

int main()
{
    union {
        float a;  // equal memory
        int b;  // equal memory
    };
}
