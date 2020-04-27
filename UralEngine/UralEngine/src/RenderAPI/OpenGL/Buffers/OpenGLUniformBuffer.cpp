//
//  OpenGLUniformBuffer.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 27.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "OpenGLUniformBuffer.h"
#include "RenderAPI/OpenGL/OpenGLAPI.h"

namespace Ural {
    OpenGLUniformBuffer::OpenGLUniformBuffer(float* data, uint32_t size)
    {
        glGenBuffers(1, &m_BufferID);
        glBindBuffer(GL_UNIFORM_BUFFER, m_BufferID);
        glBufferData(GL_UNIFORM_BUFFER, size * sizeof(float), data, GL_DYNAMIC_DRAW);
    }

    OpenGLUniformBuffer::~OpenGLUniformBuffer()
    {
        glDeleteBuffers(1, &m_BufferID);
    }

    void OpenGLUniformBuffer::Bind() const
    {
        glBindBuffer(GL_UNIFORM_BUFFER, m_BufferID);
    }

    void OpenGLUniformBuffer::UnBind() const
    {
        glBindBuffer(GL_UNIFORM_BUFFER, 0);
    }
}
