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
        
        static void* GetProgramBinary();
        static void ReleaseCompiler();
    };

}

#endif /* ShaderCompiler_h */
