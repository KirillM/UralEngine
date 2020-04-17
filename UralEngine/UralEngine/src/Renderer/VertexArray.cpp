//
//  VertexArray.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 17.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "VertexArray.h"
#include "RenderAPI/RenderAPI.h"
#include "RenderAPI/OpenGL/OpenGLVertexArray.h"
namespace Ural {

    Ref<VertexArray> VertexArray::Create()
    {
        switch (RenderAPI::s_API) {
            case RenderAPI::API::None: {
                   UL_CORE_ASSERT(false, "RendererAPI::None not supported");
                   return nullptr;
               }
            case RenderAPI::API::OpenGL: {
                   return std::make_shared<OpenGLVertexArray>();
               }
         }

        UL_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }
}
