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

namespace Surface {

    class URAL_API Window : public RenderArea
    {
    public:
        static Surface* Create();
    };
}

#endif /* Surface_h */
