#version 330 core
out vec4 FragColor;

//uniform vec4 myColor;

//in vec3 myColor;

in vec4 outColor;

void main()
{
    FragColor = outColor;
    //FragColor = myColor;
}