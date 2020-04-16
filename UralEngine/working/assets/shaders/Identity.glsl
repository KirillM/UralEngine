
#type vertex // препроцессор

#version 330

#define
#undef
#if
#ifdef
#ifndef
#else
#elif
#endif
#error
#pragma

#extension

// Set behavior for an extension
#extension extension_name : behavior
// Set behavior for ALL extensions
#extension all : behavior

// vertex defailt high
// fragment needs to specify explicitly

precision highp float;
precision mediump int;

highp vec4 position;
varying lowp vec4 color;
mediump float specularExp;

#pragma STDGL invariant(all) // PERFOMANCE SERIOUS HIT

/*
 that if the same computations are used to compute an output, its value
 must be exactly the same (or invariant). The invariant keyword can be
 used either on varying declarations or for varyings that have already been
 declared
 */
invariant gl_Position;
invariant texCoord

// Will be the same value in all shaders with the
// same viewProjMatrix and vertex
gl_Position = u_viewProjMatrix * a_vertex;

// внутри себя шейдеры работают с vec4
// Also, each attribute is always a four-component vector, even if you don’t use all four components.

// The key here to understand is that vertex
// inputs are data that are specified for each vertex being drawn

gl_MaxVertexAttribs

// Something else to remember is that variables marked as in are read-only
in vec4 a_Postion; // в каждом шейдере можно иметь минимум 16 аттрибутов
in vec4 a_Color;


// в каждом шейдере можно иметь минимум 16 out's
gl_MaxFragmentInputVectors

/*
  Vertex shader outputs/fragment shader
 inputs are typically stored in interpolators, which again are usually stored
 as an array of vectors.
 */
out vec4 v_Color;

smooth out float smooth1;

/*
 In flat shading, the value is not interpolated across the primitive.
Rather, one of the vertices is considered the provoking vertex (dependent
on the primitive type;
 and that vertex value is used for all fragments in the primitive
 */
flat out flat1;

/*
 when rendering with multisampling, the centroid keyword can be
 used to force interpolation to occur inside the primitive being rendered
 */

centroid out centroid1;

/*
 with uniform buffer objects, uniform buffer data
 can be SHARED ACROSS MULTIPLE PROGRAMS BUT NEED TO BE SET ONLY ONCE
 Further, uniform buffer objects typically allow for storage of larger amounts
 of uniform data. Finally, it can be more efficient to switch between
 uniform buffer objects than to individually load one uniform at a time
 */


uniform TransofrmBlock
{
    mat4 matViewProj;
    mat3 matNormal;
    mat3 matTextGen;
};

/*
 Layout qualifiers can be provided either for individual
 uniform blocks or globally for all uniform block
 */
// Global
layout (shared, column_major) uniform; // default
layout (packed, row_major) uniform;

// Individual
layout(std140) uniform TransformBlock
{
 mat4 matViewProj;
 layout(row_major) mat3 matNormal;
 mat3 matTexGen;
};

/*
 Basically,
 any parameter to a shader that is constant across either all vertices or
 fragments should be passed in as a uniform
 */

/*
 Note also that the namespace for
 uniform variables is SHARED ACROSS BOTH A VERTEX SHADER AND A FRAGMENT
 SHADER. That is, if vertex and fragment shaders are linked together into a
 Uniform Blocks 109
 program object, they share the same set of uniform variables. Therefore,
 if a uniform variable is declared in the vertex shader and also in the
 fragment shader, both of those declarations MUST MATCH. When the
 application loads the uniform variable through the API, its value will be
 available in both the vertex and fragment shaders
 */

// Uniforms cannot be marked as in or out, they cannot be interpolated (although you can
// copy them into interpolated variables) between shader stages, and they are always readonly.

// You should bear in
// mind that even if a shader compiles correctly, a uniform name may still “disappear” from
// the shader if it is not used directly in the shader.

uniform mat4 matViewProj;
uniform mat3 matNormal;
uniform mat3 matTextGen;

/*
 Uniform variables generally are stored in hardware into what is known
 as the “constant store.” This special space is allocated in the hardware
 for the storage of constant values. Because it is typically of a fixed
 size, the number of uniforms that can be used in a program is limited
 */

/*
 An
 implementation of OpenGL ES 3.0 must provide at least 256 vertex
 uniform vectors and 224 fragment uniform vectors, although it is free to
 provide more.
 */

gl_MaxVertexUniformVectors
gl_MaxFragmentUniformVectors

/*
  The std140
 layout guarantees a specific packing behavior with an explicit layout
 specification defined by the OpenGL ES 3.0 specification. Thus using
 std140 layout allows you to share the uniform block between different
 OpenGL ES 3.0 implementations
 */

layout (std140) uniform LightBlock
{
    vec3 lightDirection;
    vec4 lightPosition;
};

// Scalars
float, int, uint, bool

// Floating-point vectors
float, vec2, vec3, vec4

// Integer vectors
int, ivec2, ivec3, ivec4

// Usigned integer vecors
uint, uvec2, uvec3, uvec4

// Boolean vectors
bool, bvec2, bvec3, bvec4

// FLoating-point matricies

mat2, mat2x2, mat2x2, mat2x3, mat2x4
mat3, mat3x2, mat3x3, mat3x4
mat4, mat4x2, mat4x3, mat4x4

// in attributes могут быть только этих типов
float, vec2, vec3, vec4,
int, ivec2, ivec3, ivec4,
uint, uvec2, uvec3, uvec4,

mat2, mat2x2, mat2x3, mat2x4,
mat3, mat3x3, mat3x4,
mat4, mat4x2, mat4x3

