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
#include "Renderer/Shaders/ShaderProgram.h"
#include "OpenGLShaderSlot.h"

namespace Ural {
    class OpenGLShaderProgram : public ShaderProgram {
    public:
        OpenGLShaderProgram() = default;
        OpenGLShaderProgram(const std::vector<char> binaryProgram, GLenum binaryFormat);
        ~OpenGLShaderProgram();

        void LoadBinaryProgram(const std::vector<char> binaryProgram, GLenum binaryFormat);

        void UseProgram() const;
        void StopProgram() const;
        inline GLuint GetProgram() const { return m_ProgramID; }

        void AttachShaderSlot(const Ref<OpenGLShaderSlot> shaderSlot);
        void DetachShaderSlot();

        bool IsValid() const;

        void CompileAndLink() const;
        void Compile() const;
        void Link() const;

    private:
        inline static void Log(GLuint programID);
    private:
        GLuint m_ProgramID;
        Ref<OpenGLShaderSlot> m_ShaderSlot;
    };
}

#endif /* OpenGLShaderProgram_h */
