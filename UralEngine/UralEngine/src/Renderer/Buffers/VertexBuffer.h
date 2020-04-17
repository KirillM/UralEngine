//
//  VertexBuffer.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 15.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef VertexBuffer_h
#define VertexBuffer_h

namespace Ural {
    class VertexBuffer {
    public:
        virtual ~VertexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;

        static VertexBuffer* Create(float* vertices, uint32_t size);
    };
}

#endif /* VertexBuffer_hpp */
