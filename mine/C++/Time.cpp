//
//  Time.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <thread>

struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        std::cout << ms << std::endl;
    }
};

void Fucntion()
{
    Timer timer;
    for (int i = 0; i < 100; i++) {
        std::cout << "t\n";
    }
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    std::this_thread::sleep_for(1s);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;

    duration.count();

    Fucntion();
}
