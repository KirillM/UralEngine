//
//  TimeStep.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 24.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef TimeStep_h
#define TimeStep_h

namespace Ural {

    class TimeStep
    {
    public:
        TimeStep(float time = 0.0f) : m_Time(time) {}

        operator float() const { return m_Time; }

        float GetSeconds() const { return m_Time; }
        float GetMilliseconds() const { return m_Time / 1000; }
    private:
        float m_Time;
    };
}

#endif /* TimeStep_h */
