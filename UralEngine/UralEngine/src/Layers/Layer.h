//
//  Layer.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 22.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef Layer_h
#define Layer_h

#include "Ural/Core.h"
#include "Events/Event.h"
#include "Time/TimeStep.h"

#pragma GCC visibility push(default)

namespace Ural {

    class URAL_API Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate(TimeStep ts) {}
        virtual void OnEvent(Event& event) {}

        inline const std::string& GetName() const { return m_DebugName; }
    protected:
        std::string m_DebugName;
    };
}

#pragma GCC visibility pop

#endif /* Layer_h */
