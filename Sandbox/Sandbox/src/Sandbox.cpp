//
//  main.cpp
//  Sandbox
//
//  Created by Кирилл Мезрин on 30/11/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include "Ural.h"

class ExampleLayer: public Ural::Layer
{
public:
    ExampleLayer() : Layer("Example")
    {
    }

    void OnUpdate(Ural::TimeStep ts) override
    {
        UL_INFO("ExampleLayer::Update");

        if(Ural::DesktopInput::IsKeyPressed(UL_KEY_TAB))
            UL_INFO("Tab key is pressed!");
    }

    void OnEvent(Ural::Event& event) override
    {
       // UL_TRACE("{0}", event);
    }
};

class Sandbox : public Ural::DesktopApplication
{
public:
    Sandbox()
    {
        PushOverlay(new ExampleLayer());
     //  PushOverlay(new Ural::ImGuiLayer());
    }

    ~Sandbox()
    {

    }
};

Ural::Application* Ural::CreateApplication()
{
	return new Sandbox();
}
