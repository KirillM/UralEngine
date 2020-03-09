//
//  Sandbox2D.cpp
//  Sandbox
//
//  Created by Кирилл Мезрин on 07.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "Sandbox2D.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Platform/OpenGL/OpenGLShader.h"


Sandbox2D::Sandbox2D() : Layer("SandBox2D"), m_CameraController(1280.0f / 720.0f, true)
{

}

void Sandbox2D::OnAttach()
{
    m_Texture = Ural::Texture2D::Create(R"(assets/textures/texture.png)");
}

void Sandbox2D::OnDetach()
{

}

void Sandbox2D::OnUpdate(Ural::TimeStep ts)
{
    m_CameraController.OnUpdate(ts);

    Ural::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
    Ural::RenderCommand::Clear();

    Ural::Renderer2D::BeginScene(m_CameraController.GetCamera());

    Ural::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
    Ural::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
    Ural::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f}, { 10.0f, 10.0f }, m_Texture);

    Ural::Renderer2D::EndScene();
}

void Sandbox2D::OnEvent(Ural::Event& e)
{
    m_CameraController.OnEvent(e);
}
