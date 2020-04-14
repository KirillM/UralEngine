//
//  RenderArea.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 14.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef RenderArea_h
#define RenderArea_h

#include "Events/Event.h"
class Event;
class URAL_API RenderArea
{
public:
    using EventcallabckFn = std::function<void(Event&)>;

    virtual ~RenderArea() = default;

    virtual void OnUpdate() = 0;

    virtual unsigned int GetWidth() const = 0;
    virtual unsigned int GetHeight() const = 0;

    virtual void SetEventCallback(const EventcallabckFn& callback) = 0;

  //  static Window* Create(const WindowsProps& props = WindowsProps());
};

#endif /* RenderArea_h */
