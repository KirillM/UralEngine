//
//  Renderer.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 18.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef Renderer_h
#define Renderer_h

#include "RenderCommand.h"
#include "Renderer/Shaders/Shader.h"
#include "VertexArray.h"
#include "Translations/OrthographicCamera.h"

namespace Ural {

    class Renderer
    {
    public:
        static void Init();
        static void OnWindowResize(uint32_t width, uint32_t height);

        static void BeginScene(OrthographicCamera& camera);
        static void EndScene();

        static void Submit( const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

       // inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
    private:
        struct SceneData
        {
            glm::mat4 ViewProjectionMatrix;
        };

        static SceneData* m_SceneData;
    };
}

#endif /* Renderer_h */
