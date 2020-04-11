//
//  Lambda.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include <vector>
#include <functional>


void ForEach(const std::vector<int>& values, const std::function<void(int)>& func) //void(*func)(int)
{
    for (int value : values)
        func(value);
}

int main()
{

    int a = 5;

    auto lambda = [=](int value) mutable {
        a = 6; // mutable
        std::cout << value << std::endl;
    };

    ForEach({1,4,5,6,7}, lambda);

    std::vector<int> values = {1,2,3,4,5,6,7,8};
    auto it = std::find_if(values.begin(), values.end(), [](int value) {
        return value > 3;
    });

    std::cout << *it << std::endl;
}
