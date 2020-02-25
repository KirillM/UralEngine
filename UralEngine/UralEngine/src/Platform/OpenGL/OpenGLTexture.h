//
//  OpenGLTexture.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 25.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLTexture_hpp
#define OpenGLTexture_hpp

#include "Renderer/Texture.h"

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

#endif /* OpenGLTexture_hpp */
