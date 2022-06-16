#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 color;

out vec3 rgb;
void main(){
    gl_Position.xyz = pos;
    gl_Position.w = 1.0;
    rgb = color;
}

