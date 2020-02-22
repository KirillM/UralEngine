//
//  MacWindow.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 07/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#ifndef MacWindow_h
#define MacWindow_h

#include "Platform/Window/Window.h"
#include <GLFW/glfw3.h>

namespace Ural {
	class MacWindow : public Window {
	public:
		MacWindow(const WindowsProps& props);
		virtual ~MacWindow();
		
		void OnUpdate() override;
		
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }
		
		inline void SetEventCallback(const EventcallabckFn& callback) override { m_Data.Callback = callback; };
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowsProps& props);
		virtual void ShutDown();
	private:
		GLFWwindow* m_Window;
		
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			
			EventcallabckFn Callback;
		};
		
		WindowData m_Data;
	};
}

#endif /* MacWindow_h */
