//
//  OpenGLShaderCompiler.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 17.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "OpenGLShaderCompiler.h"
#include "Core.h"
#include "RenderAPI/OpenGL/OpenGLAPI.h"

namespace Ural {

    bool ShaderCompiler::isSupported()
    {
        GLboolean isSupported = 0;
        glGetBooleanv(GL_SHADER_COMPILER, &isSupported);
        return isSupported;
    }

    void ShaderCompiler::PrintSupportedShaderFormats()
    {
        /*
         But the problem with iOS implementation of OpenGL ES is that it doesn't export any binary formats. Meaning glGetInteger(GL_NUM_SHADER_BINARY_FORMATS) returns 0
         */

        GLint numberOfSupportedShaderFormats = 0;
        glGetIntegerv(GL_NUM_SHADER_BINARY_FORMATS, &numberOfSupportedShaderFormats);

        if (!numberOfSupportedShaderFormats) return;

        GLint* listOfSupportedFormats = (GLint*)malloc(sizeof(GLint) * numberOfSupportedShaderFormats + 1);
        glGetIntegerv(GL_SHADER_BINARY_FORMATS, listOfSupportedFormats);

//        for(int i = 0; i < numberOfSupportedShaderFormats; i++)
//        {
//            GLchar* supportedFormat = (GLchar*)listOfSupportedFormats[i];
//            UL_CORE_INFO("Supported Shader Formats: {0}", supportedFormat);
//        }
//
        free(listOfSupportedFormats);
    }

    void ShaderCompiler::PrintSupportedProgramFormats()
    {

        GLint numberOfSupportedProgramFormats = 0;
        glGetIntegerv(GL_NUM_PROGRAM_BINARY_FORMATS, &numberOfSupportedProgramFormats);

        if (!numberOfSupportedProgramFormats) return;

        GLint* listOfSupportedFormats = (GLint*)malloc(sizeof(GLint) * numberOfSupportedProgramFormats);
        glGetIntegerv(GL_PROGRAM_BINARY_FORMATS, listOfSupportedFormats);

//        for(int i = 0; i < numberOfSupportedProgramFormats; i++)
//        {
//            GLchar* supportedFormat = (GLchar*)listOfSupportedFormats[i];
//            UL_CORE_INFO("Supported Shader Formats: {0}", supportedFormat);
//        }

        free(listOfSupportedFormats);
    }

    uint32_t ShaderCompiler::CurrentProgram()
    {
        GLint programID = 0;
        glGetIntegerv(GL_CURRENT_PROGRAM, &programID);
        return programID;
    }

    void* ShaderCompiler::GetProgramBinary(uint32_t programID, uint32_t binaryFormat)
    {
        GLint binaryLenght = 0;
        glGetIntegerv(GL_PROGRAM_BINARY_LENGTH, &binaryLenght);

        if (!binaryLenght) return nullptr;

        std::vector<char> buffer(1024);
        glGetProgramBinary(programID, 1024, &binaryLenght, &binaryFormat, buffer.data()); //?

        return buffer.data();
    }

    void ShaderCompiler::ReleaseCompiler()
    {
        glReleaseShaderCompiler();
    }

}
