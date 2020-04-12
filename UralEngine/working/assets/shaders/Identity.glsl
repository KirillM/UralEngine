
#type vertex

#version 330

// внутри себя шейдеры работают с vec4

in vec4 a_Postion; // в каждом шейдере можно иметь максимум 16 аттрибутов
in vec4 a_Color;

out vec4 v_Color;

void main(void) {
    v_Color = a_Color;
    gl_Position = a_Position;
}


// vertex out v_Color == fragment in v_Color
#type fragment

#version 330

in vec4 v_Color; // в каждом шейдере можно иметь максимум 16 аттрибутов

out vec4 v_FragColor; // любой out идет в цвет fragment

void main(void) {
    v_FragColor = v_Color;
}
