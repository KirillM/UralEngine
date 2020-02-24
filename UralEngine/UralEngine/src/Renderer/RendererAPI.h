//
//  RendererAPI.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 24.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef RendererAPI_hpp
#define RendererAPI_hpp

#include <glm/glm.hpp>
#include "VertexArray.h"

namespace Ural {
    class RendererAPI
    {
    public:
        enum class API
         {
             None = 0,
             OpenGL = 1
         };
    public:
        virtual void SetClearColor(const glm::vec4& color) = 0;
        virtual void Clear() = 0;

        virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

        inline static API GetAPI() { return  s_API; }
    private:
        static API s_API;
    };

}

#endif /* RendererAPI_hpp */
