//
//  HandHeldSurface.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 15.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef HandHeldSurface_h
#define HandHeldSurface_h

#include "Ural/Core.h"
#include "Surface/OnScreenSurface.h"

namespace Ural {

    class URAL_API HandHeldSurface : public OnScreenSurface
    {
    public:
        static HandHeldSurface* Create();
    };
}

#endif /* HandHeldSurface_h */
