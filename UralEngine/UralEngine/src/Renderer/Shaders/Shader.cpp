//
//  Shader.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 15.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "Shader.h"
#include "Renderer/RendererAPI.h"
#include "RenderAPI/OpenGL/Shaders/OpenGLShader.h"

namespace Ural {
    Ref<Shader> Shader::Create(const std::string& filepath)
    {
        switch (RendererAPI::GetAPI()) {
            case RendererAPI::API::None: {
                   UL_CORE_ASSERT(false, "RendererAPI::None not supported");
                   return nullptr;
               }
            case RendererAPI::API::OpenGL: {
                   return std::make_shared<OpenGLShader>(filepath);
               }
         }

        UL_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }

    Ref<Shader> Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        switch (RendererAPI::GetAPI()) {
            case RendererAPI::API::None: {
                   UL_CORE_ASSERT(false, "RendererAPI::None not supported");
                   return nullptr;
               }
            case RendererAPI::API::OpenGL: {
                   return std::make_shared<OpenGLShader>(name, vertexSrc, fragmentSrc);
               }
         }

        UL_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }
}
