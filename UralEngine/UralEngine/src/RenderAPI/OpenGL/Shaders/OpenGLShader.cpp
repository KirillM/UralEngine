//
//  OpenGLShader.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 16.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "OpenGLShader.h"
#include <glm/gtc/type_ptr.hpp>
#include <fstream>

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
        CompileAndLink(shaderSources[GL_VERTEX_SHADER], shaderSources[GL_FRAGMENT_SHADER]);

        auto lastSlash = filepath.find_last_of("/\\");
        lastSlash = lastSlash == std::string::npos ? 0 : lastSlash + 1;
        auto lastDot = filepath.rfind(".");
        auto count = lastDot == std::string::npos ? filepath.size() - lastSlash : lastDot - lastSlash;
        m_Name = filepath.substr(lastSlash, count);
    }

    OpenGLShader::OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc) : m_Name(name)
    {
        CompileAndLink(vertexSrc, fragmentSrc);
    }

    OpenGLShader::OpenGLShader(const std::vector<char> binaryShaderOrProgram, GLenum binaryFormat, bool isBinaryProgram)
    {
        if (isBinaryProgram)
        {
            LoadBinaryProgram(binaryShaderOrProgram, binaryFormat);
        }
        else
        {
            LinkBinaryShader(binaryShaderOrProgram, binaryFormat);
        }
    }

    std::string OpenGLShader::ReadFile(const std::string& filepath)
    {
        std::string result;
        std::ifstream in(filepath, std::ios::in | std::ios::binary);
        if (in)
        {
            in.seekg(0, std::ios::end);
            result.resize(in.tellg());
            in.seekg(0, std::ios::beg);
            in.read(&result[0], result.size());
            in.close();
        }
        else
        {
            UL_CORE_ERROR("Cpuld not open file '{0}'", filepath);
        }

        return result;
    }

    std::unordered_map<GLenum, std::string> OpenGLShader::PreProcess(const std::string& source)
    {
        std::unordered_map<GLenum, std::string> shaderSources;

        const char* typeToken = "#type";
        size_t typeTokenLenght = strlen(typeToken);
        size_t pos = source.find(typeToken, 0);
        while (pos != std::string::npos)
        {
            size_t eol = source.find_first_of("\r\n", pos);
            UL_CORE_ASSERT(eol != std::string::npos, "Syntax error");
            size_t begin = pos + typeTokenLenght + 1;
            std::string type = source.substr(begin, eol - begin);
            UL_CORE_ASSERT(type == "vertex" || type == "fragment" || type == "pixel", "Invalid shader type specification");

            size_t nextLinePos = source.find_first_not_of("\r\n", eol);
            pos = source.find(typeToken, nextLinePos);
            shaderSources[ShderTypeFromString(type)] = source.substr(nextLinePos,
                                                                     pos - (nextLinePos == std::string::npos ? source.size() - 1: nextLinePos));
        }
        return shaderSources;
    }

    void OpenGLShader::CompileAndLink(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        m_ShaderSlot = std::make_shared<OpenGLShaderSlot>(vertexSrc, fragmentSrc);
        m_ShaderProgram = std::make_unique<OpenGLShaderProgram>();
        m_ShaderProgram->AttachShaderSlot(m_ShaderSlot);
        m_ShaderProgram->CompileAndLink();
    }

    void OpenGLShader::LinkBinaryShader(const std::vector<char> binaryShader, GLenum binaryFormat)
    {
        m_ShaderSlot = std::make_shared<OpenGLShaderSlot>(binaryShader, binaryFormat);
        m_ShaderProgram = std::make_unique<OpenGLShaderProgram>();
        m_ShaderProgram->AttachShaderSlot(m_ShaderSlot);
        m_ShaderProgram->Link();
    }

    void OpenGLShader::LoadBinaryProgram(const std::vector<char> binaryProgram, GLenum binaryFormat)
    {
        m_ShaderProgram = std::make_unique<OpenGLShaderProgram>(binaryProgram, binaryFormat);
    }

    void OpenGLShader::Bind() const
    {
        m_ShaderProgram->UseProgram();
    }

    void OpenGLShader::UnBind() const
    {
        m_ShaderProgram->StopProgram();
    }

    void OpenGLShader::SetInt(const std::string& name, int value)
    {
        UploadUniformInt(name, value);
    }

    void OpenGLShader::SetMat4(const std::string& name, const glm::mat4& value)
    {
        UploadUniformMat4(name, value);
    }

    void OpenGLShader::SetFloat4(const std::string& name, const glm::vec4& value)
    {
        UploadUniformFloat4(name, value);
    }

    void OpenGLShader::SetFloat3(const std::string& name, const glm::vec3& value)
    {
        UploadUniformFloat3(name, value);
    }

    void OpenGLShader::UploadUniformInt(const std::string& name, int value)
    {
        GLint location = glGetUniformLocation(m_ShaderProgram->ProgramID, name.c_str());
        glUniform1i(location, value);
    }

     void OpenGLShader::UploadUniformFloat(const std::string& name, float value)
    {
        GLint location = glGetUniformLocation(m_ShaderProgram->ProgramID, name.c_str());
        glUniform1f(location, value);
    }
     void OpenGLShader::UploadUniformFloat2(const std::string& name, const glm::vec2& vector)
    {
        GLint location = glGetUniformLocation(m_ShaderProgram->ProgramID, name.c_str());
        glUniform2f(location, vector.x, vector.y);
    }
     void OpenGLShader::UploadUniformFloat3(const std::string& name, const glm::vec3& vector)
    {
        GLint location = glGetUniformLocation(m_ShaderProgram->ProgramID, name.c_str());
        glUniform3f(location, vector.x, vector.y, vector.z);
    }

    void OpenGLShader::UploadUniformFloat4(const std::string& name, const glm::vec4& vector)
    {
        GLint location = glGetUniformLocation(m_ShaderProgram->ProgramID, name.c_str());
        glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
    }

     void OpenGLShader::UploadUniformMat3(const std::string& name, const glm::mat3& matrix)
    {
        GLint location = glGetUniformLocation(m_ShaderProgram->ProgramID, name.c_str());
        glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShader::UploadUniformMat4(const std::string& name, const glm::mat4& matrix)
    {
        GLint location = glGetUniformLocation(m_ShaderProgram->ProgramID, name.c_str());
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

}

