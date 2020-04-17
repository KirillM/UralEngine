//
//  OpenGLVertexBuffer.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 17.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "OpenGLVertexBuffer.h"
#include "RenderAPI/OpenGL/OpenGLAPI.h"

namespace Ural {
    OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size)
    {
        /*
        Note that glGenBuffers is not required to assign a buffer object name
        before it is bound using glBindBuffer
        */
        glGenBuffers(1, &m_BufferID);
        /*
         When a buffer object is bound to a target, the previous binding for that target is automatically broken.
         */
        glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer()
    {
        glDeleteBuffers(1, &m_BufferID);
    }

    void OpenGLVertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
    }

    void OpenGLVertexBuffer::UnBind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    uint32_t OpenGLVertexBuffer::Size()
    {
        GLint size = 0;
        glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
        return size;
    }

    uint32_t OpenGLVertexBuffer::Usage()
    {
        GLint usage = 0;
        glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_USAGE, &usage);
        return usage;
    }

//    uint32_t OpenGLVertexBuffer::Offset()
//    {
//        GLint offset = 0;
//        glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_MAP_OFFSET, &offset);
//        return offset;
//    }
//
//    uint32_t OpenGLVertexBuffer::MapOffset()
//    {
//        GLint offset = 0;
//        glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_MAP_OFFSET, &offset);
//        return offset;
//    }
//
//    uint32_t OpenGLVertexBuffer::MapLenght()
//    {
//        GLint lenght = 0;
//        glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_MAP_LENGTH, &lenght);
//        return lenght;
//    }
//
//    bool OpenGLVertexBuffer::IsMapped()
//    {
//        GLint isMapped = 0;
//        glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_MAPPED, &isMapped);
//        return isMapped;
//    }
//
//    uint32_t OpenGLVertexBuffer::AccessFlags()
//    {
//        GLint policyFlags = 0;
//        glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_ACCESS_FLAGS, &policyFlags);
//        return policyFlags;
//    }

//    uint32_t OpenGLVertexBuffer::MaxVertexAttributes()
//    {
//        GLint maxVertexAttribs = 0; // n will be >= 16
//        glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &maxVertexAttribs);
//        return maxVertexAttribs;
//    }

}
