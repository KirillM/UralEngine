//
//  Application.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 01/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#ifndef Application_h
#define Application_h

#include "Core.h"
#include "Platform/Window/Window.h"
#include "Layers/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include "Renderer/Shader.h"
#include "Renderer/Buffer.h"
#include "Renderer/VertexArray.h"

#pragma GCC visibility push(default)

namespace Ural {
	class URAL_API Application {
	public:
		Application();
		virtual ~Application();
		
		void Run();
		
		void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        static inline Application& Get() { return *s_Instance; }
        inline Window& GetWindow() { return *m_Window; }
	private:
        bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window = nullptr;
		bool m_Running = true;
        LayerStack m_LayerStack;

        std::shared_ptr<Shader> m_Shader;
        std::shared_ptr<Shader> m_BlueShader;
        std::shared_ptr<VertexArray> m_VertexArray;
        std::shared_ptr<VertexBuffer> m_VertexBuffer;
        std::shared_ptr<IndexBuffer> m_IndexBuffer;

        std::shared_ptr<VertexArray> m_SquareVA;
    private:
        static Application* s_Instance;
	};

	// Реализована в клиенте
	Application *CreateApplication();
}

#pragma GCC visibility pop

#endif /* Application_h */
