//
//  MouseEvent.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 06/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#ifndef MouseEvent_h
#define MouseEvent_h

#include "Event.h"

namespace Ural {

	class URAL_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
		: m_MouseX(x), m_MouseY(y) {};
		
		inline float int GetX() const { return m_MouseX; }
		inline float int GetY() const { return m_MouseY; }
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}
			
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	private:
		unsigned int m_MouseX, m_MouseY;
	};
			
	class URAL_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_xOffset(xOffst), m_yOffset(yOffset) {};
		
		inline float int GetXOffset() const { return m_xOffset; }
		inline float int GetYOffset() const { return m_yOffset; }
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_xOffset << ", " << m_yOffset;
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	private:
		float m_xOffset;
		float m_yOffset;
	};
			
	class URAL_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }
		
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton)
	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}
		
		int m_Button;
	};
			
	class URAL_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};
			
	class URAL_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}

#endif /* MouseEvent_h */
