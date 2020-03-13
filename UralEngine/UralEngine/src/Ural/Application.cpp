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
//#include <OpenGL/gl3.h>

namespace Ural {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application* Application::s_Instance = nullptr;

	Application::Application()
	
	{
        UL_CORE_ASSERT(!s_Instance, "Application already exists !");
        s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

//        unsigned int id;
//        glGenVertexArrays(1, &id);
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

        glClearColor(0, 1, 1, 1); // устанавливает цвет для очистки окна

		while (m_Running)
		{
            int w = GetWindow().GetWidth();
            int h = GetWindow().GetHeight();
            WindowResizeEvent e(w, h);
            OnWindowResize(e);

            glClear(GL_COLOR_BUFFER_BIT); // очищает определенный буфер или комбинацию буферов, в данном случае удаляет из буфера пикселей последний отображенный рисунок
            //GL_COLOR_BUFFER_BIT - буфер цветов (пикселей), место где хранится отображаемое изображений

            // OpenGL - машина состояний
            // для преключания сотосяний
            glEnable(GL_LIGHTING);
            glRectf(0, 0, 50.0f, -50.0f);
            bool isEnabled = glIsEnabled(GL_LIGHTING);
            glDisable(GL_LIGHTING);

            // для проверки переключаемых значений
//            glGetBooleanv(GLenum pname, GLboolean *params);
//            glGetDoublev(GLenum pname, GLdouble *params);
//            glGetFloatv(GLenum pname, GLfloat *params);
//            glGetIntegerv(GLenum pname, GLint *params);

            // Стэк аттрибутов
//            glPushAttrib(GLbitfield mask);
//            glPopAttrib();

            // Информация о драйверах
            //glGetString(GLenum name)
            //gluGetString(GLenum name)

            // Инормация о расширения поддерживаемые драйвером
            const GLubyte *ext = glGetString(GL_EXTENSIONS);
            UL_CORE_INFO(ext);


            // Управление скоростью / качеством ( эта функця целиком определяется производителем драйверов )
            //glHint(GLenum target, GLenum mode);
            // target = точность тумана, защита от наложения (сливание линий с фоном)
            // mode = быстрое выполнение / качественное изображение / не волнует

            glPushAttrib(GL_TEXTURE_BIT | GL_LIGHTING_BIT); // записываем в стэк состояние освещения и текутры

            glColor3f(1.0f, 0.0f, 0.0f); // устанавливает текущий цвет
            glRectf(-25.0f, 25.0f, 25.0f, -25.0f); // рисует прямоугольник закрашенный текущим цветом
            GLenum err = glGetError();
            const GLubyte *str = gluErrorString(err); // строка описывающая метку ошибки
         //   glFlush(); // указывается выполнить все невыполненные команды OpenGL, очищает очередь комманд

            GLfloat sizes[2];
            GLfloat step;

            glGetFloatv(GL_POINT_SIZE_RANGE, sizes); // диапозон размеров
            glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step); // наименьший интервал между ними
            // OpenGL = 1.0
            // Microsoft 0.125 - 10 / мин шаг 0.125
            // при непопадании в диапозон исполбзуется наиболее приблеженное мин и макс,
            // точки не меняют свое положение при перспективных преобразованиях
            // не уменьшаются и не увеличиваются - всегда квадратные
            // не является чтоным размером точки в пикселях, а приблизительном диаметре окружности содержаий все пиксели точки
            glPointSize(64); // поддерживает не все размеры

           // glLineWidth(GLfloat width)
            glEnable(GL_LINE_STIPPLE);
             glLineStipple(2, 127); // (factor, pattern)
             // pattern - 16 бит, каждый бит соответсвует 1-му пикселю // 0000000011111111 -> ттттттттсссссссс (темно - светло)
             // factor - множитель увеличивающий длину шаблона, столько-то включенных / выключенных пикселей подряд

            glShadeModel(GL_SMOOTH);

            

            glDisable(GL_LINE_STIPPLE);

            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();

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
