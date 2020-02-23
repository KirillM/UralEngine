//
//  Buffer.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 23.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "Buffer.h"
#include "Renderer.h"
#include "Ural/Core.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Ural
{
    VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
    {
        switch (Renderer::GetAPI()) {
            case RendererAPI::None: {
                UL_CORE_ASSERT(false, "RendererAPI::None not supported");
                return nullptr;
            }
            case RendererAPI::OpenGL: {
                return new OpenGLVertexBuffer(vertices, size);
            }
        }

         UL_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }

    IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
    {
        switch (Renderer::GetAPI()) {
            case RendererAPI::None: {
                UL_CORE_ASSERT(false, "RendererAPI::None not supported");
                return nullptr;
            }
            case RendererAPI::OpenGL: {
                return new OpenGLIndexBuffer(indices, count);
            }
        }

         UL_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }
}


