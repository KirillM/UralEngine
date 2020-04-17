//
//  IndexBuffer.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 15.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "IndexBuffer.h"
#include "RenderAPI/RenderAPI.h"
#include "RenderAPI/OpenGL/Buffers/OpenGLIndexBuffer.h"

namespace Ural {

    IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
    {
        switch (RenderAPI::s_API) {
            case RenderAPI::API::None: {
                UL_CORE_ASSERT(false, "RendererAPI::None not supported");
                return nullptr;
            }
            case RenderAPI::API::OpenGL: {
                return new OpenGLIndexBuffer(indices, count);
            }
        }

        UL_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }

}
