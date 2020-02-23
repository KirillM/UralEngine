//
//  Shader.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 23.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

//#include <string>

namespace Ural {
    class Shader
    {
    public:
        Shader(const std::string& vertexSrc, std::string& fragmentSrc);
        ~Shader();

        void Bind() const;
        void UnBind() const;
    private:
        uint32_t m_RendererID;
    };
}

#endif /* Shader_hpp */
