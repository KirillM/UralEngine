//
//  OpenGLTexture.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 25.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "OpenGLTexture.h"

#include <glad/glad.h>
#include "stb_image.h"

namespace Ural {
    OpenGLTexture2D::OpenGLTexture2D(const std::string& path) : m_Path(path)
    {
        char mycwdbuf[80];
        memset (mycwdbuf, 0, sizeof(mycwdbuf));
        if (getcwd(mycwdbuf, sizeof(mycwdbuf)-1) != NULL)
           std::cout << "current directory is " << mycwdbuf << std::endl;
        
        int width, height, channels;
        stbi_set_flip_vertically_on_load_thread(1);
        stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
        UL_CORE_ASSERT(data, "Failed to load image!");
        m_Width = width;
        m_Height = height;

       // glGenTextures(GL_TEXTURE_2D, 1, &m_RendererID);
       // glTextureStorage2D(m_RendererID, 1, GL_RGB8, m_Width, m_Height);

        glGenTextures(1, &m_RendererID);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, m_RendererID);

    //    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
      //          glGetError();
        //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        
       // glGetError();
        // uv are not in [0,1] for some models, they assume uvs are repeated.
      //  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
      //  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        //glGenerateMipmap(GL_TEXTURE_2D);
       // gluBuild2DMipmaps(GL_TEXTURE_2D, 4, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
    //    glBindTexture(GL_TEXTURE_2D, 0);
        stbi_image_free(data);
    }

    OpenGLTexture2D::~OpenGLTexture2D()
    {
        glDeleteTextures(1, &m_RendererID);
    }

    void OpenGLTexture2D::Bind(uint32_t slot) const
    {
        glBindTexture(GL_TEXTURE_2D, m_RendererID);
    }
}
