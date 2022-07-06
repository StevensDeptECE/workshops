#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 v;
layout (location = 1) in float inval; // the value corresponding to each grid point comes in separately

uniform mat4 trans;
out float val;
void main(){
    gl_Position = trans * vec4(v,1.0);
    val = inval;
}

