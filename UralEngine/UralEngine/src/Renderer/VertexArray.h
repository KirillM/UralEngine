//
//  VertexArray.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 17.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef VertexArray_h
#define VertexArray_h

#include "Renderer/Buffers/VertexBuffer.h"
#include "Renderer/Buffers/IndexBuffer.h"

namespace Ural {
    class VertexArray {
    public:
        virtual ~VertexArray() = default;

        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;

        virtual void AddIndexBuffer(const Ref<IndexBuffer>& indexBuffer) = 0;
        virtual void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) = 0;

        virtual std::vector<Ref<VertexBuffer>>& GetVertexBuffers() = 0;
        virtual Ref<IndexBuffer>& GetIndexBuffer() = 0;

        static Ref<VertexArray> Create();
    };
}


#endif /* VertexArray_h */
