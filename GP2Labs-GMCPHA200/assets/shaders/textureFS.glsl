#version 150

in vec2 vertexTexCoordsOut;

uniform sampler2D texture0;

out vec4 FragColor;

void main()
{
	FragColor = texture(texture0, vertexTexCoordsOut);
}