#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 v;

//uniform vec3 minColor;
//uniform vec3 maxColor;
//uniform float minVal;
//uniform float maxVal;

uniform mat4 trans;
out float val;
void main(){
    gl_Position = trans * vec4(v,1.0);
    val = v.z;
}

