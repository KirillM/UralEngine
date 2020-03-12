//
//  Extension.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 09.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <OpenGL/glext.h>

// Производители могут добавлять модули к API OpenGL
// Добавлять новые токены - которые распознаются glEnable()


// пример

GL_ARB_color_buffer_float GL_ARB_depth_buffer_float
GL_ARB_depth_clamp
GL_ARB_depth_texture
GL_ARB_draw_buffers
GL_ARB_draw_elements_base_vertex
GL_ARB_draw_instanced
GL_ARB_fragment_program
GL_ARB_fragment_program_shadow
GL_ARB_fragment_shader
GL_ARB_framebuffer_object
GL_ARB_framebuffer_sRGB
GL_ARB_half_float_pixel
GL_ARB_half_float_vertex
GL_ARB_imaging

GL_EXT // Совместимо с продукцией разных производителей
GL_ARB // Одобрено ARB, находятся на оппробации - последней стадии перед включением в стандарт
GL_WGL // Microsoft
GL_APPLE
GL_ATI
GL_NV
GL_SGI
GL_IBM
GL_SGIS
