//
//  OpenGLShaderSlot.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 16.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "OpenGLShaderSlot.h"

namespace Ural {
    OpenGLShaderSlot::OpenGLShaderSlot(const std::string& vertexShaderSrc, const std::string& fragmentShaderSrc)
    {
        const GLchar *vertexShaderSrcCstr = (const GLchar *)vertexShaderSrc.c_str();
        const GLchar *fragmentShaderSrcCstr = (const GLchar *)fragmentShaderSrc.c_str();

        UL_CORE_ASSERT(vertexShaderSrcCstr && fragmentShaderSrcCstr, "Must be 2 shaders !");

        VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

        /*
         string:
         the number of shader source strings. A shader can be
         composed of a number of source strings, although each
         shader can have only one main function.
         */

        /*
         length:
         pointer to an array of count integers that holds the size of
         each respective shader string. If length is NULL, the shader
         strings are assumed to be null terminated. If length is not
         NULL, then each element of length holds the number of
         characters in the corresponding shader in the string array.
         If the value of length for any element is less than zero, then
         that string is assumed to be null terminated.
         */

        glShaderSource(VertexShaderID, 1, &vertexShaderSrcCstr, NULL);
        glShaderSource(FragmentShaderID, 1, &fragmentShaderSrcCstr, NULL);
    }

    OpenGLShaderSlot::OpenGLShaderSlot(const std::vector<char> binaryShader, GLenum binaryFormat)
    {
        VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        glShaderBinary(1, &VertexShaderID, binaryFormat, binaryShader.data(), (GLsizei)binaryShader.size());

        GLint isVertexShaderCompiled = 0;
        glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &isVertexShaderCompiled);


        if (isVertexShaderCompiled == GL_FALSE)
        {
            Log(VertexShaderID);
        }
    }

    OpenGLShaderSlot::~OpenGLShaderSlot()
    {
        glDeleteShader(VertexShaderID);
        glDeleteShader(FragmentShaderID);
    }

    void OpenGLShaderSlot::Compile() const
    {
        glCompileShader(VertexShaderID);
        glCompileShader(FragmentShaderID);

        GLint isVertexShaderCompiled = 0;
        glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &isVertexShaderCompiled);


        if (isVertexShaderCompiled == GL_FALSE)
        {
            Log(VertexShaderID);
        }

        GLint isFragmentShaderCompiled = 0;
        glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &isFragmentShaderCompiled);


        if (isFragmentShaderCompiled == GL_FALSE)
        {
            Log(FragmentShaderID);
        }

        if (isVertexShaderCompiled == GL_FALSE || isFragmentShaderCompiled == GL_FALSE)
        {
            glDeleteShader(VertexShaderID);
            glDeleteShader(FragmentShaderID);
        }
    }

    bool OpenGLShaderSlot::IsValid() const
    {
        if (glIsShader(VertexShaderID))
        {
            GLint isVertexShaderToDelete = 0;
            glGetShaderiv(VertexShaderID, GL_DELETE_STATUS, &isVertexShaderToDelete);
            if (isVertexShaderToDelete) return false;
        }
        else
        {
            return false;
        }

        if (glIsShader(FragmentShaderID))
        {
            GLint isFragmentShaderToDelete = 0;
            glGetShaderiv(FragmentShaderID, GL_DELETE_STATUS, &isFragmentShaderToDelete);
            if (isFragmentShaderToDelete) return false;
        }
        else
        {
            return false;
        }

        return true;
    }

    void OpenGLShaderSlot::PrintSource() const
    {
        GLint maxLength = 0;
        glGetShaderiv(VertexShaderID, GL_SHADER_SOURCE_LENGTH, &maxLength);
        GLchar* sourceStr = (GLchar*)malloc(sizeof(GLchar) * maxLength);
        glGetShaderSource(VertexShaderID, maxLength, nullptr, sourceStr);
        free(sourceStr);

        UL_CORE_INFO("{0}", sourceStr);
    }

    void OpenGLShaderSlot::Log(GLuint shaderID)
    {
        GLint shaderType = 0;
        glGetShaderiv(shaderID, GL_SHADER_TYPE, &shaderType);

        GLint maxLength = 0;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

        GLchar* infoLog = (GLchar*)malloc(sizeof(GLchar) * maxLength);
        glGetShaderInfoLog(shaderID, maxLength, &maxLength, infoLog);

        UL_CORE_INFO("Shader Type: {0}", shaderType);
        UL_CORE_ERROR("{0}", infoLog);
        UL_CORE_ASSERT(false, "Shader compilation failure!");

        free(infoLog);
    }
}
