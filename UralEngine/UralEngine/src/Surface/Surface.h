//
//  Surface.h
//  UralEngine IOS
//
//  Created by Кирилл Мезрин on 14.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef Surface_h
#define Surface_h

//#include "Ural/Core.h"
//#include "RenderSpace.h"
//
//namespace Ural {
//
//    class URAL_API Surface : public RenderSpace
//    {
//    public:
//        static Surface* Create();
//    };
//}

#include "Ural/Core.h"
#include "Events/Event.h"

namespace Ural {
    class URAL_API Surface
    {
    public:
        using EventcallabckFn = std::function<void(Event&)>;

        virtual ~Surface() = default;

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventcallabckFn& callback) = 0;
    };
}

#endif /* Surface_h */
