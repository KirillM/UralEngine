//
//  OrthographicCameraController.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 07.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OrthographicCameraController_h
#define OrthographicCameraController_h


#include "Time/TimeStep.h"
#include "Renderer/OrthographicCamera.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"

namespace Ural {

    class OrthographicCameraController
    {
    public:
        OrthographicCameraController(float aspectRatio, bool rotation = false);

        void OnUpdate(TimeStep ts);
        void OnEvent(Event& e);

        OrthographicCamera& GetCamera() { return m_Camera; }
        const OrthographicCamera& GetCamera() const { return m_Camera; }

        float GetZoomLevel() { return m_ZoomLevel; }
        void SetZoomLevel(float level) { m_ZoomLevel = level; }
    private:
        bool onMouseScrolled(MouseScrolledEvent& e);
        bool onWindowResized(WindowResizeEvent& e);
    private:
        float m_AspectRatio;
        float m_ZoomLevel = 1.0f;
        OrthographicCamera m_Camera;

        bool m_Rotation;
        glm::vec3 m_CameraPosition = {0.0f, 0.0f, 0.0f};
        float m_CameraRotation = 0.0f;
        float m_CameraTranslationSpeed = 5.0f, m_CameraRotationSpeed = 180.0f;
    };
}

#endif /* OrthographicCameraController_h */
