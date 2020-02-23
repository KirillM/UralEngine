//
//  main.cpp
//  Sandbox
//
//  Created by Кирилл Мезрин on 30/11/2019.
//  Copyright © 2019 Кирилл Мезрин. All rights reserved.
//

#include <iostream>
#include "Ural.h"

/*
 I disagree that simd math is absolutely necessary. It is simply not true that simd math is way faster in a huge and complex engine. There are a couple reasons for that. First, to make full use of simd, data needs to be stored in these registers as long as possible, which is often not the case. Second, simd sse data needs to be 16 byte aligned which can also decrease performance, e.g. because now you have to load more data in the cache than before and if you forgot to manually align it, it will be even slower. Yes the actual calculations are faster than non-simd, but simd is not the holy grail of graphics programming. And now the reason why i tell you this. Last year i thought exactly the same, because everyone teaches it. Now, i work with the guys who created the cryengine and did farcry, crysis etc. and they are not even using simd math. Back when they tried it it was actually slower in their engine. Another thing i want to mention is to have the abilitiy to question everything. Today, computer graphics is taught exclusively using matrix math. Guess what? Cryengine does not use it except in a few cases (Mainly for projection). Matrices are slow and have to much unnecessary data. I would argue that replacing matrices with something else (we use dual-quats and qtangents) it is way faster than using simd math. Have a nice day! :)

 34



 */
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
glm::mat4 camera(float Translate, glm::vec2 const & Rotate)
{
    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.f);
    glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
    View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
    View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
    return Projection * View * Model;
}

class ExampleLayer: public Ural::Layer
{
public:
    ExampleLayer() : Layer("Example")
    {
        auto cam = camera(5.0f, {0.5f, 0.5f});
    }

    void OnUpdate() override
    {
        UL_INFO("ExampleLayer::Update");

        if(Ural::Input::IsKeyPressed(UL_KEY_TAB))
            UL_INFO("Tab key is pressed!");
    }

    void OnEvent(Ural::Event& event) override
    {
       // UL_TRACE("{0}", event);
    }
};

class Sandbox : public Ural::Application
{
public:
    Sandbox()
    {
       // PushOverlay(new ExampleLayer());
       // PushOverlay(new Ural::ImGuiLayer());
    }

    ~Sandbox()
    {

    }
};

Ural::Application* Ural::CreateApplication()
{
	return new Sandbox();
}
