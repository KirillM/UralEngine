//
//  Anisantropic.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 12.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <OpenGL/gl.h>

if(gltIsExtSupported(“GL_EXT_texture_filter_anisotropic”)) 

// Bear in mind that anisotropic filtering
// is not free. The extra amount of work, including other texels, can sometimes result in
// substantial performance penaltie

GLfloat fLargest;
. . .
. . .
glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &fLargest);


// anisotropic filtering can also greatly reduce the visible mipmap transition patterns for the
// GL_LINEAR_MIPMAP_NEAREST and GL_NEAREST_MIPMAP_NEAREST mipmapped filters
