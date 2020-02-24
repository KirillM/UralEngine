//
//  Shader.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 23.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "Shader.h"

#include "Shader.h"
#include "Renderer.h"
#include "RendererAPI.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Ural {

    Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        switch (RendererAPI::GetAPI()) {
            case RendererAPI::API::None: {
                   UL_CORE_ASSERT(false, "RendererAPI::None not supported");
                   return nullptr;
               }
            case RendererAPI::API::OpenGL: {
                   return new OpenGLShader(vertexSrc, fragmentSrc);
               }
         }

        UL_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }
}

