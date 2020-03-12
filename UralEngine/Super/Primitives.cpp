//
//  Primitives.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 11.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <OpenGL/gl.h>

GL_POINTS           // Each vertex is a single point on the screen.
GL_LINES            // Each pair of vertices defines a line segment.
GL_LINE_STRIP       // A line segment is drawn from the first vertex to each successive vertex.
GL_LINE_LOOP        // Same as GL_LINE_STRIP, but the last and first vertex are connected.
GL_TRIANGLES        // Every three vertices define a new triangle.
GL_TRIANGLE_STRIP   // Triangles share vertices along a strip.
GL_TRIANGLE_FAN     // Triangles fan out from an origin, sharing adjacent vertices


GLfloat sizes[2];
GLfloat step;

glGetFloatv(GL_POINT_SIZE_RANGE, sizes); // диапозон размеров
glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step); // наименьший интервал между ними
// OpenGL = 1.0
// Microsoft 0.125 - 10 / мин шаг 0.125
// при непопадании в диапозон исполбзуется наиболее приблеженное мин и макс,
// точки не меняют свое положение при перспективных преобразованиях
// не уменьшаются и не увеличиваются - всегда квадратные
// не является чтоным размером точки в пикселях, а приблизительном диаметре окружности содержаий все пиксели точки
glPointSize(64); // поддерживает не все размеры


glGetFloatv(GL_LINE_WIDTH_RANGE, width); // диапозон размеров
glGetFloatv(GL_LINE_WIDTH_GRANULARITY, &step); // наименьший интервал между ними
glLineWidth(GLfloat width)

glLineStipple(2, 127); // (factor, pattern)
// pattern - 16 бит, каждый бит соответсвует 1-му пикселю // 0000000011111111 -> ттттттттсссссссс (темно - светло)
// factor - множитель увеличивающий длину шаблона, столько-то включенных / выключенных пикселей подряд
