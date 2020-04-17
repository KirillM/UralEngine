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

    static const char* StringFromError(GLenum const err) noexcept
    {
      switch (err)
      {
        // opengl 2 errors (8)
        case GL_NO_ERROR:
          return "GL_NO_ERROR";

        case GL_INVALID_ENUM:
          return "GL_INVALID_ENUM";

        case GL_INVALID_VALUE:
          return "GL_INVALID_VALUE";

        case GL_INVALID_OPERATION:
          return "GL_INVALID_OPERATION";

//        case GL_STACK_OVERFLOW:
//          return "GL_STACK_OVERFLOW";
//
//        case GL_STACK_UNDERFLOW:
//          return "GL_STACK_UNDERFLOW";

        case GL_OUT_OF_MEMORY:
          return "GL_OUT_OF_MEMORY";

//        case GL_TABLE_TOO_LARGE:
//          return "GL_TABLE_TOO_LARGE";

        // opengl 3 errors (1)
        case GL_INVALID_FRAMEBUFFER_OPERATION:
          return "GL_INVALID_FRAMEBUFFER_OPERATION";

        // gles 2, 3 and gl 4 error are handled by the switch above
        default:
          assert(!"unknown error");
          return nullptr;
      }
    }

    uint8_t Error::GetError()
    {
        GLenum errorCode = glGetError();
        return errorCode;
    }

    std::string Error::GetErrorString(uint8_t errorCode)
    {
        const char* errorString = StringFromError(errorCode);
        return errorString;
    }

    void Error::PrintError()
    {
        GLuint errorCode = glGetError();
        if (!errorCode) return;
        const char* errorString = StringFromError(errorCode);
        UL_CORE_ERROR("ERROR: {0} {1}", errorCode, errorString);
    }
}

