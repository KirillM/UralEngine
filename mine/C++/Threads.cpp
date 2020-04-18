//
//  Threads.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork()
{
    while (!s_Finished)
    {
        std::cout << "working...\n";
       // std::this_thread::sleep_for(1s);
    }
}

int main()
{
    std::thread worker(DoWork);

    std::cin.get();
    s_Finished = true;

    worker.join(); // wait blocvk vurrn thread until worker finidhed
}
