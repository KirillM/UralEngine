//
//  UniformBuffer.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 15.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "UniformBuffer.h"
#include "Renderer/RendererAPI.h"
#include "RenderAPI/OpenGL/Buffers/OpenGLUniformBuffer.h"

namespace Ural {

    Ref<UniformBuffer> UniformBuffer::Create(float* data, uint32_t size)
    {
        switch (RendererAPI::GetAPI()) {
            case RendererAPI::API::None: {
                UL_CORE_ASSERT(false, "RendererAPI::None not supported");
                return nullptr;
            }
            case RendererAPI::API::OpenGL: {
                return std::make_shared<OpenGLUniformBuffer>(data, size);
            }
        }

        UL_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }

}
