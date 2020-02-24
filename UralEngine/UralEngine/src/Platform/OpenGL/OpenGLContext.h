//
//  OpenGLContext.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 23.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLContext_h
#define OpenGLContext_h

#include "Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Ural {
    class OpenGLContext : public GraphicsContext
    {
        public:
            OpenGLContext(GLFWwindow* windowHandle);
        
            virtual void Init() override;
            virtual void SwapBuffers() override;
    private:
        GLFWwindow* m_WindowHandle;
    };
}


#endif /* OpenGLContext_h */
