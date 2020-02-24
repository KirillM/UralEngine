//
//  Shader.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 23.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef Shader_h
#define Shader_h

namespace Ural {

    class Shader
    {
    public:
        virtual ~Shader() = default;

        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;

        static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);
    };
}

#endif /* Shader_h */
