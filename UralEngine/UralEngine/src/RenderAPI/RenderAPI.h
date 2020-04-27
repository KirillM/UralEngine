//
//  RendererAPI.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 17.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef RendererAPI_h
#define RendererAPI_h

namespace Ural {
    class RenderAPI {
    public:
        enum class API {
            None,
            OpenGLES,
            OpenGL,
            Vulkan,
            Direct3D
        };
    public:
        static API s_API;
    };
}

#endif /* RendererAPI_h */
