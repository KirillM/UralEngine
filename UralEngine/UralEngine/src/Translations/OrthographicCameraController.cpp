//
//  OrthographicCameraController.cpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#include "OrthographicCameraController.h"
#include "Input/Desktop/DesktopInput.h"
#include "Input/Desktop/KeyCodes.h"

namespace Ural {

    OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation): m_AspectRatio(aspectRatio), m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel), m_Rotation(rotation)
    {

    }

 void SetProjection(float left, float right, float bottom, float top);

    void OrthographicCameraController::OnUpdate(TimeStep ts)
    {
        if (DesktopInput::IsKeyPressed(UL_KEY_A))
         {
             m_CameraPosition.x -= m_CameraTranslationSpeed * ts;
         } else if (DesktopInput::IsKeyPressed(UL_KEY_D))
         {
             m_CameraPosition.x += m_CameraTranslationSpeed * ts;
         }

         if (DesktopInput::IsKeyPressed(UL_KEY_W))
         {
             m_CameraPosition.y += m_CameraTranslationSpeed * ts;
         } else if (DesktopInput::IsKeyPressed(UL_KEY_S))
         {
             m_CameraPosition.y -= m_CameraTranslationSpeed * ts;
         }

        if (m_Rotation)
        {
            if (DesktopInput::IsKeyPressed(UL_KEY_Q))
            {
                m_CameraRotation += m_CameraRotationSpeed * ts;
            }

            if (DesktopInput::IsKeyPressed(UL_KEY_E))
            {
                m_CameraRotation -= m_CameraRotationSpeed * ts;
            }

            m_Camera.SetRotation(m_CameraRotation);
        }

        m_Camera.SetPostion(m_CameraPosition);

        m_CameraTranslationSpeed = m_ZoomLevel;
    }

    void OrthographicCameraController::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<MouseScrolledEvent>(UL_BIND_EVENT_FN(OrthographicCameraController::onMouseScrolled));
        dispatcher.Dispatch<WindowResizeEvent>(UL_BIND_EVENT_FN(OrthographicCameraController::onWindowResized));
    }

    bool OrthographicCameraController::onMouseScrolled(MouseScrolledEvent& e)
    {
        m_ZoomLevel -= e.GetYOffset() * 0.25f;
        m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
        m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
        return false;
    }

    bool OrthographicCameraController::onWindowResized(WindowResizeEvent& e)
    {
        m_AspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
        m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
        return false;
    }

}
