//
//  VertexArray.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 23.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef VertexArray_hpp
#define VertexArray_hpp

#include "Renderer/Buffer.h"

namespace Ural {
    class VertexArray {
    public:
        virtual ~VertexArray() {};

        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;

        virtual void AddIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;
        virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;

        virtual std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() = 0;
        virtual std::shared_ptr<IndexBuffer>& GetIndexBuffer() = 0;

        static VertexArray* Create();
    };
}


#endif /* VertexArray_hpp */
