//
//  RenderCommand.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 17.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "RenderCommand.h"
#include "RenderAPI/OpenGL/OpenGLRendererAPI.h"

namespace Ural {
    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();
}
