//
//  Input.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 22.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef Input_h
#define Input_h

namespace Ural {

    class Input
    {
    public:
        inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

        inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
        inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
        inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
        inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
    protected:
        virtual bool IsKeyPressedImpl(int keycode) = 0;

        virtual bool IsMouseButtonPressedImpl(int button) = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;
        virtual std::pair<float, float> GetMousePositionImpl() = 0;
    private:
        static Input* s_Instance;
    };

}


#endif /* Input_h */
