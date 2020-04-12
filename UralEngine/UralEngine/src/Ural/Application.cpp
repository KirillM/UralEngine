//
//  Application.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 01/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log/Log.h"

#include "Input/Input.h"
#include <GLFW/glfw3.h>
#include <OpenGL/glu.h>

#include <OpenGL/gl3.h>

#include <stdalign.h>

namespace Ural {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application* Application::s_Instance = nullptr;

    static void glShaders()
    {
        GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
        GLuint pShader = glCreateShader(GL_FRAGMENT_SHADER);

        const GLchar* vShaderText = R"(
             #version 330
             layout(location = 0) in vec4 a_Position;
             layout(location = 1) in vec4 a_Color;

             out vec4 v_Color;

             void main(void) {
                 gl_Position = a_Position;
                 v_Color = a_Color;
             })";
        const GLchar* pShaderText = R"(
            #version 330

             layout(location = 0) out vec4 v_FragColor;
             in vec4 v_Color;

             void main(void) {
                 v_FragColor = v_Color;
             })";

         glShaderSource(vShader, 1, &vShaderText, NULL);
         glShaderSource(pShader, 1, &pShaderText, NULL);
         glCompileShader(vShader);
         glCompileShader(pShader);

         GLint vShaderCompileStatus;
         glGetShaderiv(vShader, GL_COMPILE_STATUS, &vShaderCompileStatus);

         GLint pShaderCompileStatus;
         glGetShaderiv(pShader, GL_COMPILE_STATUS, &pShaderCompileStatus);

         char infoLog[1024];

         if (!vShaderCompileStatus)
             glGetShaderInfoLog(vShader, sizeof(infoLog), NULL, infoLog);
         if (!pShaderCompileStatus)
             glGetShaderInfoLog(pShader, sizeof(infoLog), NULL, infoLog);

         if (!vShaderCompileStatus || !pShaderCompileStatus) {
             std::cout << "Shader error:" << infoLog << "\n";
             glDeleteShader(vShader);
             glDeleteShader(pShader);
             return;
         }

         GLuint shProgram = glCreateProgram();
         glAttachShader(shProgram, vShader);
         glAttachShader(shProgram, pShader);

        GLuint positionLoc = glGetAttribLocation(shProgram, "a_Position");
        GLuint colorLoc = glGetAttribLocation(shProgram, "a_Color");

         glBindAttribLocation(shProgram, positionLoc, "a_Position");
         glBindAttribLocation(shProgram, colorLoc, "a_Color");

         glLinkProgram(shProgram);
        glValidateProgram(shProgram);
        GLint pProgramLinkStatus = 0;

        glGetProgramiv(shProgram, GL_LINK_STATUS, &pProgramLinkStatus);
        if (!pProgramLinkStatus) {

            GLint maxLength = 0;
            glGetProgramiv(shProgram, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            char* infoLoger = (char*)malloc(maxLength);
            glGetProgramInfoLog(shProgram, maxLength, &maxLength, &infoLoger[0]);

            std::cout << "Shader link error:" << infoLoger << "\n";

            glDeleteProgram(shProgram);
            return;
        }

         glDeleteShader(vShader);
         glDeleteShader(pShader);

         glUseProgram(shProgram);

        GLint maxLength = 0;
           glGetProgramiv(shProgram, GL_INFO_LOG_LENGTH, &maxLength);

           // The maxLength includes the NULL character
           char* infoLoger = (char*)malloc(maxLength);
           glGetProgramInfoLog(shProgram, maxLength, &maxLength, &infoLoger[0]);

           std::cout << "Shader link error:" << infoLoger << "\n";
    }

    static void glBuffers()
    {
        // ---------------------------------------------------------------------------
        // Pixel buffer
        // objects

        GLuint buff[1];
        glGenBuffers(1, buff);
        glBindBuffer(GL_PIXEL_PACK_BUFFER, buff[0]);

        glBufferData(GL_PIXEL_PACK_BUFFER, 1024, NULL, GL_DYNAMIC_DRAW); // fill data later
        // GL_DYNAMIC_COPY - performance hint to help the OpenGL driver
        // allocate memory in the correct location

        const char* subData[1024-256]; //256 - data offset
///
        // Pixel buffer
        // objects -  any OpenGL operations that read pixels get their data from the PBO

        glBufferSubData(GL_PIXEL_PACK_BUFFER, 256, 1024 - 256, subData); // can't change usage - memory already allocated

        /*
         Normally
         these operations pull data out of a framebuffer or texture and read it back into client
         memory. When a PBO is attached to the pack buffer, pixel data ends up in the PBO in
         GPU memory instead of downloaded to the client.


        glReadPixels(<#GLint x#>, <#GLint y#>, <#GLsizei width#>, <#GLsizei height#>, <#GLenum format#>, <#GLenum type#>, <#GLvoid *pixels#>);
        glGetTexImage(<#GLenum target#>, <#GLint level#>, <#GLenum format#>, <#GLenum type#>, <#GLvoid *pixels#>);
        glGetCompressedTexImage(<#GLenum target#>, <#GLint lod#>, <#GLvoid *img#>);

         */

        GLuint pbuffer[1];
        glGenBuffers(1, pbuffer);
        glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pbuffer[0]);

        /*
         When a PBO is attached to
         this target, any OpenGL operations that draw pixels put their data into an attached PBO

         These operations put data into framebuffers and textures
         from local CPU memory. But having a PBO bound as the unpack buffer directs the read
         operations to be the PBO in GPU memory instead of memory on the CPU

        glTexImage1D(<#GLenum target#>, <#GLint level#>, <#GLint internalformat#>, <#GLsizei width#>, <#GLint border#>, <#GLenum format#>, <#GLenum type#>, <#const GLvoid *pixels#>);
        glTexSubImage1D(<#GLenum target#>, <#GLint level#>, <#GLint xoffset#>, <#GLsizei width#>, <#GLenum format#>, <#GLenum type#>, <#const GLvoid *pixels#>);
        glCompressedTexImage1D(<#GLenum target#>, <#GLint level#>, <#GLenum internalformat#>, <#GLsizei width#>, <#GLint border#>, <#GLsizei imageSize#>, <#const GLvoid *data#>);

         */

        glBindBuffer(GL_PIXEL_PACK_BUFFER, 0); // unbind
        glDeleteBuffers(1, buff);
        glDeleteBuffers(1, pbuffer);
        // ----------------------------------------------------------------------------

       // const char* pixelData[1024];
        const char* pixelData = (char *)malloc(1024);
        glReadBuffer(GL_BACK_LEFT);
        // This function takes pixels from the specified location of the
        // currently enabled read buffer and copies them into local CPU memory
        glReadPixels(0, 0, 1024, 768, GL_RGB, GL_UNSIGNED_BYTE, (void*)pixelData);
        /*
         When you execute a read of pixel data into client memory, the entire pipeline often has to
         be emptied to ensure all drawing that would affect the pixels you are about to read has
         completed. !!! TO CPU COPYING !!!
         */

        GLuint packBuff[1];
        glGenBuffers(1, packBuff);
        glBindBuffer(GL_PIXEL_PACK_BUFFER, packBuff[0]);
        glReadPixels(0, 0, 1024, 768, GL_RGB, GL_UNSIGNED_BYTE, NULL); // NULL -  This redirects the pixels into a buffer located on
        // the GPU and avoids the performance issues that copying to client memory can cause
    }

    static void glQuery()
    {
        GLuint one_query;
        GLuint ten_queries[10];

        glGenQueries(1, &one_query); // 1 name
        glGenQueries(10, ten_queries); // 10 names

        glBeginQuery(GL_SAMPLES_PASSED, one_query); //“How many samples passed the depth test?, start counting
        /*
         This tells OpenGL to stop counting samples that have passed the depth test and made it
         through the fragment shader without being discarded. All the pixels generated by all the
         drawing commands between the call to glBeginQuery and glEndQuery are added up
         */
        glEndQuery(GL_SAMPLES_PASSED); //GL_ANY_SAMPLES_PASSED

        GLuint result;
        /*
         and then checking if
         result is zero or not, you can determine whether the object is visible
         */
        GLuint isResultAvailbale;
        /*
         ask OpenGL if it’s finished rendering anything that might affect the result of
         the query and therefore has a result available for you
         */
        glGetQueryObjectuiv(one_query, GL_QUERY_RESULT_AVAILABLE, &isResultAvailbale);
        /*
         If the result of the query object is not immediately available and trying to retrieve it
         would cause your application to have to wait for OpenGL to finish what it is working on,
         */
        if (isResultAvailbale) {
            glGetQueryObjectuiv(one_query, GL_QUERY_RESULT, &result);
             if (result) {

             }
        }
        
        glDeleteQueries(10, ten_queries);
        glDeleteQueries(1, &one_query);


        /*
          but still possible that OpenGL will not be able to create a query for you, and in
          this case it returns zero as the name of the query
         */
    }

    static void glCondition()
    {
        GLuint one_query;
        glGenQueries(1, &one_query);
        /*
         ignore all of this if the
         result stored in the query object is zero
         */
        glBeginConditionalRender(one_query, GL_QUERY_WAIT);

        // GL_QUERY_NO_WAIT -  To tell OpenGL not to wait and to
        // just go ahead and start rendering if the results aren’t available, call
        glEndConditionalRender();
    }

    static void glProfiling()
    {
        GLuint one_query;
        glGenQueries(1, &one_query);
        glBeginQuery(GL_TIME_ELAPSED, one_query);
        glEndQuery(GL_TIME_ELAPSED);
        glDeleteQueries(1, &one_query);


        GLuint start_quey;
        GLuint end_query;
        /*
         This function puts the query straight into the OpenGL pipeline, and when
         that query reaches the end of the pipeline, OpenGL records its view of the current time
         into the query object
         */
        glQueryCounter(GL_TIMESTAMP, start_quey);
        ///
        glQueryCounter(GL_TIMESTAMP, end_query);
        GLuint start_time;
        GLuint end_time;
        /*
         you don’t need to call
         glBeginQuery and glEndQuery in pairs, which means that there are less calls to OpenGL,
         in total.
         */
        glGetQueryObjectuiv(start_quey, GL_QUERY_RESULT, &start_time);
        glGetQueryObjectuiv(end_query, GL_QUERY_RESULT, &end_time);

        GLuint timePassed = end_time - start_time;
    }

    static void glVertex()
    {
        GLuint vao;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        /*
         From
         now on, any time you call a function that accesses the vertex array state, it will access the
         state contained in the currently bound VAO
         */

//        glDrawElements(<#GLenum mode#>, <#GLsizei count#>, <#GLenum type#>, <#const GLvoid *indices#>);
//        glVertexAttribPointer(<#GLuint index#>, <#GLint size#>, <#GLenum type#>, <#GLboolean normalized#>, <#GLsizei stride#>, <#const GLvoid *pointer#>);
//        glGetIntegerv(<#GLenum pname#>, <#GLint *params#>);

        GLuint buff;
        glGenBuffers(1, &buff);
        glBindBuffer(GL_ARRAY_BUFFER, buff);

        // Used with buffer
//        glBufferData(<#GLenum target#>, <#GLsizeiptr size#>, <#const GLvoid *data#>, <#GLenum usage#>);
//        glBufferSubData(<#GLenum target#>, <#GLintptr offset#>, <#GLsizeiptr size#>, <#const GLvoid *data#>);
//        glMapBuffer(<#GLenum target#>, <#GLenum access#>);
//        glCopyBufferSubData(<#GLenum readTarget#>, <#GLenum writeTarget#>, <#GLintptr readOffset#>, <#GLintptr writeOffset#>, <#GLsizeiptr size#>);


        /*
         If the data is changed regularly by the application, it may seem useful to keep data in the
         application’s memory space. However, it is still necessary to use a VBO for this because
         OpenGL does not support reading data directly from system memory. If you specify the
         GL_STREAM_DRAW usage mode when calling glBufferData, OpenGL knows that the data is
         likely to be used only once and the behavior, and performance of the application should
         be the same as if you had kept data in the application’s memory. In any case, even if you
         were able to keep data in the application’s memory, it is very likely that your OpenGL
         ptg
         drivers would perform a similar operation internally and end up copying the data to a
         staging area in the GPU’s memory before using it
         */
//        static const GLfloat data[] = {1.0f, 2.0f, 3.0f, 4.0f};
//        glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
//        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)0);
        // sahder: layout attribute position  //sahder: vec4 // data is not mormilazed (-1.0 to 1.0), data stride, data pointer,if = 0 it will be interpreted as
        // an offset into buff

        static const GLfloat positions[] = {-0.5f, -0.5f, 0.0f, 1.0f}; //vec4
        static const GLfloat colors[] = {0.0f, 0.0f, 0.5f, 1.0f}; // vec4
        static const GLfloat normals[] = {1.0f, 2.0f, 3.0f}; // vec3
//
//        glBufferData(GL_ARRAY_BUFFER, sizeof(positions) + sizeof(colors) + sizeof(normals), NULL, GL_STATIC_DRAW);
//        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(positions), positions);
//        glBufferSubData(GL_ARRAY_BUFFER, sizeof(positions), sizeof(colors), colors);
//        glBufferSubData(GL_ARRAY_BUFFER, sizeof(positions) + sizeof(colors), sizeof(normals), normals);
//
//        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)0);
//        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)sizeof(positions));
//        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)(sizeof(positions) + sizeof(colors)));

//        typedef struct
//        {
//            GLfloat positions[4];
//            GLfloat colors[4];
//            GLfloat normals[3];
//        } Vertex;

        struct vertex
        {
            GLfloat positions[4];
            GLfloat colors[4];
          //  GLfloat normals[3];
        };

        struct vertex verticies[3];

        int sz = sizeof(((struct vertex*)nullptr)->positions);
        int sz2 = sizeof(((struct vertex){0}).positions);

        /*
         An important thing to remember, at the moment you initialize even one object/ variable in the struct, all of its other variables will be initialized to default value.
         */
        //            -0.5f, -0.5f,
        //            0.0f, 0.5f,
        //            0.5f, -0.5f
       // struct vertex vtx = {.positions = {1,2,3}, .colors = {1,2,3}, .normals = {1,2,3}};
        memcpy(verticies[0].positions, positions, sizeof(verticies[0].positions));
        memcpy(verticies[0].colors, colors, sizeof(verticies[0].colors));
       // memcpy(verticies[0].normals, normals, sizeof(verticies[0].normals));

        memcpy(verticies[1].positions, (GLfloat[]){0.0f, 0.5f, 0.0f, 1.0f}, sizeof(((struct vertex){0}).positions));
        memcpy(verticies[1].colors, (GLfloat[]){0.1f, 0.1f, 0.1f, 1.0f}, sizeof(((struct vertex){0}).colors));
      //  memcpy(verticies[1].normals, (GLfloat[]){1.0f, 2.0f, 3.0f}, sizeof(((struct vertex){0}).normals));

        memcpy(verticies[2].positions, (GLfloat[]){0.5f, -0.5f, 0.0f, 1.0f}, sizeof(((struct vertex){0}).positions));
        memcpy(verticies[2].colors, (GLfloat[]){0.0f, 0.5f, 0.5f, 1.0f}, sizeof(((struct vertex){0}).colors));
      //  memcpy(verticies[2].normals, (GLfloat[]){1.0f, 2.0f, 3.0f}, sizeof(((struct vertex){0}).normals));

        glBufferData(GL_ARRAY_BUFFER, sizeof(struct vertex) * 3, verticies, GL_STATIC_DRAW);

        GLenum err = glGetError();
        const GLubyte *str = gluErrorString(glGetError()); //

        /*
         Again, when no VAO is bound, glVertexAttribPointer will not work
         and will generate an error if you call it
         */
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(struct vertex), (GLvoid *)offsetof(struct vertex, positions));
         glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(struct vertex), (GLvoid *)offsetof(struct vertex, colors));
       // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(struct vertex), (GLvoid *)offsetof(struct vertex, normals));


