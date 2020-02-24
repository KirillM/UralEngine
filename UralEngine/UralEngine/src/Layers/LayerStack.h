//
//  LayerStack.hpp
//  UralEngine
//
//  Created by Кирилл Мезрин on 22.02.2020.
//  Copyright © 2020 Кирилл Мезрин. All rights reserved.
//

#ifndef LayerStack_h
#define LayerStack_h

#include "Layer.h"

namespace Ural {

    class URAL_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer *layer);

        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_Layers.end(); }
    private:
        std::vector<Layer*> m_Layers;
        unsigned int m_LayerInsertIndex = 0;
    };
}

#endif /* LayerStack_h */
