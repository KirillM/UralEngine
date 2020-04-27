//
//  OpenGLFullShader.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 17.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLFullShader_h
#define OpenGLFullShader_h

#include "Renderer/Shaders/Shader.h"
#include "OpenGLShader.h"

namespace Ural {

    class OpenGLMirrorShader : public Shader
    {
    public:
        OpenGLMirrorShader(const OpenGLShader& shader) : m_Shader(shader) {}
        ~OpenGLMirrorShader() = default;
    private:
        const OpenGLShader& m_Shader;
    };

}

#endif /* OpenGLFullShader_h */
