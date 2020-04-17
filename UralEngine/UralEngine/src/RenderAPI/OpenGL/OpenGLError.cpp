//
//  OpenGLESError.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 15.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "OpenGLError.h"
#include "OpenGLAPI.h"

namespace Ural {
    uint8_t Error::GetError()
    {
        GLenum errorCode = glGetError();
        std::string errorString = (const char*)glGetString(errorCode);
        UL_CORE_ERROR("OpenGL Error: {0}", errorString);
        return errorCode;
    }

    std::string Error::GetErrorString(uint8_t errorCode)
    {
        std::string errorString = (const char*)glGetString(errorCode);
        return errorString;
    }

    void Error::PrintError()
    {
        GLuint errorCode = glGetError();
        if (!errorCode) return;
        UL_CORE_ERROR("ERROR: {0} No Description", errorCode);
//        const GLubyte *errorString = glGetString(errorCode);
//        if (!errorString)
//            UL_CORE_ERROR("ERROR: {0} No Description", errorCode);
//        else
//            UL_CORE_ERROR("ERROR: {0} {1})", errorCode, errorString);
    }
}

