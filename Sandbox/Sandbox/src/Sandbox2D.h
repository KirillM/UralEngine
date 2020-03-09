//
//  Sandbox2D.h
//  Sandbox
//
//  Created by Кирилл Мезрин on 07.03.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef Sandbox2D_h
#define Sandbox2D_h

#include "Ural.h"

class Sandbox2D : public Ural::Layer
{
public:
    Sandbox2D();
    virtual ~Sandbox2D() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    
    void OnUpdate(Ural::TimeStep ts) override;
    void OnEvent(Ural::Event& e) override;
private:
    Ural::OrthographicCameraController m_CameraController;

    Ural::Ref<Ural::VertexArray> m_SquareVA;
    Ural::Ref<Ural::Shader> m_FlatColorShader;

    Ural::Ref<Ural::Texture2D> m_Texture;
    
    glm::vec4 m_SquareColor = {0.2f, 0.3f, 0.8f, 1.0f};
};

#endif /* Sandbox2D_h */
