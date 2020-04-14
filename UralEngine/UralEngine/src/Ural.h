//
//  Ural.h
//  Ural
//
//  Created by Кирилл Мезрин on 30/11/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#ifndef Ural_h
#define Ural_h

#include "Ural/Core.h"
#include <ulpch.pch>

#ifdef UL_PLATFORM_MAC

// Для приложений использующих Ural
#include "Ural/Application.h"
#include "Ural/Desktop/DesktopApplication.h"
#include "Log/Log.h"

// окно
#include "Platform/Mac/MacWindow.h"

// События
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/Desktop/DesktopEvent.h"

// опрос на ввод
#include "Input/DesktopInput.h"
#include "Platform/Mac/MacInput.h"

// коды ввода
#include "Input/KeyCodes.h"
#include "Input/MouseButtonCodes.h"

// слои
#include "Layers/Layer.h"
#include "Layers/imgui/ImGuiLayer.h"

//------Точка входа-----------------
#include "Ural/Desktop/EntryPoint.h"
//----------------------------------

#else

// surface
#include "Platform/IOS/IOSSurface.h"

// Для приложений использующих Ural
#include "Ural/Application.h"
#include "Ural/Mobile/MobileApplication.h"
#include "Log/Log.h"

// События
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/Mobile/MobileEvent.h"

// опрос на ввод
#include "Input/MobileInput.h"
#include "Platform/IOS/IOSInput.h"

// слои
#include "Layers/Layer.h"
#include "Layers/imgui/ImGuiLayer.h"

#endif

#endif
