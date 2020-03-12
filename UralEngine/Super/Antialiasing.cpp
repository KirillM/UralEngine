//
//  Antialiasing.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 11.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <OpenGL/gl.h>


glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glBlendEquation(GL_ADD); // optional (default is set)

glEnable(GL_POINT_SMOOTH); // Smooth out points
glEnable(GL_LINE_SMOOTH); // Smooth out lines
glEnable(GL_POLYGON_SMOOTH); // Smooth out polygon edges



// Turn on antialiasing, and give hint to do the best
// job possible.
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glEnable(GL_BLEND);
glEnable(GL_POINT_SMOOTH);
glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
glEnable(GL_LINE_SMOOTH);
glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
glEnable(GL_POLYGON_SMOOTH);
glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

// Turn off blending and all smoothing
glDisable(GL_BLEND);
glDisable(GL_LINE_SMOOTH);
glDisable(GL_POINT_SMOOTH);
glDisable(GL_POLYGON_SMOOTH);


// Even when GL_POLYGON_SMOOTH is available, it is not as convenient a means
// of having your whole scene antialiased as you might think. Because it is based on the
// blending operation, you would need to sort all your primitives from front to back!


// when it is enabled, the point, line,
// and polygon smoothing features via antialiasing are ignored if enabled.

// On a given
// OpenGL implementation, points and lines may look better with smoothing turned on
// instead of multisampling. To accommodate this, you might turn off multisampling before
// drawing points and lines and then turn on multisampling for other solid geometry.

glEnable(GL_MULTISAMPLE);
glDisable(GL_MULTISAMPLE);


// The multisample buffers use the RGB values of fragments by default and do not include
// the alpha component of the colors. You can change this by calling glEnable with one of
// the following three values:

GL_SAMPLE_ALPHA_TO_COVERAGE // Use the alpha value.
GL_SAMPLE_ALPHA_TO_ONE // Set alpha to 1 and use it.
GL_SAMPLE_COVERAGE // Use the value set with glSampleCoverage.

glEnable(GL_SAMPLE_COVERAGE);

// When GL_SAMPLE_COVERAGE is enabled, the glSampleCoverage function allows you to
// specify a value that is ANDed (bitwise) with the fragment coverage value:

void glSampleCoverage(GLclampf value, GLboolean invert);
