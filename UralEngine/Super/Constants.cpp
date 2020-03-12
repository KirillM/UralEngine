//
//  Constants.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 09.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <OpenGL/gl.h>

// Внутри себя OpenGL работает с float
// Аппартура ограничена 24 бит цветом (16 млн) если цвет не поддерживается аппаратурой OpenGL преобразует его к ближайшему который поддерживается аппаратурой

GLboolean   1 True or false boolean value
GLbyte      8 Signed 8-bit integer
GLubyte     8 Unsigned 8-bit integer
GLchar      8 String character
GLshort     16 Signed 16-bit integer
GLushort    16 Unsigned 16-bit integer
GLhalf      16 Half precision floating-point value
GLint       32 Signed 32-bit integer
GLuint      32 Unsigned 32-bit integer
GLsizei     32 Unsigned 32-bit integer
GLenum      32 Unsigned 32-bit integer
GLfloat     32 32-bit floating-point number
GLclampf    32 32-bit floating-point number in range [0, 1]
GLbitfield  32 32-bits
GLdouble    64 64-bit double precision number
GLclampd    64 64-bit double precision number in range [0, 1]
GLint64     64 Signed 64-bit integer
GLuint64    64 Unsigned 64-bit integer
GLsizeiptr  native pointer size Unsigned integer
GLintptr    native pointer Signed integer
GLsync      native pointer Sync object handle
