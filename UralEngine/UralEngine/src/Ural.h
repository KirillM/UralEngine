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

// для приложений использующих Ural
#include "Log/Log.h"
#include "Ural/Application.h"

// окно
#include "Platform/Mac/MacWindow.h"

// События
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

// коды ввода
#include "Input/KeyCodes.h"
#include "Input/MouseButtonCodes.h"

// опрос на ввод
#include "Input/Input.h"
#include "Platform/Mac/MacInput.h"

// слои
#include "Layers/Layer.h"
#include "Layers/imgui/ImGuiLayer.h"

//------Отрисовщик------------------
// буферы + шейдеры
#include "Renderer/Shader.h"
#include "Renderer/Buffer.h"
#include "Renderer/VertexArray.h"

// отрисовщик
#include "Renderer/Renderer.h"
#include "Renderer/RenderCommand.h"

// камеры
#include "Renderer/OrthographicCamera.h"
//----------------------------------

//------Точка входа-----------------
#include "Ural/EntryPoint.h"
//----------------------------------

#endif
