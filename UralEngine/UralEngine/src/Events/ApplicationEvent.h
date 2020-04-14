//
//  ApplicationEvent.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 06/12/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#ifndef ApplicationEvent_h
#define ApplicationEvent_h

#include "Event.h"

namespace Ural {
			
	class URAL_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() = default;
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
			
	class URAL_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() = default;
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
			
	class URAL_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() = default;
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
#endif /* ApplicationEvent_h */
