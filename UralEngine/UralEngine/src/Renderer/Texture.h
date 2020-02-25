//
//  Texture.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 25.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

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

    class Texture2D : public Texture
    {
    public:
        static Texture2D* Create(const std::string& path);
    };
}

#pragma GCC visibility pop

#endif /* Texture_hpp */

