//
//  MobileApplication.hpp
//  UralEngine IOS
//
//  Created by Кирилл Мезрин on 14.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef MobileApplication_h
#define MobileApplication_h

#include "Core.h"
#include "Platform/Window/Window.h"
#include "Layers/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#pragma GCC visibility push(default)

namespace Ural {
    class URAL_API MobileApplication {
    public:
        MobileApplication();
        virtual ~MobileApplication();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }
    private:
        std::unique_ptr<Window> m_Window = nullptr;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

}

#pragma GCC visibility pop

#endif /* MobileApplication_hpp */
