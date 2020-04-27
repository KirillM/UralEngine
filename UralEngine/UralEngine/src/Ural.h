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
#include "Input/Desktop/DesktopInput.h"
#include "Platform/Mac/MacInput.h"

// коды ввода
#include "Input/Desktop/KeyCodes.h"
#include "Input/Desktop/MouseButtonCodes.h"

// слои
#include "Layers/Layer.h"
#include "Layers/imgui/ImGuiLayer.h"

//------Отрисовщик------------------
// буферы + шейдеры
#include "Renderer/Shaders/Shader.h"
#include "Renderer/Buffers/IndexBuffer.h"
#include "Renderer/Buffers/VertexBuffer.h"
#include "Renderer/Textures/Texture.h"

//------Точка входа-----------------
#include "Ural/Desktop/EntryPoint.h"
//----------------------------------

// время
#include "Time/TimeStep.h"

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
#include "Input/HandHandled/MobileInput.h"
#include "Platform/IOS/IOSInput.h"

// слои
#include "Layers/Layer.h"
//#include "Layers/imgui/ImGuiLayer.h"

//------Отрисовщик------------------
// буферы + шейдеры
#include "Renderer/Shaders/Shader.h"
#include "Renderer/Buffers/IndexBuffer.h"
#include "Renderer/Buffers/VertexBuffer.h"
#include "Renderer/Textures/Texture.h"
#include "Renderer/RenderCommand.h"

// время
#include "Time/TimeStep.h"

#endif

#endif
