//
//  VertexBuffer.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 15.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "VertexBuffer.h"
#include "RenderAPI/RenderAPI.h"
#include "RenderAPI/OpenGL/Buffers/OpenGLVertexBuffer.h"

namespace Ural {

    Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
    {
        switch (RenderAPI::s_API) {
            case RenderAPI::API::None: {
                UL_CORE_ASSERT(false, "RendererAPI::None not supported");
                return nullptr;
            }
            case RenderAPI::API::OpenGL: {
                return std::make_shared<OpenGLVertexBuffer>(vertices, size);
            }
        }

         UL_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }

}
