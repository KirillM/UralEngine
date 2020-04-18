//
//  Strings.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 05.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <stdlib.h>

const int asz = 6; // compiled-time known constant

static const int asz2 = 6;

int main()
{
    const char* str = "Hello";
    const char str2[6] = {'H', 'e', 'l', 'l', 'o', 0};

    int ar[asz];

    int array[5];
    sizeof(array); // 20 bytes
    int count = sizeof(array) / sizeof(int);
    int *ptr = array;
    array[2] = 3;
    *(ptr+2) = 3;
    *(int*)((char*)ptr +8) = 3;

    int* heap = new int[6];
    sizeof(heap); // size of int pointer = 4 bytes
    delete[] heap;

    "Gopa"; // const char[5] Gopa\0

    const char name[9] = "Che\0rno";
    std::cout << strlen(name) << std::endl; //3

    char *nn = "au"; // can't modify, const segment
    nn[1] = 's'; // exception

    char nn2[] = "au"; // can modify , copied from const segment
    nn2[1] = 's'; // good

    const wchar_t* nm = L"fdsdfdsfsdf"; // (2 win / 4 unix) bytes
    const char16_t* nm2 = u"fdsdfdsfsdf"; // 8 bytes
    const char32_t* nm3 = U"fdsdfdsfsdf";

    const char* exap = R"(csfsdf
    sdfsdf
    sdfsdf
    sdfsdf
    sdfsdfs
    dsfsdf)";

    const char *ex2 = "asdasd\n"
    "asdasd\n"
    "asdasd\n"
    "asdasd\n"
    "asdasd\n";

}
