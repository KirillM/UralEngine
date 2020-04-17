//
//  OpenGLVertexBuffer.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 17.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLVertexBuffer_h
#define OpenGLVertexBuffer_h

#include "Renderer/Buffers/VertexBuffer.h"

namespace Ural {

    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(float* vertices, uint32_t size);
        ~OpenGLVertexBuffer();

        virtual void Bind() const override;
        virtual void UnBind() const override;

        virtual void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }
        virtual const BufferLayout& GetLayout() const override { return m_Layout; }

        static uint32_t Size();
        static uint32_t Usage();
    private:
        uint32_t m_BufferID;
        BufferLayout m_Layout;
    };

}

#endif /* OpenGLVertexBuffer_h */
