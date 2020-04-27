//
//  OpenGLTexture2D.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 27.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLTexture2D_h
#define OpenGLTexture2D_h

#include "Renderer/Textures/Texture2D.h"

namespace Ural {

    class OpenGLTexture2D : public Texture2D
    {
    public:
        OpenGLTexture2D(const std::string& path);
        virtual ~OpenGLTexture2D();

        virtual uint32_t GetWidth() const override { return m_Width; }
        virtual uint32_t GetHeight() const override { return m_Height; }
        virtual void Bind(uint32_t slot) const override;
    private:
        std::string m_Path;
        uint32_t m_Width, m_Height;
        uint32_t m_RendererID;
    };

}

#endif /* OpenGLTexture2D_h */
