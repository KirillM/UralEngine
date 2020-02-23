//
//  VertexArray.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 23.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "VertexArray.h"
#include "Renderer.h"

namespace Ural {
    void VertexArray::Bind() const
    {
    }
    void VertexArray::UnBind() const
    {
    }

    void VertexArray::AddIndexBuffer(const std::shared_ptr<IndexBuffer>& indecBuffer)
    {

    }
    void VertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
    {
        
    }

    VertexArray* VertexArray::Create()
    {
        switch (Renderer::GetAPI()) {
               case RendererAPI::None: {
                   UL_CORE_ASSERT(false, "RendererAPI::None not supported");
                   return nullptr;
               }
               case RendererAPI::OpenGL: {
                   return new OpenGLVertexArray(vertices, size);
               }
         }

        UL_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }
}
