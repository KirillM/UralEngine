//
//  Renderer2D.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef Renderer2D_h
#define Renderer2D_h

#include "OrthographicCamera.h"
#include "Texture.h"

namespace Ural {
    class Renderer2D
    {
    public:
        static void Init();
        static void ShutDown();

        static void BeginScene(const OrthographicCamera& camera);
        static void EndScene();

        static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
        static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
        static void DrawQuad(const glm::vec2& position, const glm::vec2& size, Ref<Texture2D>& texture);
        static void DrawQuad(const glm::vec3& position, const glm::vec2& size, Ref<Texture2D>& texture);
    private:
    };
}

#endif /* Renderer2D_hpp */
