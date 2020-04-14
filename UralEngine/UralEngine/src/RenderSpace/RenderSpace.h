//
//  RenderArea.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 14.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef RenderArea_h
#define RenderArea_h

#include "Ural/Core.h"
#include "Events/Event.h"

namespace Ural {
    class URAL_API RenderSpace
    {
    public:
        using EventcallabckFn = std::function<void(Event&)>;

        virtual ~RenderSpace() = default;

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventcallabckFn& callback) = 0;
    };
}

#endif /* RenderArea_h */
