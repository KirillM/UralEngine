//
//  OpenGLGraphicsDeviceInfo.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 16.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "OpenGLGraphicsDeviceInfo.h"
#include "OpenGLAPI.h"

// Производители могут добавлять модули к API OpenGL
// Добавлять новые токены - которые распознаются glEnable()


// пример

//GL_ARB_color_buffer_float GL_ARB_depth_buffer_float
//GL_ARB_depth_clamp
//GL_ARB_depth_texture
//GL_ARB_draw_buffers
//GL_ARB_draw_elements_base_vertex
//GL_ARB_draw_instanced
//GL_ARB_fragment_program
//GL_ARB_fragment_program_shadow
//GL_ARB_fragment_shader
//GL_ARB_framebuffer_object
//GL_ARB_framebuffer_sRGB
//GL_ARB_half_float_pixel
//GL_ARB_half_float_vertex
//GL_ARB_imaging

//GL_EXT // Совместимо с продукцией разных производителей
//GL_ARB // Одобрено ARB, находятся на оппробации - последней стадии перед включением в стандарт
//GL_WGL // Microsoft
//GL_APPLE
//GL_ATI
//GL_NV
//GL_SGI
//GL_IBM
//GL_SGIS
//GL_SHADING_LANGUAGE_VERSION

namespace Ural {
    void GraphicsDeviceInfo::PrintInfo()
    {
        UL_CORE_INFO("OpenGL Info:");
        UL_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
        UL_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
        UL_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
        UL_CORE_INFO("  Shader: {0}", glGetString(GL_SHADING_LANGUAGE_VERSION));
        UL_CORE_INFO("  Extensions: {0}", glGetString(GL_EXTENSIONS));
    }
}
