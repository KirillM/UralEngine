//
//  OpenGLIndexBuffer.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 17.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLIndexBuffer_h
#define OpenGLIndexBuffer_h

#include "Renderer/Buffers/IndexBuffer.h"

namespace Ural {
    class OpenGLIndexBuffer : public IndexBuffer
     {
     public:
         OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
         ~OpenGLIndexBuffer();

          virtual void Bind() const override;
          virtual void UnBind() const override;

          virtual uint32_t GetCount() const override { return m_Count; }
     private:
         uint32_t m_BufferID;
         uint32_t m_Count;
     };
}

#endif /* OpenGLIndexBuffer_h */
