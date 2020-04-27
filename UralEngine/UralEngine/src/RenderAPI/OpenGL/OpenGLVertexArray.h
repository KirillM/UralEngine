//
//  OpenGLVertexArray.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 17.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLVertexArray_h
#define OpenGLVertexArray_h

#include "Renderer/Buffers/VertexBuffer.h"
#include "Renderer/Buffers/VertexBuffer.h"
#include "Renderer/VertexArray.h"

#pragma GCC visibility push(default)

namespace Ural {
    class OpenGLVertexArray : public VertexArray {
    public:
        OpenGLVertexArray();
        ~OpenGLVertexArray();

        virtual void Bind() const override;
        virtual void UnBind() const override;

        virtual void AddIndexBuffer(const Ref<IndexBuffer>& indexBuffer) override;
        virtual void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) override;

        virtual std::vector<Ref<VertexBuffer>>& GetVertexBuffers() override { return m_VertexBuffers; }
        virtual Ref<IndexBuffer>& GetIndexBuffer() override { return m_IndexBuffer; }

    private:
        uint32_t m_RendererID;
        std::vector<Ref<VertexBuffer>> m_VertexBuffers;
        Ref<IndexBuffer> m_IndexBuffer;
    };
}

#pragma GCC visibility pop

#endif /* OpenGLVertexArray_h */
