#version 330 core
out vec4 color;
in vec4 vertexColor;
uniform vec4 uniformColor;
void main()
{
    color = vertexColor + uniformColor;
} 