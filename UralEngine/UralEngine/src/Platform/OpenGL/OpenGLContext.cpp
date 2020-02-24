//
//  OpenGLContext.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 23.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Ural {

    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
    {
        UL_CORE_ASSERT(windowHandle, "Window handle is null");
    }
    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        UL_CORE_ASSERT(status, "Failed to initialized GLAD");

        UL_CORE_INFO("OpenGL Info:");
        UL_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
        UL_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
        UL_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
    }
    void OpenGLContext::SwapBuffers()
    {
        //glBegin(GL_TRIANGLES);
        //glEnd();
        glfwSwapBuffers(m_WindowHandle);
    }
}
