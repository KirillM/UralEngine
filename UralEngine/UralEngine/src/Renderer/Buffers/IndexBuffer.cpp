//
//  IndexBuffer.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 15.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "IndexBuffer.h"
#include "Renderer/RendererAPI.h"
#include "RenderAPI/OpenGL/Buffers/OpenGLIndexBuffer.h"

namespace Ural {

    Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count)
    {
        switch (RendererAPI::GetAPI()) {
            case RendererAPI::API::None: {
                UL_CORE_ASSERT(false, "RendererAPI::None not supported");
                return nullptr;
            }
            case RendererAPI::API::OpenGL: {
                return std::make_shared<OpenGLIndexBuffer>(indices, count);
            }
        }

        UL_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }

}
