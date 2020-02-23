//
//  Application.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 01/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log/Log.h"
#include <glad/glad.h>

#include "Input/Input.h"
#include <glm/glm.hpp>

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Ural {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application* Application::s_Instance = nullptr;

	Application::Application()
	
	{
        UL_CORE_ASSERT(!s_Instance, "Application already exists !");
        s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));


        m_VertexArray.reset(VertexArray::Create());

        float vertices[7 * 3] = {
             -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
             0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
             0.0f, 0.5f, 0.0f,  1.0f, 1.0f, 0.0f, 1.0f
         };

        m_VertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

        BufferLayout layout = {
            { ShaderDataType::Float3, "a_Position" },
            { ShaderDataType::Float4, "a_Color" }
            // { ShaderDataType::Float3, "a_Normal" }
        };

        m_VertexBuffer->SetLayout(layout);
        m_VertexArray->AddVertexBuffer(m_VertexBuffer);

        unsigned int indices[3] = {0, 1, 2};
        m_IndexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
        m_VertexArray->AddIndexBuffer(m_IndexBuffer);


        m_SquareVA.reset(VertexArray::Create());

        float squareVertices[3 * 4] = {
             -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.5f, 0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f
        };

        std::shared_ptr<VertexBuffer> squareVB;
        squareVB.reset(VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

        BufferLayout squareVBlayout = {
               { ShaderDataType::Float3, "a_Position" },
           };

           squareVB->SetLayout(squareVBlayout);
           m_SquareVA->AddVertexBuffer(squareVB);

        unsigned int squareIndices[6] = {0, 1, 2, 2, 3, 0};
        std::shared_ptr<IndexBuffer> squareIB;
        squareIB.reset(IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));

        m_SquareVA->AddIndexBuffer(squareIB);

        std::string vertexSrc = R"(
            #version 330 core

            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec4 a_Color;

            out vec3 v_Position;
            out vec4 v_Color;

            void main()
            {
                v_Position = a_Position;
                v_Color = a_Color;
                gl_Position = vec4(a_Position, 1.0);
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

        m_Shader.reset(new Shader(vertexSrc, fragmentSrc));


        std::string blueShaderVertexSrc = R"(
                  #version 330 core

                  layout(location = 0) in vec3 a_Position;

                  out vec3 v_Position;

                  void main()
                  {
                      v_Position = a_Position;
                      gl_Position = vec4(a_Position, 1.0);
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

        m_BlueShader.reset(new Shader(blueShaderVertexSrc, blueShaderFragmentSrc));

	}

	Application::~Application()
	{
		
	}

	void Application::OnEvent(Event& e)
	{        
		UL_CORE_INFO("event {0}", e);

        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

        UL_CORE_TRACE("{0}", e);

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
        {
            (*--it)->OnEvent(e);
            if (e.m_Handled)
                break;
        }
	}

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        m_Running = false;
        return true;
    }
		
	void Application::Run()
	{		
		while (m_Running)
		{
            glClearColor(0.1f, 0.1f, 0.1f, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            m_BlueShader->Bind();
            m_SquareVA->Bind();
            glDrawElements(GL_TRIANGLES, m_SquareVA->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

            m_Shader->Bind();
            m_VertexArray->Bind();
            glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();

            //std::pair<float, float> position = Input::GetMousePosition();
            //UL_CORE_TRACE("{0}, {1}", std::get<0>(position), std::get<1>(position));

			m_Window->OnUpdate();
		}
	}

    void Application::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer *layer)
    {
        m_LayerStack.PushOverlay(layer);
    }
}
