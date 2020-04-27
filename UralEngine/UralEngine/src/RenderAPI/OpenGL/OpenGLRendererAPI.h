//
//  OpenGLRendererAPI.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 27.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLRendererAPI_h
#define OpenGLRendererAPI_h

#include "Renderer/RendererAPI.h"

namespace Ural {
    class OpenGLRendererAPI : public RendererAPI
    {
    public:
        virtual void Init() override;
        virtual void SetClearColor(const glm::vec4& color) override;
        virtual void SetViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
        virtual void Clear() override;

        virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) override;
    };
}

#endif /* OpenGLRendererAPI_h */
