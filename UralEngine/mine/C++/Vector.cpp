//
//  Vector.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x, y, z;

    Vertex() = default;
    Vertex(float x, float y, float z) : x(x), y(y), z(z) {}
    Vertex(const Vertex& vertex) : x(vertex.x), y(vertex.y), z(vertex.z)
    {

    }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}


int main()
{
    Vertex verticies[5];
    Vertex* vr = new Vertex[5];

    std::vector<Vertex> vrc;
    vrc.push_back({1, 2, 3}); //copied into vector
    vrc.push_back({4, 5, 6});

    for (int i = 1; i < vrc.size(); i++)
    {
        vrc[i];
    }

    for  (Vertex v : vrc) // copy
    {
        vrc;
    }

    for (const Vertex& v : vrc)
    {
        vrc;
    }

    vrc.erase(vrc.begin() + 1);

    std::vector<Vertex> vt;
    vt.reserve(3);
    vt.emplace_back(1, 2, 3); // calls constructor
    vt.emplace_back(4, 5, 6);
    vt.emplace_back(7, 8, 9);
    
}
