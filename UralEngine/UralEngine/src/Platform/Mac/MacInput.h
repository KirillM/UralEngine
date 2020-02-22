//
//  MacInput.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 22.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef MacInput_hpp
#define MacInput_hpp

#include "Input/Input.h"

namespace Ural {
    class MacInput : public Input
    {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;
        virtual bool IsMouseButtonPressedImpl(int button) override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
    };
}

#endif /* MacInput_hpp */
