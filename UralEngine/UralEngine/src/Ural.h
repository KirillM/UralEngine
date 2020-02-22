//
//  Ural.h
//  Ural
//
//  Created by Кирилл Мезрин on 30/11/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#ifndef Ural_h
#define Ural_h

#include <ulpch.pch>

// Для приложений использующих Ural
#include "Ural/Application.h"
#include "Log/Log.h"

// окно
#include "Platform/Mac/MacWindow.h"

// События
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

// опрос на ввод
#include "Input/Input.h"
#include "Platform/Mac/MacInput.h"

// коды ввода
#include "Input/KeyCodes.h"
#include "Input/MouseButtonCodes.h"

// слои
#include "Layers/Layer.h"
#include "Layers/imgui/ImGuiLayer.h"

//------Точка входа-----------------
#include "Ural/EntryPoint.h"
//----------------------------------

#endif
