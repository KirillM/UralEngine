//
//  Shaders.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 12.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include <stdio.h>

// with GLSL you can have a maximum of 16 attributes per vertex program
// Also, each attribute is always a four-component vector, even if you don’t use all four components.

bool bDone = false; // Boolean true or false
int iValue = 42; // Signed integer
uint uiValue = 3929u; // unsigned integer
float fValue = 42.0f; // Floating point value


vec2, vec3, vec4    // 2, 3, and 4 component floating-point vectors
ivec2, ivec3, ivec4 // 2, 3, and 4 component integer vectors
uvec2, uvec3, uvec4 // 2, 3, and 4 component unsigned integer vectors
bvec2, bvec3, bvec4 // 2, 3, and 4 component Boolean vectors


vec4 vVertexPos = vec4(39.0f, 10.0f, 0.0f, 1.0f);

vVertexPos = vOldPos + vOffset;
vVertexPos = vNewPos;
vVertexPos += vec4(1.0f, 1.0f, 0.0f, 0.0f);
vVertexPos *= 5.0f;

vVertexPos.x = 3.0f;
vVertexPos.xy = vec2(3.0f, 5.0f);
vVertexPos.xyz = vNewPos.xyz;

vOutputColor.r = 1.0f;
vOutputColor.rgba = vec4(1.0f, 1.0f, 0.5f, 1.0f);

vTexCoord.st = vec2(1.0f, 0.0f);

vNewColor.bgra = vOldColor.rgba;



mat2, mat2x2    2 columns and 2 rows
mat3, mat3x3    3 columns and 3 rows
mat4, mat4x4    4 columns and 4 rows
mat2x3          2 columns and 3 rows
mat2x4          2 columns and 4 rows
mat3x2          3 columns and 2 rows
mat3x4          3 columns and 4 rows
mat4x2          4 columns and 2 rows
mat4x3          4 columns and 3 rows

// A matrix is essentially an array of vectors in GLSL—column vectors
// For example, to set the last column of a 4 x 4 matrix, you
// would write code similar to this:
mModelView[3] = vec4(0.0f, 0.0f, 0.0f, 1.0f);

// Conversely, to retrieve the last column of a matrix:
vec4 vTranslation = mModelView[3];

// Or even a finer grained query:
vec3 vTranslation = mModelView[3].xyz;

mat4 vTransform = mat4(1.0f, 0.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 0.0f, 1.0f);

mat4 vTransform = mat4(1.0f);


<none>          // Just a normal local variable, no outside visibility or access.
const           // A compile-time constant, or a read-only parameter to a function.
in              // A variable passed in from a previous stage.
in centroid     // Passed in from a previous state, uses centroid interpolation.
out             // Passed out to the next processing stage or assigned a return value in a function.
out centroid    // Passed out to the next processing stage, uses centroid interpolation.
inout           // A read/write variable. Only valid for local function parameters.
uniform         // Value is passed in from client code and does not change across vertices
// The centroid qualifier has no effect unless rendering is being done to a multisampled
// buffer. In a single sampled buffer, interpolation is always performed from the center of a
// pixel.

int CalculateSometing(float fTime, float fStepSize, inout float fVariance); 


// By default parameters are interpolated between shader stages in a perspective correct
// manner. You can specify nonperspective interpolation with the noperspective keyword or
// even no interpolation at all with the flat keyword. You can also optionally use the smooth
// keyword to explicitly state the variable is smoothly interpolated in a perspective correct
// manner, but that is already the default. Here are a few example declarations.
smooth out vec3 vSmoothValue;
flat out vec3 vFlatColor;
noperspective float vLinearlySmoothed;


in vec4 vVertex;
in vec4 vColor;

// Something else to remember is that variables marked as in are read-only


// Uniforms cannot be marked as in or out, they cannot be interpolated (although you can
// copy them into interpolated variables) between shader stages, and they are always readonly.

// You should bear in
// mind that even if a shader compiles correctly, a uniform name may still “disappear” from
// the shader if it is not used directly in the shader.

uniform float fTime;
uniform int iIndex;
uniform vec4 vColorValue;
uniform mat4 mvpMatrix;

uniform sampler2D colorMap;
