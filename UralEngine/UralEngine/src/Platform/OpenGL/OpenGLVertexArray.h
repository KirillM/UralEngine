//
//  OpenGLVertexArray.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 23.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLVertexArray_h
#define OpenGLVertexArray_h

#include "Renderer/VertexArray.h"
#include "Renderer/Buffer.h"

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

#endif /* OpenGLVertexArray_h */
