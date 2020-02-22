//
//  MacInput.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 22.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "MacInput.h"
#include <GLFW/glfw3.h>
#include "Ural/Application.h"

namespace Ural {

    Input* Input::s_Instance = new MacInput();

    bool MacInput::IsKeyPressedImpl(int keycode)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool MacInput::IsMouseButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    float MacInput::GetMouseXImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);
        return (float)xPos;
    }

    float MacInput::GetMouseYImpl()
    {
       // auto[x, y] = GetMousePositionImpl();
        
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);
        return (float)yPos;
    }

    std::pair<float, float> MacInput::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);
        return { (float)xPos, (float)yPos };
    }
}
