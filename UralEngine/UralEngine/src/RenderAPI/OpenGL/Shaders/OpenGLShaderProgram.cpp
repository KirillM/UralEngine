//
//  OpenGLShaderProgram.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 16.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "OpenGLShaderProgram.h"

namespace Ural {

    OpenGLShaderProgram::~OpenGLShaderProgram()
    {
        // Deletes attached shaders
        glDeleteProgram(m_ProgramID);
    }

    void OpenGLShaderProgram::UseProgram() const
    {
        glUseProgram(m_ProgramID);
    }

    void OpenGLShaderProgram::StopProgram() const
    {
        /*
         If program is zero, then the current rendering state refers to an invalid program object and the results of shader execution are undefined. However, this is not an error.
         */
        glUseProgram(0);
    }

    void OpenGLShaderProgram::AttachShaderSlot(const OpenGLShaderSlot& shaderSlot)
    {
        m_ShaderSlot = std::make_shared<OpenGLShaderSlot>(shaderSlot);

        m_ProgramID = glCreateProgram();
        /*
         All operations that can be performed on a shader object are valid whether or not the shader object is attached to a program object. It is permissible to attach a shader object to a program object before source code has been loaded into the shader object or before the shader object has been compiled. It is not permissible to attach multiple shader objects of the same type. It is permissible to attach a shader object to more than one program object.
         */
        glAttachShader(m_ProgramID, m_ShaderSlot->m_VertexShaderID);
        glAttachShader(m_ProgramID, m_ShaderSlot->m_FragmentShaderID);
    }

    void OpenGLShaderProgram::DetachShaderSlot()
    {
        m_ShaderSlot.reset();
    }

    bool OpenGLShaderProgram::IsValid() const
    {
        if(glIsProgram(m_ProgramID))
        {
            GLint isProgramToDelete = 0;
            glGetProgramiv(m_ProgramID, GL_DELETE_STATUS, &isProgramToDelete);
            if (isProgramToDelete) return false;
        }
        else
        {
            return false;
        }

        return true;
    }

    void OpenGLShaderProgram::Compile() const
    {
        m_ShaderSlot->Compile();

        /*
        However, relinking the program object that is currently in use will install the program object as part of the current rendering state if the link operation was successful (see glLinkProgram ). If the program object currently in use is relinked unsuccessfully, its link status will be set to GL_FALSE, but the executables and associated state will remain part of the current state until a subsequent call to glUseProgram removes it from use. After it is removed from use, it cannot be made part of current state until it has been successfully relinked
         */
        glLinkProgram(m_ProgramID);

        GLint isLinkStatusOK = 0;
        glGetProgramiv(m_ProgramID, GL_LINK_STATUS, &isLinkStatusOK);

        if (!isLinkStatusOK)
        {
            Log(m_ProgramID);
        }

        #ifdef DEBUG
        glValidateProgram(m_ProgramID);
        GLint isValidationStatusOK = 0;
        glGetProgramiv(m_ProgramID, GL_VALIDATE_STATUS, &isValidationStatusOK);

        if (!isValidationStatusOK)
        {
            Log(m_ProgramID);
        }
        #endif

        glDetachShader(m_ProgramID, m_ShaderSlot->m_VertexShaderID);
        glDetachShader(m_ProgramID, m_ShaderSlot->m_FragmentShaderID);
    }

    void OpenGLShaderProgram::Log(GLuint programID)
    {
        GLint maxLength = 0;
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &maxLength);

        GLchar* infoLog = (GLchar*)malloc(sizeof(GLchar) * maxLength);
        glGetProgramInfoLog(programID, maxLength, &maxLength, infoLog);

        UL_CORE_ERROR("{0}", infoLog);
        UL_CORE_ASSERT(false, "Program Error!");
    }
}
