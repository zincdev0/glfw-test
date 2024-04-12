#version 330 core

layout (location = 0) in vec3 vCol;
layout (location = 1) in vec2 vPos;

layout (location = 0) out vec3 color;

void main() {
	gl_Position = vec4(vPos, 0.0, 1.0);
	color = vCol;
}