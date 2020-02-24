//
//  main.cpp
//  Sandbox
//
//  Created by Кирилл Мезрин on 30/11/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include "Ural.h"

/*
 I disagree that simd math is absolutely necessary. It is simply not true that simd math is way faster in a huge and complex engine. There are a couple reasons for that. First, to make full use of simd, data needs to be stored in these registers as long as possible, which is often not the case. Second, simd sse data needs to be 16 byte aligned which can also decrease performance, e.g. because now you have to load more data in the cache than before and if you forgot to manually align it, it will be even slower. Yes the actual calculations are faster than non-simd, but simd is not the holy grail of graphics programming. And now the reason why i tell you this. Last year i thought exactly the same, because everyone teaches it. Now, i work with the guys who created the cryengine and did farcry, crysis etc. and they are not even using simd math. Back when they tried it it was actually slower in their engine. Another thing i want to mention is to have the abilitiy to question everything. Today, computer graphics is taught exclusively using matrix math. Guess what? Cryengine does not use it except in a few cases (Mainly for projection). Matrices are slow and have to much unnecessary data. I would argue that replacing matrices with something else (we use dual-quats and qtangents) it is way faster than using simd math. Have a nice day! :)

 34



 */

//#include <glm/glm.hpp>

class ExampleLayer: public Ural::Layer
{
public:
    ExampleLayer() : Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
    {
        m_VertexArray.reset(Ural::VertexArray::Create());

            float vertices[7 * 3] = {
                 -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
                 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
                 0.0f, 0.5f, 0.0f,  0.8f, 0.8f, 0.2f, 1.0f
             };

            std::shared_ptr<Ural::VertexBuffer> m_VertexBuffer;
            m_VertexBuffer.reset(Ural::VertexBuffer::Create(vertices, sizeof(vertices)));

            Ural::BufferLayout layout = {
                { Ural::ShaderDataType::Float3, "a_Position" },
                { Ural::ShaderDataType::Float4, "a_Color" }
                // { ShaderDataType::Float3, "a_Normal" }
            };

            m_VertexBuffer->SetLayout(layout);
            m_VertexArray->AddVertexBuffer(m_VertexBuffer);

            unsigned int indices[3] = {0, 1, 2};

            std::shared_ptr<Ural::IndexBuffer> m_IndexBuffer;
            m_IndexBuffer.reset(Ural::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
            m_VertexArray->AddIndexBuffer(m_IndexBuffer);


            m_SquareVA.reset(Ural::VertexArray::Create());

            float squareVertices[3 * 4] = {
                 -0.75f, -0.75f, 0.0f,
                 0.75f, -0.75f, 0.0f,
                 0.75f, 0.75f, 0.0f,
                -0.75f, 0.75f, 0.0f
            };

            std::shared_ptr<Ural::VertexBuffer> squareVB;
            squareVB.reset(Ural::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

            Ural::BufferLayout squareVBlayout = {
                   { Ural::ShaderDataType::Float3, "a_Position" },
               };

               squareVB->SetLayout(squareVBlayout);
               m_SquareVA->AddVertexBuffer(squareVB);

            unsigned int squareIndices[6] = {0, 1, 2, 2, 3, 0};
            std::shared_ptr<Ural::IndexBuffer> squareIB;
            squareIB.reset(Ural::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));

            m_SquareVA->AddIndexBuffer(squareIB);

            std::string vertexSrc = R"(
                #version 330 core

                layout(location = 0) in vec3 a_Position;
                layout(location = 1) in vec4 a_Color;

                uniform mat4 u_ViewProjection;
                out vec3 v_Position;
                out vec4 v_Color;

                void main()
                {
                    v_Position = a_Position;
                    v_Color = a_Color;
                    gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
                }
            )";

            std::string fragmentSrc = R"(
                #version 330 core

                layout(location = 0) out vec4 color;
                in vec3 v_Position;
                in vec4 v_Color;

                void main()
                {
                    color = vec4(v_Position * 0.5 + 0.5, 1.0);
                    color = v_Color;
                }
            )";

            m_Shader.reset(new Ural::Shader(vertexSrc, fragmentSrc));


            std::string blueShaderVertexSrc = R"(
                      #version 330 core

