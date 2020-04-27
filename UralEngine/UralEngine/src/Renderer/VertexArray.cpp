//
//  VertexArray.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 17.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "VertexArray.h"
#include "Renderer/RendererAPI.h"
#include "RenderAPI/OpenGL/OpenGLVertexArray.h"
namespace Ural {

    Ref<VertexArray> VertexArray::Create()
    {
        switch (RendererAPI::GetAPI()) {
            case RendererAPI::API::None: {
                   UL_CORE_ASSERT(false, "RendererAPI::None not supported");
                   return nullptr;
               }
            case RendererAPI::API::OpenGL: {
                   return std::make_shared<OpenGLVertexArray>();
               }
         }

        UL_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }
}
