//
//  Primitive.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 15.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef Primitive_h
#define Primitive_h

/*
By default, OpenGL ES 3.0 describes the window origin (0, 0) to be the
(left, bottom) region. However, for point sprites, the point coordinate
origin is (left, top).
*/

/*
 The clipping operation (especially for lines and triangles) can
 be quite expensive to perform in hardware. A primitive must be
 clipped against six clip planes of the viewing volume, as shown
 in Figure 7-8. Primitives that are partly outside the near and far
 planes go through the clipping operations. However, primitives
 that are partially outside the x and y planes do not necessarily
 need to be clipped. By rendering into a viewport that is bigger
 than the dimensions of the viewport specified with glViewport,
 clipping in the x and y planes becomes a scissoring operation.
 Scissoring is implemented very efficiently by GPUs. This larger
 viewport region is called the guard-band region. Although OpenGL
 ES does not allow an application to specify a guard-band region,
 most—if not all—OpenGL ES implementations implement a
 guard-band.
 */

#endif /* Primitive_h */
