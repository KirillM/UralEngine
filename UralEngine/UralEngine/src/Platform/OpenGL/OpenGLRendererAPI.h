//
//  OpenGLRendererAPI.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 24.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLRendererAPI_hpp
#define OpenGLRendererAPI_hpp

#include "Renderer/RendererAPI.h"

namespace Ural {
    class OpenGLRendererAPI : public RendererAPI
    {
    public:
        virtual void SetClearColor(const glm::vec4& color) override;
        virtual void Clear() override;

        virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
    };
}

#endif /* OpenGLRendererAPI_hpp */