//        GLubyte indecies[] = {0 , 1, 2};
//        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, indecies);
       // glBindBuffer(GL_ARRAY_BUFFER, 0);

        /*
         If no buffer is bound to the GL_ELEMENT_ARRAY_BUFFER binding, glDrawElements won’t do
         anything
         */
        GLuint indexBuffer;
        glGenBuffers(1, &indexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
        GLuint indecies[] = {0 , 1, 2};
        
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 3, &indecies, GL_STATIC_DRAW);
        //glDrawElements(<#GLenum mode#>, <#GLsizei count#>, <#GLenum type#>, <#const GLvoid *indices#>);
        /*
          that allows you to use the same
         indices but different vertex data for each call
         */
        //glDrawElementsBaseVertex(<#GLenum mode#>, <#GLsizei count#>, <#GLenum type#>, <#const GLvoid *indices#>, <#GLint basevertex#>);

       // glBindVertexArray(0);
       // glDeleteVertexArrays(1, &vao);
    }

    static void instanceRender()
    {
        /*
          Your graphics card doesn’t really have a lot of work to do to
         render a single blade of grass, and the system is likely to spend most of its time sending
         commands to OpenGL rather than actually drawing anything
         */

        /*
         Instanced rendering is a method provided by OpenGL to specify that you want to draw
         many copies of the same geometry with a single function call. This functionality is
         accessed through instanced rendering functions
         */

        glDrawArraysInstanced(<#GLenum mode#>, <#GLint first#>, <#GLsizei count#>, <#GLsizei instancecount#>);
        glDrawElementsInstanced(<#GLenum mode#>, <#GLsizei count#>, <#GLenum type#>, <#const GLvoid *indices#>, <#GLsizei instancecount#>);

        /*
         One of the things that makes instanced rendering usable and very powerful is a
         special, built-in variable in GLSL named gl_InstanceID

        When the first copy of the vertices is sent
        to OpenGL, gl_InstanceID will be zero. It will then be incremented once for each copy of
        the geometry and will eventually reach primcount - 1
         */

        /*
          Normally, the vertex attributes would be read per vertex and
         a new value would be fed to the shader. However, to make OpenGL read attributes from
         the arrays once per instance, you can call
         */
        glVertexAttribDivisor(<#GLuint index#>, <#GLuint divisor#>);
        // index: index if attribute, divisor: the number of
        // instances you’d like to pass between each new value being read from the array
    }

    static void storedTransformVerticies()
    {
        glGetBufferSubData(<#GLenum target#>, <#GLintptr offset#>, <#GLsizeiptr size#>, <#GLvoid *data#>);
        glMapBuffer(<#GLenum target#>, <#GLenum access#>);

        /*
         The set of vertex attributes, or varyings, to be recorded during transform feedback mode is
         specified using
         */
        glTransformFeedbackVaryings(<#GLuint program#>, <#GLsizei count#>, <#const GLchar *const *varyings#>, <#GLenum bufferMode#>);

        glBindBuffer(GL_TRANSFORM_FEEDBACK_BUFFER, <#GLuint buffer#>);
        glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, <#GLuint index#>, <#GLuint buffer#>);
        glBindBufferRange(<#GLenum target#>, <#GLuint index#>, <#GLuint buffer#>, <#GLintptr offset#>, <#GLsizeiptr size#>);
        glPauseTransformFeedback();
        glBeginTransformFeedback(<#GLenum primitiveMode#>);
        glEndTransformFeedback();
    }

    static void rasterization()
    {
        /*
         When GL_RASTERIZER_DISCARD is enabled, anything produced by the vertex or geometry
         shader (if present) does not create any fragments, and the fragment shader never runs. If
         you turn off rasterization and do not use transform feedback mode, the OpenGL pipeline
         is essentially turned off.
         */
        glEnable(GL_RASTERIZER_DISCARD);
        glDisable(GL_RASTERIZER_DISCARD);
    }

static void glSync()
{
    glFlush();
    glFinish();

    glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, <#GLbitfield flags#>);
}
	Application::Application()
	
	{
        UL_CORE_ASSERT(!s_Instance, "Application already exists !");
        s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

//        unsigned int id;
//        glGenVertexArrays(1, &id);

//        glVertex();
//         glShaders();
      //  glQuery();
      //  glCondition();
      //  glBuffers();

	}

	Application::~Application()
	{
		
	}

	void Application::OnEvent(Event& e)
	{        
		UL_CORE_INFO("event {0}", e);

        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));

        UL_CORE_TRACE("{0}", e);

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
        {
            (*--it)->OnEvent(e);
            if (e.m_Handled)
                break;
        }
	}

    bool Application::OnWindowResize(WindowResizeEvent &e)
    {
        int w = e.GetWidth();
        int h = e.GetHeight();
        glViewport(0, 0, w, h);

        return true;
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        m_Running = false;
        return true;
    }
		
	void Application::Run()
	{
		//WindowResizeEvent e(1280, 720);
		//UL_TRACE(e);

//        static float vertecies[6] = {
//            -0.5f, -0.5f,
//            0.0f, 0.5f,
//            0.5f, -0.5f
//        };
//
//        unsigned int vao;
//        glGenVertexArrays(1, &vao);
//        glBindVertexArray(vao);
//
//        unsigned int buffer;
//        glGenBuffers(1, &buffer);
//        glBindBuffer(GL_ARRAY_BUFFER, buffer);
//        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, vertecies, GL_STATIC_DRAW);
//        glEnableVertexAttribArray(0);
//        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, nullptr);

        glVertex();
        glShaders();


        glClearColor(0, 1, 1, 1); // устанавливает цвет для очистки окна

		while (m_Running)
		{
            int w = GetWindow().GetWidth();
            int h = GetWindow().GetHeight();
            WindowResizeEvent e(w, h);
            OnWindowResize(e);

            //glDisable(GL_CULL_FACE);
            //glDisable(GL_DEPTH_TEST);

            glClear(GL_COLOR_BUFFER_BIT); // очищает определенный буфер или комбинацию буферов, в данном случае удаляет из буфера пикселей последний отображенный рисунок
            //GL_COLOR_BUFFER_BIT - буфер цветов (пикселей), место где хранится отображаемое изображений
            //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


               glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
            //glDrawArrays(GL_TRIANGLES, 0, 3);

                        GLenum err = glGetError();
                        const GLubyte *str = gluErrorString(err); // строка описывающая метку ошибки









//
//            // OpenGL - машина состояний
//            // для преключания сотосяний
//            glEnable(GL_LIGHTING);
//            glRectf(0, 0, 50.0f, -50.0f);
//            bool isEnabled = glIsEnabled(GL_LIGHTING);
//            glDisable(GL_LIGHTING);
//
//            // для проверки переключаемых значений
////            glGetBooleanv(GLenum pname, GLboolean *params);
////            glGetDoublev(GLenum pname, GLdouble *params);
////            glGetFloatv(GLenum pname, GLfloat *params);
////            glGetIntegerv(GLenum pname, GLint *params);
//
//            // Стэк аттрибутов
////            glPushAttrib(GLbitfield mask);
////            glPopAttrib();
//
//            // Информация о драйверах
//            //glGetString(GLenum name)
//            //gluGetString(GLenum name)
//
//            // Инормация о расширения поддерживаемые драйвером
//            const GLubyte *ext = glGetString(GL_EXTENSIONS);
//            UL_CORE_INFO(ext);
//
//
//            // Управление скоростью / качеством ( эта функця целиком определяется производителем драйверов )
//            //glHint(GLenum target, GLenum mode);
//            // target = точность тумана, защита от наложения (сливание линий с фоном)
//            // mode = быстрое выполнение / качественное изображение / не волнует
//
//            glPushAttrib(GL_TEXTURE_BIT | GL_LIGHTING_BIT); // записываем в стэк состояние освещения и текутры
//
//            glColor3f(1.0f, 0.0f, 0.0f); // устанавливает текущий цвет
//            glRectf(-25.0f, 25.0f, 25.0f, -25.0f); // рисует прямоугольник закрашенный текущим цветом
//            GLenum err = glGetError();
//            const GLubyte *str = gluErrorString(err); // строка описывающая метку ошибки
//         //   glFlush(); // указывается выполнить все невыполненные команды OpenGL, очищает очередь комманд
//
//            GLfloat sizes[2];
//            GLfloat step;
//
//            glGetFloatv(GL_POINT_SIZE_RANGE, sizes); // диапозон размеров
//            glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step); // наименьший интервал между ними
//            // OpenGL = 1.0
//            // Microsoft 0.125 - 10 / мин шаг 0.125
//            // при непопадании в диапозон исполбзуется наиболее приблеженное мин и макс,
//            // точки не меняют свое положение при перспективных преобразованиях
//            // не уменьшаются и не увеличиваются - всегда квадратные
//            // не является чтоным размером точки в пикселях, а приблизительном диаметре окружности содержаий все пиксели точки
//            glPointSize(64); // поддерживает не все размеры
//
//           // glLineWidth(GLfloat width)
//            glEnable(GL_LINE_STIPPLE);
//             glLineStipple(2, 127); // (factor, pattern)
//             // pattern - 16 бит, каждый бит соответсвует 1-му пикселю // 0000000011111111 -> ттттттттсссссссс (темно - светло)
//             // factor - множитель увеличивающий длину шаблона, столько-то включенных / выключенных пикселей подряд
//
//            glShadeModel(GL_SMOOTH);
//
//
//
//            glDisable(GL_LINE_STIPPLE);

//            for (Layer* layer : m_LayerStack)
//                layer->OnUpdate();

            std::pair<float, float> position = Input::GetMousePosition();
            UL_CORE_TRACE("{0}, {1}", std::get<0>(position), std::get<1>(position));

			m_Window->OnUpdate(); // при переключении буферов (swap buffers) неявно вызывается glFlush()
		}
	}

    void Application::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer *layer)
    {
        m_LayerStack.PushOverlay(layer);
    }
}
