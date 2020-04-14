//
//  Window.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 07/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

//#ifndef Window_h
//#define Window_h
//
//#include "Ural/Core.h"
//#include "RenderArea.h"
//
//namespace Ural {
//
//	struct WindowsProps
//	{
//		std::string Title;
//		unsigned int Width;
//		unsigned int Height;
//
//		WindowsProps(const std::string title = "Ural Engine",
//					 unsigned int width = 1280,
//					 unsigned int height = 720)
//			: Title(title), Width(width), Height(height) {}
//
//	};
//
//	class URAL_API Window : public RenderArea
//	{
//	public:
//		virtual void SetVSync(bool enabled) = 0;
//		virtual bool IsVSync() const = 0;
//
//        virtual void* GetNativeWindow() const = 0;
//
//		static Window* Create(const WindowsProps& props = WindowsProps());
//	};
//}
//
//#endif /* Window_h */


#ifndef Window_h
#define Window_h

#include "Events/Event.h"

namespace Ural {

    struct WindowsProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowsProps(const std::string title = "Ural Engine",
                     unsigned int width = 1280,
                     unsigned int height = 720)
            : Title(title), Width(width), Height(height) {}

    };

    class URAL_API Window
    {
    public:
        using EventcallabckFn = std::function<void(Event&)>;

        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventcallabckFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        virtual void* GetNativeWindow() const = 0;

        static Window* Create(const WindowsProps& props = WindowsProps());
    };
}

#endif /* Window_h */
