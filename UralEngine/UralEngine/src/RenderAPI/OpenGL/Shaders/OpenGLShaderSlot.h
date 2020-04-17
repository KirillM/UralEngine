//
//  OpenGLShaderSlot.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 16.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLShaderSlot_h
#define OpenGLShaderSlot_h

#include "RenderAPI/OpenGL/OpenGLAPI.h"

namespace Ural {
    struct OpenGLShaderSlot {
        OpenGLShaderSlot(const std::string& vertexShaderSrc, const std::string& fragmentShaderSrc);
        OpenGLShaderSlot(const std::vector<char> binaryShader, GLenum binaryFormat);
        ~OpenGLShaderSlot();

        void Compile() const;
        bool IsValid() const;
        void PrintSource() const;

        GLuint m_VertexShaderID;
        GLuint m_FragmentShaderID;
    private:
        inline static void Log(GLuint shaderID);
    };
}

#endif /* OpenGLShaderSlot_h */
