//
//  Renderer.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 23.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include "RenderCommand.h"
#include "RendererAPI.h"

namespace Ural {
    class Renderer
    {
    public:
        static void BeginScene();
        static void EndScene();

        static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

        inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
    };
}

#endif /* Renderer_hpp */
