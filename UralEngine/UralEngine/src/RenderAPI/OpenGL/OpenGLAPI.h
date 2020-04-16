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
    #include <glad/glad.h>
#elif UL_PLATFORM_IOS
    #include <OpenGLES/ES3/gl.h>
#endif

#endif /* OpenGLAPI_h */
