	const char* fragmentSource = R"(
#version 460 core

out vec4 FragColor;  

in vec4 ourColor;

void main() {
    FragColor = ourColor;
}
 )";
