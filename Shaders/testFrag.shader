#version 330 core
out vec4 FragColor;

//uniform vec4 myColor;

//in vec3 myColor;

in vec4 outColor;
in vec2 texCoord;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture,texCoord);
    //FragColor = myColor;
}