//
//  Blending.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 11.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <OpenGL/gl.h>


// The color value already stored in the color buffer is called the
// destination color DST
// A color value that is coming in
//  is called the source color SRC

// Note that anytime you omit an
// alpha value, OpenGL assumes it is 1.0

// Cf = (Cs * S) + (Cd * D)

glEnable(GL_BLEND);

GL_ZERO                         // (0,0,0)                 0
GL_ONE                          // (1,1,1)                 1
GL_SRC_COLOR                    // (Rs,Gs,Bs)              As
GL_ONE_MINUS_SRC_COLOR          // (1,1,1) – (Rs,Gs,Bs)    1 – As
GL_DST_COLOR                    // (Rd,Gd,Bd)              Ad
GL_ONE_MINUS_DST_COLOR          // (1,1,1) – (Rd,Gd,Bd)    1 – Ad
GL_SRC_ALPHA                    // (As,As,As)              As
GL_ONE_MINUS_SRC_ALPHA          // (1,1,1) – (As,As,As)    1 – As
GL_DST_ALPHA                    // (Ad,Ad,Ad)              Ad
GL_ONE_MINUS_DST_ALPHA          // (1,1,1) – (Ad,Ad,Ad)    1 – Ad
GL_CONSTANT_COLOR               // (Rc,Gc,Bc)              Ac
GL_ONE_MINUS_CONSTANT_COLOR     // (1,1,1) – (Rc,Gc,Bc)    1 – Ac
GL_CONSTANT_ALPHA               // (Ac,Ac,Ac)              Ac
GL_ONE_MINUS_CONSTANT_ALPHA     // (1,1,1) – (Ac,Ac,Ac)    1 – Ac
GL_SRC_ALPHA_SATURATE           // (f,f,f)*                1
                                //* Where f = min(As, 1 – Ad).
glBlendFunc(GLenum S, GLenum D);

// CONSTANT_COLOR set by

void glBlendColor(GLclampf red, GLclampf green, Glclampf blue,
GLclampf alpha);


void glBlendEquation(GLenum mode);

GL_FUNC_ADD //(default)     // Cf = (Cs * S) + (Cd * D)
GL_FUNC_SUBTRACT            // Cf = (Cs * S) – (Cd * D)
GL_FUNC_REVERSE_SUBTRACT    // Cf = (Cd * D) – (Cs * S)
GL_MIN                      // Cf = min(Cs, Cd)
GL_MAX                      // Cf = max(Cs, Cd)


// Whereas glBlendFunc specifies the blend functions for source and destination RGBA
// values, glBlendFuncSeparate allows you to specify blending functions for the RGB and
// alpha components separately

void glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum
dstAlpha);
