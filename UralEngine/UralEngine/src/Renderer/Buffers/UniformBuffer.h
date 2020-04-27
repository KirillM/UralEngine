//
//  UniformBuffer.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 15.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef UniformBuffer_h
#define UniformBuffer_h

namespace Ural {
    class UniformBuffer
    {
    public:
        virtual ~UniformBuffer() = default;

        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;

        static Ref<UniformBuffer> Create(float* data, uint32_t size);
    };
}

#endif /* UniformBuffer_hpp */
