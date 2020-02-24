//
//  VertexArray.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 23.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "VertexArray.h"
#include "Renderer.h"
#include "RendererAPI.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Ural {

    VertexArray* VertexArray::Create()
    {
        switch (RendererAPI::GetAPI()) {
            case RendererAPI::API::None: {
                   UL_CORE_ASSERT(false, "RendererAPI::None not supported");
                   return nullptr;
               }
            case RendererAPI::API::OpenGL: {
                   return new OpenGLVertexArray();
               }
         }

        UL_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }
}
