//
//  Renderer.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 18.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "Renderer.h"
#include "RenderAPI/OpenGL/Shaders/OpenGLShader.h"

namespace Ural {

    Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData;

    void Renderer::Init()
    {
      //  RenderCommand::Init();
      //  Renderer2D::Init();
    }

    void Renderer::OnWindowResize(uint32_t width, uint32_t height)
    {
      //  RenderCommand::SetViewPort(0, 0, width, height);
    }

    void Renderer::BeginScene(OrthographicCamera& camera)
    {
        m_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
    }

    void Renderer::EndScene()
    {

    }

    void Renderer::Submit(const Ref<Shader>&shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform)
    {
        shader->Bind();
        std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
        std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_Transform", transform);

        vertexArray->Bind();
        //RenderCommand::DrawIndexed(vertexArray);
    }
}
