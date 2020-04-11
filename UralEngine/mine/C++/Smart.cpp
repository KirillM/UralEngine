//
//  Smart.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 06.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include <string>
#include <memory>

class Entity
{
    Entity();
    ~Entity();
};

int main()
{
    std::weak_ptr<Entity> weak;
    std::shared_ptr<Entity> e0; // подсчет ссылок
    {
        std::shared_ptr<Entity> e1 = std::make_shared<Entity>(); // подсчет ссылок
        e0 = e1;
        weak = e1;
        std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // нельзя копировать
    } // -1
} // -1
