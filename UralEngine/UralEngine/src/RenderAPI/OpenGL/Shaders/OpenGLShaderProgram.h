//
//  OpenGLShaderProgram.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 16.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLShaderProgram_h
#define OpenGLShaderProgram_h

#include "RenderAPI/OpenGL/OpenGLAPI.h"
#include "OpenGLShaderSlot.h"

namespace Ural {
    class OpenGLShaderProgram {
    public:
        ~OpenGLShaderProgram();

        void UseProgram() const;
        void StopProgram() const;

        void AttachShaderSlot(const Ref<OpenGLShaderSlot> shaderSlot);
        void DetachShaderSlot();

        bool IsValid() const;

        void Compile() const;
    public:
        GLuint m_ProgramID;
    private:
        inline static void Log(GLuint programID);
    private:
        Ref<OpenGLShaderSlot> m_ShaderSlot;
    };
}

#endif /* OpenGLShaderProgram_h */
