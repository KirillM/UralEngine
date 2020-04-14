//
//  IOSSurface.hpp
//  UralEngine IOS
//
//  Created by Кирилл Мезрин on 14.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef IOSSurface_h
#define IOSSurface_h

#include "RenderSpace/Surface.h"

namespace Ural {
    class IOSSurface : public Surface {
    public:
        IOSSurface();
        virtual ~IOSSurface();

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }

        inline void SetEventCallback(const EventcallabckFn& callback) override { m_Data.Callback = callback; };
    private:
        virtual void Init();
        virtual void ShutDown();
    private:

        struct SurfaceData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventcallabckFn Callback;
        };

        SurfaceData m_Data;
    };
}

#endif /* IOSSurface_h */