                      layout(location = 0) in vec3 a_Position;

                      uniform mat4 u_ViewProjection;
                      out vec3 v_Position;

                      void main()
                      {
                          v_Position = a_Position;
                          gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
                      }
                  )";

                  std::string blueShaderFragmentSrc = R"(
                      #version 330 core

                      layout(location = 0) out vec4 color;
                      in vec3 v_Position;

                      void main()
                      {
                          color = vec4(0.2, 0.3, 0.8, 1.0);
                      }
                  )";

            m_BlueShader.reset(new Ural::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
    }

    void OnUpdate(Ural::TimeStep ts) override
    {
       // UL_INFO("ExampleLayer::Update");
        UL_TRACE("Delta time: {0}s", ts.GetSeconds());
        if (Ural::Input::IsKeyPressed(UL_KEY_LEFT))
        {
            m_CameraPosition.x -= m_CameraMoveSpeed * ts;
        } else if (Ural::Input::IsKeyPressed(UL_KEY_RIGHT))
        {
            m_CameraPosition.x += m_CameraMoveSpeed * ts;
        }

        if (Ural::Input::IsKeyPressed(UL_KEY_UP))
        {
            m_CameraPosition.y += m_CameraMoveSpeed * ts;
        } else if (Ural::Input::IsKeyPressed(UL_KEY_DOWN))
        {
            m_CameraPosition.y -= m_CameraMoveSpeed * ts;
        }

        if (Ural::Input::IsKeyPressed(UL_KEY_A))
        {
            m_CameraRotation += m_CameraRotationSpeed * ts;
        }

        if (Ural::Input::IsKeyPressed(UL_KEY_D))
        {
            m_CameraRotation -= m_CameraRotationSpeed * ts;
        }

        if(Ural::Input::IsKeyPressed(UL_KEY_TAB))
            UL_INFO("Tab key is pressed!");

        Ural::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
        Ural::RenderCommand::Clear();

        m_Camera.SetPostion(m_CameraPosition);
        m_Camera.SetRotation(m_CameraRotation);

        Ural::Renderer::BeginScene(m_Camera);

        Ural::Renderer::Submit(m_BlueShader, m_SquareVA);
        Ural::Renderer::Submit(m_Shader, m_VertexArray);

        Ural::Renderer::EndScene();
    }

    void OnEvent(Ural::Event& event) override
    {
        Ural::EventDispatcher dispathcer(event);
        dispathcer.Dispatch<Ural::KeyPressedEvent>(UL_BIND_EVENT_FN(ExampleLayer::OnKeyPressedEvent));
       // UL_TRACE("{0}", event);
    }

    bool OnKeyPressedEvent(Ural::KeyPressedEvent& event)
    {
//        if (event.GetKeyCode() == UL_KEY_LEFT)
//        {
//            m_CameraPosition.x -= m_CameraSpeed;
//        }
//
//        if (event.GetKeyCode() == UL_KEY_RIGHT)
//        {
//            m_CameraPosition.x += m_CameraSpeed;
//        }
//
//        if (event.GetKeyCode() == UL_KEY_UP)
//        {
//            m_CameraPosition.y += m_CameraSpeed;
//        }
//
//        if (event.GetKeyCode() == UL_KEY_DOWN)
//        {
//            m_CameraPosition.y -= m_CameraSpeed;
//        }

        return false;
    }

private:
    std::shared_ptr<Ural::Shader> m_Shader;
    std::shared_ptr<Ural::Shader> m_BlueShader;
    std::shared_ptr<Ural::VertexArray> m_VertexArray;
    std::shared_ptr<Ural::VertexArray> m_SquareVA;

    Ural::OrthographicCamera m_Camera;
    glm::vec3 m_CameraPosition;
    float m_CameraRotation = 0.0f;
    float m_CameraMoveSpeed = 5.0f;
    float m_CameraRotationSpeed = 180.1f;
};

class Sandbox : public Ural::Application
{
public:
    Sandbox()
    {
        PushOverlay(new ExampleLayer());
        PushOverlay(new Ural::ImGuiLayer());
    }

    ~Sandbox()
    {

    }
};

Ural::Application* Ural::CreateApplication()
{
	return new Sandbox();
}
