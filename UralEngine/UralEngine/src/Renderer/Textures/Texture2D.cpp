//
//  Texture2D.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 27.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "Texture2D.h"
#include "Renderer/RendererAPI.h"
#include "RenderAPI/OpenGL/Textures/OpenGLTexture2D.h"

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
