//
//  OpenGLUniformBuffer.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 27.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLUniformBuffer_h
#define OpenGLUniformBuffer_h

#include "Renderer/Buffers/UniformBuffer.h"

namespace Ural {
    class OpenGLUniformBuffer : public UniformBuffer
    {
    public:
        OpenGLUniformBuffer(float* data, uint32_t size);
        ~OpenGLUniformBuffer();

        virtual void Bind() const override;
        virtual void UnBind() const override;
    private:
        uint32_t m_BufferID;
    };
}

#endif /* OpenGLUniformBuffer_h */
