//
//  MobileApplication.hpp
//  UralEngine IOS
//
//  Created by Кирилл Мезрин on 14.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef MobileApplication_h
#define MobileApplication_h

#include "Ural/Core.h"
#include "Ural/Application.h"
#include "Surface/Device/HandHeldSurface.h"
#include "Layers/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include "RenderAPI/OpenGL/Shaders/OpenGLShader.h"

#pragma GCC visibility push(default)

namespace Ural {
    class URAL_API MobileApplication : public Application {
    public:
        MobileApplication();
        virtual ~MobileApplication();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline HandHeldSurface& GetSurface() { return *m_Surface; }
    private:
        std::unique_ptr<HandHeldSurface> m_Surface = nullptr;
        Ref<Shader> m_Shader = nullptr;
        LayerStack m_LayerStack;
    };

}

#pragma GCC visibility pop

#endif /* MobileApplication_h */
