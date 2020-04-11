//
//  Tuple.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <string>
#include <array>
#include <vector>
#include <utility>
#include <functional>

std::string vs, fs;


void some(std::string& vs, std::string& fs) {
    vs = "as";
    fs = "sfd";
}

void some2(std::string* vs, std::string* fs) {
    if (vs) {
        *vs = "as";
    }
    if (fs) {
        *fs = "sfd";
    }
}

std::string* some3() {
    return new std::string[] {"as", "sfd"}; // heap
}

std::array<std::string, 2> some4() {
    return std::array<std::string, 2>({"as", "sfd"}); // stack copy
}

std::vector<std::string> some5() {
    return std::vector<std::string>({"as", "sfd"}); // heap
}

std::tuple<std::string, std::string> some6() {
    return std::make_pair(vs, fs);
}

std::pair<std::string, std::string> some7() {
    return std::make_pair(vs, fs);
}

int main()
{
    some(vs, fs);
    some2(&vs, &fs);

    std::tuple<std::string, std::string> ss = some6();
    std::string one = std::get<0>(ss);
    std::string two = std::get<1>(ss);

    auto dd = some7();
    std::string one1 = dd.first;
    std::string two2 = dd.second;
}
