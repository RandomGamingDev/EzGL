#version 330 core

// Positions/Coordinates
layout (location = 0) in vec3 aPos;
// Colors
layout (location = 1) in vec4 aColor;
// Texture Coordinates
layout (location = 2) in vec2 aTex;


// Outputs the color for the Fragment Shader
out vec4 color;
// Outputs the texture coordinates to the fragment shader
out vec2 texCoord;

// Imports the camera matrix from the main function
layout (std140) uniform test {
	int testing;
};
uniform mat4 camMatrix;

void main() {
	vec3 offsets[2] = { vec3(testing), vec3(1.5) };
	// You should be able to rotate here
	// Outputs the positions/coordinates of all vertices
	gl_Position = camMatrix * vec4(aPos + offsets[gl_InstanceID], 1.0);
	// Assigns the colors from the Vertex Data to "color"
	color = aColor;
	// Assigns the texture coordinates from the Vertex Data to "texCoord"
	texCoord = aTex;
}