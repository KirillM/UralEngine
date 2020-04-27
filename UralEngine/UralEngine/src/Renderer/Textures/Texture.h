//
//  Texture.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 27.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef Texture_h
#define Texture_h

#pragma GCC visibility push(default)

namespace Ural {
    class Texture
    {
    public:
        virtual ~Texture() = default;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        virtual void Bind(uint32_t slot = 0) const = 0;
    };
}

#pragma GCC visibility pop

#endif /* Texture_h */
