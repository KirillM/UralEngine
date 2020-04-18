//
//  Copy.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 06.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include <string>

struct Vector2
{
    float x,y;
};

class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

    String(const String& other)  : m_Size(other.m_Size)  // copy constructor
    {
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1); // deep copy
    }

    ~String()
    {
        delete m_Buffer;
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

int main()
{
    int a = 2;

    int b = a; // copy


    b = 3;

    Vector2 a1 = {2 ,3};
    Vector2 b1 = a1; // copy
    b1.x = 5;

    Vector2* a2 = new Vector2();
    Vector2* b2 = a2; // adderss(pointer) copy
    b2->x = 2;

    String str = "Test";
    String str2 = str; // shallow copy

    // разделяемое
    //    private:
    //    char* m_Buffer;
    //    unsigned int m_Size;

    // delete - вызывается 2-жды

}
