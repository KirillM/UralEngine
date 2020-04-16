//
//  Error.h
//  UralEngine
//
//  Created by Кирилл Мезрин on 15.04.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef Error_h
#define Error_h

namespace Ural {
    class Error {
    public:
        static uint8_t GetError();
        static std::string GetErrorString(uint8_t errorCode);
    };
}

#endif /* Error_h */
