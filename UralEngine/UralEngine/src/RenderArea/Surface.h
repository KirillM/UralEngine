//
//  Surface.h
//  UralEngine IOS
//
//  Created by Кирилл Мезрин on 14.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef Surface_h
#define Surface_h

#include "Ural/Core.h"
#include "RenderArea.h"

namespace Ural {

    class URAL_API Surface : public RenderArea
    {
    public:
        static Surface* Create();
    };
}

#endif /* Surface_h */
