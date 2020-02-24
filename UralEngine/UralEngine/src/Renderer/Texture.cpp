//
//  Texture.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 25.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "Texture.h"

#include "Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Ural {
    Ref<Texture2D> Texture2D::Create(const std::string& path)
    {
        switch (RendererAPI::GetAPI()) {
              case RendererAPI::API::None: {
                     UL_CORE_ASSERT(false, "RendererAPI::None not supported");
                     return nullptr;
                 }
              case RendererAPI::API::OpenGL: {
                     return std::make_shared<OpenGLTexture2D>(path);
                 }
           }

          UL_CORE_ASSERT(false, "Unknown RendererAPI");
          return nullptr;
    }
}
