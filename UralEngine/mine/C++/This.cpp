//
//  This.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 06.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include <string>

void PrintEntity(Entity* e);

class Entity
{
public:
    int x,y;

    Entity(int x, int y)
    {
        Entity* const e = this;
        Entity* const & e2 = this;
        this = nullptr
        x = x;
        e->x = x;
        this->x;
        (*this).x = x;

        PrintEntity(this);
    }

    int GetX() const
    {
        const Entity* e = this;
        return x;
    }
}

void PrintEntity(Entity* e)
{

}


int main()
{

}
