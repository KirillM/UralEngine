//
//  MobileEvent.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 14.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef MobileEvent_h
#define MobileEvent_h

#include "Events/Event.h"

namespace Ural {
    class URAL_API SurfaceResizeEvent : public Event
    {
    public:
        SurfaceResizeEvent(unsigned int width, unsigned int height)
        : m_Width(width), m_Height(height) {};

        inline unsigned int GetWidth() const { return m_Width; }
        inline unsigned int GetHeight() const { return m_Height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "SurfaceResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(SurfaceResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    private:
        unsigned int m_Width, m_Height;
    };

    class URAL_API SurfaceDestroyEvent : public Event
    {
    public:
        SurfaceDestroyEvent() = default;
        EVENT_CLASS_TYPE(SurfaceDestroy)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}

#endif /* MobileEvent_h */
