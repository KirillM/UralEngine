//
//  ImGuiLayer.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 22.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef ImGuiLayer_hpp
#define ImGuiLayer_hpp

#include "Layers/Layer.h"

#include "Events/ApplicationEvent.h"
#include "Events/Desktop/DesktopEvent.h"
#include "Events/Desktop/KeyEvent.h"
#include "Events/Desktop/MouseEvent.h"

#pragma GCC visibility push(default)

namespace Ural {

    class URAL_API ImGuiLayer: public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event& event);
    private:
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
        bool OnMouseMovedEvent(MouseMovedEvent& e);
        bool OnMouseScrolledEvent(MouseScrolledEvent& e);
        bool OnKeyPressedEvent(KeyPressedEvent& e);
        bool OnKeyReleasedEvent(KeyReleasedEvent& e);
        bool OnKeyTypedEvent(KeyTypedEvent& e);
        bool OnWindowResizedEvent(WindowResizeEvent& e);

    private:
        float m_Time = 0.0f;
    };
}

#pragma GCC visibility pop

#endif /* ImGuiLayer_hpp */
