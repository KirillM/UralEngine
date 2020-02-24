//
//  RenderCommand.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 24.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "RenderCommand.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Ural {

    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}
