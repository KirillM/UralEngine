//
//  Texture2D.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 27.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef Texture2D_h
#define Texture2D_h

#include "Texture.h"

#pragma GCC visibility push(default)

namespace Ural {

    class Texture2D : public Texture
    {
    public:
        static Ref<Texture2D> Create(const std::string& path);
    };

}

#pragma GCC visibility pop

#endif /* Texture2D_h */
