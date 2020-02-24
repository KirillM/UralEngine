//
//  RenderCommand.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 24.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef RenderCommand_h
#define RenderCommand_h

#include "RendererAPI.h"

namespace Ural {

    class RenderCommand
    {
    public:
        inline static void SetClearColor(const glm::vec4& color)
        {
            s_RendererAPI->SetClearColor(color);
        }

        inline static void Clear()
        {
            s_RendererAPI->Clear();
        }

        inline static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
        {
            s_RendererAPI->DrawIndexed(vertexArray);
        }
    private:
        static RendererAPI* s_RendererAPI;
    };

}

#endif /* RenderCommand_h */
