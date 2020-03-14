//
//  OpenGLShader.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 14.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLShader_h
#define OpenGLShader_h

namespace Ural {
    class OpenGLShader {
    public:
        Shader(const std::string& filepath);
        OpenGLShader::OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
        ~Shader();
    private:
        std::string ReadFile(const std::string& filepath);
        std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
        void Compile(const std::unordered_map<GLenum, std::string>& shaderSources);
    private:
        uint32_t m_RendererID;
        std::string m_Name;
    };
}

#endif /* OpenGLShader_hpp */
