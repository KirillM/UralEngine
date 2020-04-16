//
//  OpenGLAPI.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 16.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLAPI_h
#define OpenGLAPI_h

#ifdef UL_PLATFORM_MAC
    #define GL_SILENCE_DEPRECATION
    //#include <glad/glad.h>
    #include <OpenGL/gl3.h>
#elif UL_PLATFORM_IOS
    #define GLES_SILENCE_DEPRECATION
    #include <OpenGLES/ES3/gl.h>
#endif

#endif /* OpenGLAPI_h */
