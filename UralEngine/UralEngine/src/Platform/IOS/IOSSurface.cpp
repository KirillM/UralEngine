//
//  IOSSurface.cpp
//  UralEngine IOS
//
//  Created by Кирилл Мезрин on 14.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "IOSSurface.h"

#include "Ural/Core.h"
#include "Log/Log.h"

#include "Events/ApplicationEvent.h"
#include "Events/Mobile/MobileEvent.h"

namespace Ural {

    HandHeldSurface* HandHeldSurface::Create()
    {
        return new IOSSurface();
    }

    IOSSurface::IOSSurface()
    {
        Init();
    }

    IOSSurface::~IOSSurface()
    {
        ShutDown();
    };

    void IOSSurface::Init()
    {
        m_Data.Title = "test";
        m_Data.Width = 0;
        m_Data.Height = 0;
     }

    void IOSSurface::ShutDown()
    {

    }

    void IOSSurface::OnUpdate()
    {

    }

}
