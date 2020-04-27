//
//  main.cpp
//  Sandbox
//
//  Created by Кирилл Мезрин on 30/11/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#include "Ural.h"

class ExampleLayer: public Ural::Layer
{
public:
    ExampleLayer() : Layer("Example")
    {
        glClearColor(1, 0, 0, 1);
    }

    void OnUpdate(Ural::TimeStep ts) override
    {
       // UL_INFO("ExampleLayer::Update");
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
       // Error::PrintError();

        m_SquareVA = Ural::VertexArray::Create();

           float squareVertices[7 * 4] = {
               -0.6f, -0.5f, 0.0f, 1.0f, 0.3f, 0.5f, 1.0f,
               0.8f, -0.5f, 0.0f, 1.0f, 0.3f, 0.5f, 1.0f,
               0.5f, 0.5f, 0.0f, 1.0f, 0.3f, 0.5f, 1.0f,
               -0.5f, 0.5f, 0.0f, 1.0f, 0.3f, 0.5f, 1.0f
           };


        Ural::Ref<Ural::VertexBuffer> squareVB = Ural::VertexBuffer::Create(squareVertices, sizeof(squareVertices));
//        Error::PrintError();

           Ural::BufferLayout squareVBlayout = {
                  { Ural::ShaderDataType::Float3, "a_Position" },
                  { Ural::ShaderDataType::Float4, "a_Color" }
            };
        squareVB->SetLayout(squareVBlayout);
        m_SquareVA->AddVertexBuffer(squareVB);

        uint32_t squareIndices[6] = {2, 3, 0, 0, 1, 2};//{0, 1, 2, 2, 3, 0};
        Ural::Ref<Ural::IndexBuffer> squareIB = Ural::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
 //       Error::PrintError();
        m_SquareVA->AddIndexBuffer(squareIB);
        m_SquareVA->Bind();
//        Error::PrintError();

          const std::string vShaderText = R"(
             #version 300 es
             layout(location = 0) in vec3 a_Position;
             layout(location = 1) in vec4 a_Color;

             out vec4 v_Color;

             void main(void) {
                 gl_Position = vec4(a_Position, 1.0);
                 v_Color = a_Color;
             })";
        const std::string pShaderText = R"(
            #version 300 es
            precision mediump float;
             layout(location = 0) out vec4 v_FragColor;
             in vec4 v_Color;

             void main(void) {
                 v_FragColor = v_Color;
             })";

        const std::string name = "test";
        m_Shader = Ural::Shader::Create("test", vShaderText, pShaderText);
        m_Shader->Bind();
//        Error::PrintError();
//
//        ShaderCompiler::CurrentProgram();
//        GraphicsDeviceInfo::PrintInfo();
    }

    void OnEvent(Ural::Event& event) override
    {
       // UL_TRACE("{0}", event);
    }
private:
    Ural::Ref<Ural::VertexArray> m_SquareVA;
    Ural::Ref<Ural::Shader> m_Shader;
  //  Ural::OrthographicCameraController m_CameraController;
};

class Sandbox : public Ural::MobileApplication
{
public:
    Sandbox()
    {
        PushOverlay(new ExampleLayer());
     //  PushOverlay(new Ural::ImGuiLayer());
    }

    ~Sandbox()
    {

    }
};

//Ural::Application* Ural::CreateApplication()
//{
//    return new Sandbox();
//}

