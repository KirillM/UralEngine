//
//  Instantiation.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 06.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;
public:
    Entity() : m_Name("Unknown") {}
    Entity(const String& name) : m_Name(name) {}

    const String& GetName() const { return m_Name; }
};

int main()
{
    // stack
    Entity entity; // инициализация дефолтным конструктором
    Entity enitity2 = Entity("Test");
    Entity enitity3("Test2");
    entity.GetName();

    // heap
    Entity *ent = new Entity("Test3");

    (*ent).GetName();
    ent->GetName();
    
    delete ent;
    // внктри происходит что то типа этого
    free(ent); // + вызывается деструктор


    int a = 2;
    int* b = new int;
    int *c = new int[50]; // 200 bytes

    Entity *qwerty = new(b) Entity; // выделяет память в определенном месте
    Entity* e = new Entity; // выделяем память
    Entity* e1 = new Entity(); // выделаяем память и вызываем конструктор
    Entity* e2 = new Entity[50]; // выделяем память

    // внктри происходит что то типа этого
    Entity* e4 = (Entity*)malloc(sizeof(Entity));
}
