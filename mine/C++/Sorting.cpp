//
//  Sorting.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> values = {3, 5, 1, 4, 2};

    std::sort(values.begin(), values.end());
    std::sort(values.begin(), values.end(), std::greater<int>());
    std::sort(values.begin(), values.end(), [](int a, int b) {
        return  a < b;
    });

    for (int value : values)
        std::cout << value << std::endl;
}
