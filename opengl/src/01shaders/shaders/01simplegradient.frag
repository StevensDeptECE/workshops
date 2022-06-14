#version 330 core

out vec4 FragColor;  

in vec2 TexCoord;

void main() {
   vec2 p = TexCoord;
   vec3 c = vec3(1,0,0); //red
    // Output to screen
    FragColor = vec4(p.x*c,1.0);
}
