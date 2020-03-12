//
//  Commands.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 10.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <OpenGL/gl.h>


// управление и проверка состояний
glEnable()
glDisable()
glIsEnable()

glClearColor() // устанавливает цвет для очистки окна
glFinish() // инициирует завершение всех пердыдущих комманд, в отличае от glFlush не возвращается пока все команды не выполнятся
glFlush() // опорожнить все очереди комманд и буферы

// для извлечения переключаемых значений
glGetBooleanv(GLenum pname, GLboolean *params);
glGetDoublev(GLenum pname, GLdouble *params);
glGetFloatv(GLenum pname, GLfloat *params);
glGetIntegerv(GLenum pname, GLint *params);

glGetError() // возвращает коды ошибоек Errors.cpp


glGetString(GL_VENDOR) // Название постовщика дравйвера
glGetString(GL_RENDERER)  // зависит от постовщика (может содержать название торговой марки)
glGetString(GL_VERSION) // Номер версии
glGetString(GL_EXTENSIONS) // список имен расширений


// Управление скоростью / качеством ( эта функця целиком определяется производителем драйверов )
// Разрешить необязательный контроль над определенными аспектами поведения при визуализации
GL_NICEST
GL_FASTEST
GL_DONT_CARE

glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_DONT_CARE) // желаемо качество параметрической интерполяции
glHint(GL_POINT_SMOOTH_HINT, GL_DONT_CARE) // желаемое качество дискретизации точек
glHint(GL_POINT_LINE_HINT, GL_DONT_CARE) // желаемое качество дискретизации линий
glHint(GL_POLYGON_LINE_HINT, GL_DONT_CARE) // желаемое качество дискретизации многоугольников
glHint(GL_FOG_HINT, GL_DONT_CARE) // расчет тумана по вершинам (GL_FASTEST), или по пикселям (GL_NICEST)
glHint(GL_GENERATE_MIPMAP_HINT, GL_DONT_CARE) // качество и производительность автоматической генерации множесвенных изображений
glHint(GL_TEXTURE_COMPRESSION_HINT, GL_DONT_CARE) // качество и производительность сжатия текстурных изображений

glOrtho(left, right, bottom, top, near, far) // модифицировать границы отсечения, параллельный (ортогональный), объекты не ументшаются в размерах по z

// Стэк аттрибутов
glPushAttrib(GLbitfield mask);
glPopAttrib();

GL_ACCUM_BUFFER_BIT // Установки буфера накопления
GL_COLOR_BUFFER_BIT // Установки буфера цвета
GL_CURRENT_BIT // Текущий цвет и координаты
GL_DEPTH_BUFFER_BIT // Установки буфера глубины
GL_ENABLE_BIT // Все активизированные метки
GL_EVAL_BIT // Установки устройства оценки
GL_FOG_BIT // Установки тумана
GL_HINT_BIT_ALL // Подсказки OpenGL
GL_LIGHTING_BIT // Установки освещения
GL_LINE_BIT // Установки линий
GL_LIST_BIT // Установки таблиц отображения
GL_MULTISAMPLE_BIT // Множественная выборка
GL_PIXEL_MODE_BIT // Пиксельный режим
GL_POINT_BIT // Установки точек
GL_POLYGON_BIT // Установки ркжима многоугольников
GL_POLYGON_STIPPLE_BIT // Установки фактуры многоугольников
GL_SCISSOR_BIT // Установки тестов разрезания
GL_STENCIL_BUFFER_BIT // Уставновки буфера шаблонов
GL_TEXTURE_BIT // Установки текстур
GL_TRANSFORM_BIT // Установки преобразований
GL_VIEWPORT_BIT // Установки поля просмотра
GL_ALL_ATTRIB_BITS // Все состояния OpenGL


// Задание прямоугольника через противоположные вершины
glRectf(x1,y1,x2,y2);
glRectf(*v1,*v2);


glViewport(x, y, width, height) // Задать участок окна где OpenGL будет рисовать (в пикселях)

// reverse the default behavior of OpenGL
glFrontFace(GL_CW); // defaults : GL_CW (back) / GL_CCW (front)


// выключение (отбраковка) граней
GL_FRONT
GL_BACK
GL_FRONT_AND_BACK

glCullFace(GL_BACK);
glEnable(GL_CULL_FACE);



// face
GL_FRONT
GL_BACK
GL_FRONT_AND_BACK
// mode
GL_FILL // default // сплошной многоугольник
GL_LINE // многугольник нартсованный линиями
GL_POINT // многоугоьник нарисованный точками (рисуются вершины)

glPolygonMode(GLenum face, GLenum mode);


// The glPolygonOffset function shown here allows you to tweak the depth values of fragments, thus offsetting the depth values but not the actual physical location in 3D space
// The total offset applied to fragments is given by this equation:
// Depth Offset = (DZ X factor) + (r X units)

GL_POLYGON_OFFSET_FILL
GL_POLYGON_OFFSET_LINE
GL_POLYGON_OFFSET_POINT

glEnable(GL_POLYGON_OFFSET_LINE);
void glPolygonOffset(GLfloat factor, GLfloat units);

// Задача зоны рисования в окне

glEnable(GL_SCISSOR_TEST);
glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
