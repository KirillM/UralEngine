//
//  OpenGLShader.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 25.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "OpenGLShader.h"
#include <glm/gtc/type_ptr.hpp>
#include <fstream>
#include <glad/glad.h>

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
        glDeleteProgram(m_RendererID);
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

    void OpenGLShader::Compile(const std::unordered_map<GLenum, std::string>& shaderSources)
    {
        GLuint program = glCreateProgram();
        UL_CORE_ASSERT(shaderSources.size() <= 2, "Only 2 shaders supported !");
        int glSahderIDIndex = 0;
        std::array<GLenum, 2> glShaderIDs;

        for (auto& kv : shaderSources)
        {
            GLenum type = kv.first;
            const std::string& source = kv.second;

            GLuint shader = glCreateShader(type);

            const GLchar *sourceCstr = (const GLchar *)source.c_str();
              glShaderSource(shader, 1, &sourceCstr, 0);

              glCompileShader(shader);

              GLint isCompiled = 0;
              glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
              if(isCompiled == GL_FALSE)
              {
                  GLint maxLength = 0;
                  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

                  // The maxLength includes the NULL character
                  std::vector<GLchar> infoLog(maxLength);
                  glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

                  // We don't need the shader anymore.
                  glDeleteShader(shader);

                  // Use the infoLog as you see fit.
                  UL_CORE_ERROR("{0}", infoLog.data());
                  UL_CORE_ASSERT(false, "Shader compilation failure!");
                  // In this simple program, we'll just leave
                  break;
              }
            glAttachShader(program, shader);
            glShaderIDs[glSahderIDIndex++] = shader;
        }

         // Vertex and fragment shaders are successfully compiled.
         // Now time to link them together into a program.
         // Get a program object.
         m_RendererID = program;

         // Link our program
         glLinkProgram(program);

         // Note the different functions here: glGetProgram* instead of glGetShader*.
         GLint isLinked = 0;
         glGetProgramiv(program, GL_LINK_STATUS, (int *)&isLinked);
         if (isLinked == GL_FALSE)
         {
             GLint maxLength = 0;
             glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

             // The maxLength includes the NULL character
             std::vector<GLchar> infoLog(maxLength);
             glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

             // We don't need the program anymore.
             glDeleteProgram(program);

             for (auto id : glShaderIDs)
             {
                 glDeleteShader(id);
             }

             // Use the infoLog as you see fit.
             UL_CORE_ERROR("{0}", infoLog.data());
             UL_CORE_ASSERT(false, "Shader link filaure!");
             // In this simple program, we'll just leave
             return;
         }

         // Always detach shaders after a successful link.
        for (auto id : glShaderIDs)
        {
            glDetachShader(program, id);
        }
    }

    void OpenGLShader::Bind() const
    {
        glUseProgram(m_RendererID);
    }

    void OpenGLShader::UnBind() const
    {
        glUseProgram(0);
    }

    void OpenGLShader::UploadUniformInt(const std::string& name, int value)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniform1i(location, value);
    }

     void OpenGLShader::UploadUniformFloat(const std::string& name, float value)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniform1f(location, value);
    }
     void OpenGLShader::UploadUniformFloat2(const std::string& name, const glm::vec2& vector)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniform2f(location, vector.x, vector.y);
    }
     void OpenGLShader::UploadUniformFloat3(const std::string& name, const glm::vec3& vector)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniform3f(location, vector.x, vector.y, vector.z);
    }

    void OpenGLShader::UploadUniformFloat4(const std::string& name, const glm::vec4& vector)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
    }

     void OpenGLShader::UploadUniformMat3(const std::string& name, const glm::mat3& matrix)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShader::UploadUniformMat4(const std::string& name, const glm::mat4& matrix)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }
}

