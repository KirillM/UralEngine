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
        int width, height, channels;
        stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
        UL_CORE_ASSERT(data, "Failed to load image!");
        m_Width = width;
        m_Height = height;

       // glGenTextures(GL_TEXTURE_2D, 1, &m_RendererID);
       // glTextureStorage2D(m_RendererID, 1, GL_RGB8, m_Width, m_Height);

        glGenTextures(1, &m_RendererID);
        glActiveTexture(GL_TEXTURE0);
        //glBindTexture(GL_TEXTURE_2D, m_RendererID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB8, GL_UNSIGNED_BYTE, data);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        glGenerateMipmap(GL_TEXTURE_2D);
        //glBindTexture(GL_TEXTURE_2D, 0);
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
