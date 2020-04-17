//
//  ShaderCompiler.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 17.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef ShaderCompiler_h
#define ShaderCompiler_h

namespace Ural {

    class ShaderCompiler {
    public:
        static bool isSupported();
        static void PrintSupportedShaderFormats();
        static void PrintSupportedProgramFormats();

        static uint32_t CurrentProgram();

        static void* GetProgramBinary(uint32_t programID, uint32_t binaryFormat);
        static void ReleaseCompiler();
    };

}

#endif /* ShaderCompiler_h */
