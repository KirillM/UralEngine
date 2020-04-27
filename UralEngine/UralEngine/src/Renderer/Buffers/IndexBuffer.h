//
//  IndexBuffer.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 15.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef IndexBuffer_h
#define IndexBuffer_h

#pragma GCC visibility push(default)

namespace Ural {
    class IndexBuffer
    {
    public:
        virtual ~IndexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;

        virtual uint32_t GetCount() const = 0;
        static Ref<IndexBuffer> Create(uint32_t* indices, uint32_t count);
    };
}

#pragma GCC visibility pop

#endif /* IndexBuffer_hpp */
