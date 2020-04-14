//
//  DesktopApplication.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 14.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef DesktopApplication_h
#define DesktopApplication_h

#include "Ural/Core.h"
#include "Ural/Application.h"
#include "RenderArea/Window.h"
#include "Layers/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/Desktop/DesktopEvent.h"

#pragma GCC visibility push(default)

namespace Ural {
    class URAL_API DesktopApplication : public Application {
    public:
        DesktopApplication();
        virtual ~DesktopApplication();

        virtual void Run() override;

        virtual void OnEvent(Event& e) override;

        virtual void PushLayer(Layer* layer) override;
        virtual void PushOverlay(Layer* layer) override;

        static inline DesktopApplication& Get() { return static_cast<DesktopApplication&>(Application::Get()); }
        inline Window& GetWindow() { return *m_Window; }

    private:
        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);
        std::unique_ptr<Window> m_Window = nullptr;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };
}

#pragma GCC visibility pop

#endif /* DesktopApplication_hpp */
