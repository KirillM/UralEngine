//
//  RendererAPI.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 17.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef RendererAPI_h
#define RendererAPI_h

#include <glm/glm.hpp>
#include "Renderer/VertexArray.h"

namespace Ural {

    class RendererAPI
    {
    public:
        enum class API {
            None,
            OpenGLES,
            OpenGL,
            Vulkan,
            Direct3D
        };
    public:
        virtual void Init() = 0;
        virtual void SetClearColor(const glm::vec4& color) = 0;
        virtual void SetViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
        virtual void Clear() = 0;

        virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) = 0;

        inline static API GetAPI() { return  s_API; }
    private:
        static API s_API;
    };

}

#endif /* RendererAPI_h */
