//
//  OpenGLShader.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 14.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "OpenGLShader.h"

namespace Ural {

    static GLenum ShderTypeFromString(const std::string& type)
    {
        if (type == "vertex") return GL_VERTEX_SHADER;
        if (type == "fragment" || type == "pixel") return GL_FRAGMENT_SHADER;

        UL_CORE_ASSERT(false, "Unknown shader type!");
        return 0;
    }

    OpenGLShader::OpenGLShader(const std::string& filepath)
    {
        std::string source = ReadFile(filepath);
        auto shaderSources = PreProcess(source);
        Compile(shaderSources);

        auto lastSlash = filepath.find_last_of("/\\");
        lastSlash = lastSlash == std::string::npos ? 0 : lastSlash + 1;
        auto lastDot = filepath.rfind(".");
        auto count = lastDot == std::string::npos ? filepath.size() - lastSlash : lastDot - lastSlash;
        m_Name = filepath.substr(lastSlash, count);
    }

    OpenGLShader::OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc) : m_Name(name)
    {
        std::unordered_map<GLenum, std::string> sources;
        sources[GL_VERTEX_SHADER] = vertexSrc;
        sources[GL_FRAGMENT_SHADER] = fragmentSrc;
        Compile(sources);
    }

    OpenGLShader::~OpenGLShader()
    {

    }

}
