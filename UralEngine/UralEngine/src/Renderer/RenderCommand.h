//
//  RenderCommand.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 17.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef RenderCommand_h
#define RenderCommand_h

#include "RendererAPI.h"

#pragma GCC visibility push(default)

namespace Ural {

    class RenderCommand
    {
    public:
        inline static void Init()
        {
            s_RendererAPI->Init();
        }

        inline static void SetClearColor(const glm::vec4& color)
        {
            s_RendererAPI->SetClearColor(color);
        }

        inline static void Clear()
        {
            s_RendererAPI->Clear();
        }

        inline static void DrawIndexed(const Ref<VertexArray>& vertexArray)
        {
            s_RendererAPI->DrawIndexed(vertexArray);
        }

        inline static void SetViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
        {
            s_RendererAPI->SetViewPort(x, y, width, height);
        }
    private:
        static RendererAPI* s_RendererAPI;
    };

}

#pragma GCC visibility pop

#endif /* RenderCommand_h */
