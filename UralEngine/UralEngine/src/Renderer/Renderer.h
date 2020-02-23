//
//  Renderer.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 23.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

namespace Ural {
    enum class RendererAPI
    {
        None = 0,
        OpenGL = 1
    };

    class Renderer
    {
    public:
        inline static RendererAPI GetAPI() { return s_RendererAPI; }
    private:
        static RendererAPI s_RendererAPI;
    };
}

#endif /* Renderer_hpp */
