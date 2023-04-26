#version 330 core
out vec4 FragColor;

//uniform vec4 myColor;

//in vec3 myColor;

in vec4 outColor;
in vec2 texCoord;

uniform sampler2D container;
uniform sampler2D smileTexture;

void main()
{
    //FragColor = mix(texture(container,texCoord),texture(smileTexture,texCoord),0.2)*outColor;
    FragColor = mix(texture(container,texCoord),texture(smileTexture,texCoord),0.2);
    //FragColor = texture(smileTexture, texCoord);
    //FragColor = myColor;
}