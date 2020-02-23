//
//  OpenGLVertexArray.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 23.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLVertexArray_hpp
#define OpenGLVertexArray_hpp

#include "Renderer/VertexArray.h"
#include "Renderer/Buffer.h"

namespace Ural {
    class OpenGLVertexArray : public VertexArray {
    public:
        OpenGLVertexArray();
        ~OpenGLVertexArray();

        virtual void Bind() const override;
        virtual void UnBind() const override;

        virtual void AddIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;
        virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;

        virtual std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() override { return m_VertexBuffers; }
        virtual std::shared_ptr<IndexBuffer>& GetIndexBuffer() override { return m_IndexBuffer; }

    private:
        uint32_t m_RendererID;
        std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
        std::shared_ptr<IndexBuffer> m_IndexBuffer;
    };
}

#endif /* OpenGLVertexArray_hpp */
