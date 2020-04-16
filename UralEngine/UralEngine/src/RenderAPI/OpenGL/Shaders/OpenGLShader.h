//
//  OpenGLShader.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 16.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef OpenGLShader_h
#define OpenGLShader_h

#include "Renderer/Shaders/Shader.h"
#include "RenderAPI/OpenGL/Shaders/OpenGLShaderSlot.h"
#include "RenderAPI/OpenGL/Shaders/OpenGLShaderProgram.h"
#include <glm/glm.hpp>

typedef unsigned int GLenum;

namespace Ural {

    class OpenGLShader : public Shader
    {
    public:
        OpenGLShader(const std::string& filepath);
        OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
        ~OpenGLShader() = default;

        virtual void Bind() const override;
        virtual void UnBind() const override;

        virtual void SetInt(const std::string& name, int value) override;
        virtual void SetMat4(const std::string& name, const glm::mat4& value) override;
        virtual void SetFloat4(const std::string& name, const glm::vec4& value) override;
        virtual void SetFloat3(const std::string& name, const glm::vec3& value) override;

        virtual const std::string& GetName() const override { return m_Name; }

        void UploadUniformInt(const std::string& name, int value);

        void UploadUniformFloat(const std::string& name, float value);
        void UploadUniformFloat2(const std::string& name, const glm::vec2& vector);
        void UploadUniformFloat3(const std::string& name, const glm::vec3& vector);
        void UploadUniformFloat4(const std::string& name, const glm::vec4& vector);

        void UploadUniformMat3(const std::string& name, const glm::mat3& matrix);
        void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
    private:
        std::string ReadFile(const std::string& filepath);
        std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
        void Compile(const std::string& vertexSrc, const std::string& fragmentSrc);
    private:
        Ref<OpenGLShaderSlot> m_ShaderSlot;
        Scope<OpenGLShaderProgram> m_ShaderProgram;
        std::string m_Name;
    };
}

#endif /* OpenGLShader_h */
