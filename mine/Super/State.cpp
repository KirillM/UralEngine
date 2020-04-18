//
//  State.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 10.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <OpenGL/gl.h>


// Turning different OpenGL features on and off changes the internal state of the driver. These state
// changes can be costly in terms of rendering performance. Frequently, performance-sensitive
// programmers go to great lengths to sort all the drawing commands so that geometry needing
// the same state is drawn together. This state sorting is one of the more common techniques to
// improve rendering speed in games.

// Состояния
glEnable()
glDisable()
glIsEnable()

GL_BLEND // Смешение цветов
GL_CULL_FACE // Отбор граней многоугольников выключение (отбраковка) граней -  Cull Backface

// The reverse of the painters algorithm actually speeds up fill performance. 
// Draw the objects nearest you first, and then the objects
//farther away. The depth test eliminates pixel writes that would fall under existing pixels,
//saving a considerable amount of memory bandwidth.
GL_DEPTH_TEST // Проверка глубины, z каждого рисуемого пикселя сравнивается с предыдущим чтобы понять рисовать его или нет
GL_DITHER // Добавление псевдослучайного шума
GL_FOG // Режим тумана
GL_LIGHTING // Освещение
GL_LIGHTx// x - ый источник света, минимум 8
GL_POINT_SMOOTH // Зашита от наложения точек (сглаживание) (antialiasing) (анти-ступенчаточть)
GL_LINE_SMOOTH // Защита от наложения линий (сглаживание) (antialiasing) (анти-ступенчаточть)
GL_LINE_STIPPLE // Предание шероховатости линиям
GL_POLYGON_SMOOTH // Защита от наложений многоугольников
GL_SCISSOR_TEST // Разрешено отсечение
GL_STENCIL_TEST // Проверка шаблона
GL_TEXTURE_1D // x
GL_TEXTURE_2D // мерные
GL_TEXTURE_3D // текстуры
GL_TEXTURE_CUBE_MAP // наложение текстуры на куб
GL_TEXTURE_GEN_S // генерация текстур
GL_TEXTURE_GEN_T
GL_TEXTURE_GEN_R
GL_TEXTURE_GEN_Q

GL_PROGRAM_POINT_SIZE

GL_POLYGON_OFFSET_FILL
GL_POLYGON_OFFSET_LINE
GL_POLYGON_OFFSET_POINT

GL_SAMPLE_ALPHA_TO_COVERAGE // Use the alpha value.
GL_SAMPLE_ALPHA_TO_ONE // Set alpha to 1 and use it.
GL_SAMPLE_COVERAGE // Use the value set with glSampleCoverage.
