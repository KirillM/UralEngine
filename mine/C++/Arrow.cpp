//
//  Arrow.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include <string>

class Entity
{
public:
    int x;
public:
    void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr
{
private:
    Entity *m_Obj;
public:
    ScopedPtr(Entity* entity) : m_Obj(entity) {}
    ~ScopedPtr()
    {
        delete m_Obj;
    }

    Entity* GetObject() const
    {
        return m_Obj;
    }

    Entity* operator->()
    {
        return m_Obj;
    }

    const Entity* operator->() const
    {
        return m_Obj;
    }
};

struct Vector3
{
    float x,y,z; // 0 4 8
};

int main()
{
    Entity e;
    e.Print();

    Entity *ptr = &e;

    ptr->Print();
    ptr->x;

    ScopedPtr entity = new Entity();
    entity.GetObject()->Print();

    entity->Print();



    int offset = (long)&((Vector3*)nullptr)->x;

}