/*
 Unlike
 uniform and vertex shader output/fragment shader input variables, which
 are packed automatically by the compiler, attributes do not get packed
 */

/*
 An attribute can be declared inside a vertex shader—but if it is not
 used, then it is not considered active and does not count against the
 limit
 */

// инициализация при объявления
// Initialization is done
// through the use of constructors
//  Each of the built-in variable types has a set of
// associated constructors
bool test = true;
// инициализация без объявления
bool test2;

// If only one scalar argument is provided to a vector constructor, that
// value is used to set all values of the vector
vec3 scalarTest = vec3(4);
vec3 vector = vec3(1.0, 0.0, 0.5);
vec3 vectorAssign = vec3(vector);
vec2 vectorToSmall = vec2(vectorAssign); // в аргументе должно быть как миниуму 2 значения, берутся первые слева на право

sclarTest = vec3(vectorToSmall, vector);


mat3 myMat3 = mat3(1.0); // identity matrix, со значением по диагонали
// эквивалентно
mat3 MyMat31 = mat3(1.0, 0.0, 0.0   // 1 column
                    0.0, 1.0, 0.0   // 2 column
                    0.0, 0.0, 1.0); // 3 column

vec4 myVec4 = vec4(1.0, 0.5, 0.7, 1.0);
// {xyzw rgba stpq}

vec3 myVec3;
myVec3 = myVec4.xxx;
myVec3 = myVec4.zyx;
myVec3 = myVec4.xyz;

myVec3 = vec3(myVec3[0], myVec3[1], myVec3[2]);

mat4 myMat4 = mat4(1.0);
vec4 col0 = myMat4[0];
float el1 = myMat[0][0];
// эквивалентно
float el2 = myMat[0].x;


const float zero = 0.0;

// will result in a new user type named fogStruct
// and a new variable named fogVar
struct fogStruct
{
    vec4 color;
    float start;
    float end;
} fogVar;


fogVar = fogStruct(vec4(1.0, 0.5, 0.4, 1.0),
                   5.0,
                   3.0);

float array0[2] = float[](1.0, 2.0);
// эквивалентно, указание размера - опиционально
float array1[2] = float[2](1.0, 2.0);

vec2 array2[2] = vec2[2](vec2(1.0), vec2(1.0));



/*
 IN (Default if none specified) This qualifier specifies that the parameter
 is passed by value and will not be modified by the function.

 INOUT This qualifier specifies that the variable is passed by reference into
 the function and if its value is modified, it will be changed after
 function exit.

 OUT This qualifier says that the variable’s value is not passed into the
 function, but it will be modified on return from the function.
 */

// по умолчанию in
vec4 myFunc(inout float myFloat, out vec4 myVec4, mat4 myMat4); // объявление функции
// functions cannot be recursive


// Built In

/* The only built-in uniform state available inside a vertex shader is the
depth range in window coordinates. This is given by the built-in uniform
name gl_DepthRange, which is declared as a uniform of type
gl_DepthRangeParameters. */

struct gl_DepthRangeParameters
{
    highp float near; // near Z
    highp float far; // far Z
    highp float diff; // far – near
};

uniform gl_DepthRangeParameters gl_DepthRange;

const mediump int gl_MaxVertexAttribs = 16;
const mediump int gl_MaxVertexUniformVectors = 256;
const mediump int gl_MaxVertexOutputVectors = 16;
const mediump int gl_MaxVertexTextureImageUnits = 16;
const mediump int gl_MaxCombinedTextureImageUnits = 32;

void main(void) {
    tes2 = true;
    v_Color = a_Color;
    gl_Position = a_Position; // highp
    //in gl_InstanceID

    /*
      It is important that a vertex
     shader associated with the point primitive output gl_PointSize; otherwise,
     the value of the point size is considered undefined and will most likely result
     in drawing errors
     */
    
    //out gl_PointSize

    // in gl_VertexID int highp // index of the vertex

    // in gl_FrontFacing bool
}

if (fogVar.color.r < 0.25) // must evaluate to a boolean value
{

}
else
{

}

/*
 That is not to say that loops don’t come with some PERFOMANCE
 implications. On most GPU architectures, vertices or fragments are
 executed in PARALLEL in BATCHES. The GPU typically requires that all
 fragments or vertices in a batch evaluate all branches (or loop iterations)
 of flow control statements. If vertices or fragments in a batch execute
 different paths, then, USUALLY ALL OF THE OTHER VERTICES/FRAGMENTS IN A
 BATCH WILL NEED TO EXECUTE THAT PATH AS WELL. The size of a batch is GPU
 dependent and will often require profiling to determine the performance
 implications of the use of flow control on a particular architecture.
 However, a good rule of thumb is to try to limit the use of divergent flow
 control or loop iterations across vertices/fragments.
 */

for, while, do {} while


// vertex out v_Color == fragment in v_Color / равны тип и имя
// unforms объявлены в обоих шейдерах / равны тип и имя
#type fragment

#version 330

smooth in smooth1;

in vec4 v_Color; // в каждом шейдере можно иметь максимум 16 аттрибутов

out vec4 v_FragColor; // любой out идет в цвет fragment
// может иметь несколько out'ов в разные буферы

uniform TransofrmBlock
{
    mat4 matViewProj;
    mat3 matNormal;
    mat3 matTextGen;
};

uniform mat4 matViewProj;
uniform mat3 matNormal;
uniform mat3 matTextGen;

void main(void) {
    v_FragColor = v_Color;
//in    gl_FragCoord
//in    gl_FrontFacing
//in    gl_PointCoord   mediump vec2 
//out   gl_FragDepth
}
