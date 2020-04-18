//
//  Textures.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 12.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <OpenGL/gl.h>


// packed or unpacked in memory.
// You can change how pixel data is stored and retrieved by using the following functions:
void glPixelStorei(GLenum pname, GLint param);
void glPixelStoref(GLenum pname, GLfloat param);


GL_UNPACK_ALIGNMENT // specifies how OpenGL unpacks image data from data buffers.
GL_PACK_ALIGNMENT // how to pack data being read
// from pixel buffers and placed in a user-specified memory buffer


// OPenGL USES 4 BYTE ALIGNMENT by default !!!

GL_PACK_SWAP_BYTES      // GLboolean GL_FALSE
GL_UNPACK_SWAP_BYTES    // GLboolean GL_FALSE
GL_PACK_LSB_FIRST       // GLboolean GL_FALSE
GL_UNPACK_LSB_FIRST     // GLboolean GL_FALSE
GL_PACK_ROW_LENGTH      // GLint 0
GL_UNPACK_ROW_LENGTH    // GLint 0
GL_PACK_SKIP_ROWS       // GLint 0
GL_UNPACK_SKIP_ROWS     // GLint 0
GL_PACK_SKIP_PIXELS     // GLint 0
GL_UNPACK_SKIP_PIXELS   // GLint 0
GL_PACK_ALIGNMENT       // GLint 4
GL_UNPACK_ALIGNMENT     // GLint 4
GL_PACK_IMAGE_HEIGHT    // GLint 0
GL_UNPACK_IMAGE_HEIGHT  // GLint 0
GL_PACK_SKIP_IMAGES     // GLint 0
GL_UNPACK_SKIP_IMAGES   // GLint 0

glPixelStorei(GL_UNPACK_ALIGNMENT, 1);


glReadPixels(GLint x, GLint y, GLSizei width, GLSizei height,
GLenum format, GLenum type, const void *pixels);

// by default, the read operation is performed on the back buffer for
// double-buffered rendering contexts, and the front buffer for single-buffered rendering
// contexts. You can change the source of these pixel operations by using this function:

glReadBuffer(GLenum mode);

GL_FRONT
GL_BACK
GL_LEFT
GL_RIGHT
GL_FRONT_LEFT
GL_FRONT_RIGHT
GL_BACK_LEFT
GL_BACK_RIGHT
GL_NONE

// The width, height, and depth parameters (where appropriate) specify the dimensions of
// the texture being loaded. It is important to note that prior to OpenGL 2.0, these dimensions must be integer powers of 2 (1, 2, 4, 8, 16, 32, 64, and so on). There is no requirement that texture maps be square (all dimensions equal), but a texture loaded with
// non-power of 2 dimensions on older OpenGL implementations will cause texturing to be
// implicitly disabled. Even though OpenGL 2.0 (and later) allows non-power of 2 textures,
// this is no guarantee that they will necessarily be fast on the underlying hardware. Many
// performance-minded developers still avoid non-power of two textures for this reason.

// 1D 2D 3D
glTexImage3D(GLenum target, GLint level, GLint internalformat,
GLsizei width, GLsizei height, GLsizei depth, GLint border,
GLenum format, GLenum type, void *data);

// You can read an image from the color buffer and use it as a new texture
// 1D 2D
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat,
GLint x, GLint y,
GLsizei width, GLsizei height, GLint border);
// The source buffer is set using
// glReadBuffer


// Replacing a texture map can often be done
// much more quickly than reloading a new texture directly with glTexImage

// 1D 2D 3D
glTexSubImage3D(GLenum target, GLint level,
GLint xOffset, GLint yOffset, GLint zOffset,
GLsizei width, GLsizei height, GLsizei depth,
GLenum format, GLenum type, const GLvoid *data);


// allows you to combine reading from the color buffer and inserting
// or replacing part of a texture

// 1D 2D ... 3D

// the color buffer is 2D, and there simply is no corresponding way to use a 2D color image
// as a source for a 3D texture. However, you can use glCopyTexSubImage3D to use the color
// buffer data to set a plane of texels in a three-dimensional texture.

glCopyTexSubImage2D(GLenum target, GLint level,
GLint xoffset, GLint yoffset,
GLint x, GLint y,
GLsizei width, GLsizei height);


// The texture state is
// maintained by the currently bound texture object, which is identified by an unsigned
// integer

// You allocate a number of texture objects

// With this function, you specify the number of texture objects and a pointer to an array of
// unsigned integers that will be populated with the texture object identifiers.

glGenTextures(GLsizei n, GLuint *textures);

// You can think
// of them as handles to different available texture states. To “bind” to one of these states,
// you call this function

glBindTexture(GLenum target, GLuint texture);
// !!!! Hereafter, all texture loads and !!!!
// !!!! texture parameter settings affect only the currently bound texture object !!!!


glDeleteTextures(GLsizei n, GLuint *textures);


GLboolean glIsTexture(GLuint texture);


// More effort is involved in texture mapping than slapping an image on the side of a triangle. Many parameters affect the rendering rules and behaviors of texture maps as they are
// applied. These texture parameters are all set via variations on the function
// glTexParameter:

void glTexParameterf(GLenum target, GLenum pname, GLfloat param);
void glTexParameteri(GLenum target, GLenum pname, GLint param);
void glTexParameterfv(GLenum target, GLenum pname, GLfloat *params);
void glTexParameteriv(GLenum target, GLenum pname, GLint *params);


glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 4);

GL_NEAREST                 // Perform nearest neighbor filtering on the base mip level
GL_LINEAR                  // Perform linear filtering on the base mip level
GL_NEAREST_MIPMAP_NEAREST  // Select the nearest mip level and perform nearest
                           // neighbor filtering
GL_NEAREST_MIPMAP_LINEAR   // Perform a linear interpolation between mip levels and
                           // perform nearest neighbor filtering
GL_LINEAR_MIPMAP_NEAREST   // Select the nearest mip level and perform linear filtering
GL_LINEAR_MIPMAP_LINEAR    // Perform a linear interpolation between mip levels and
                           // perform linear filtering; also called trilinear mipmapping

// each one half the size on each
// axis or one-fourth the total number of pixels of the previous image
glGenerateMipmap(GLenum target);


// in most implementations, the texture data stays compressed
// even in the graphics hardware memory
// This allows you to load more texture into less
// memory and can significantly improve texturing performance due to fewer texture swaps
// (moving textures around) and fewer memory accesses during texture filtering

// Texture data does not have to be initially compressed to take advantage of OpenGL
// support for compressed textures. You can request that OpenGL compress a texture image
// when loaded by using one of the generic compression values
