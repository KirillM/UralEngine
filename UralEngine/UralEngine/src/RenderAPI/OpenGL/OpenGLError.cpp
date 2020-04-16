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
}

