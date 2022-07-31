#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;


// Inputs the color from the Vertex Shader
in vec4 color;
// Inputs the texture coordinates from the Vertex Shader
in vec2 texCoord;

// Gets the Texture Unit from the main function
uniform sampler2D tex0;

void main()
{
	//FragColor = texture(tex0, texCoord);
	//FragColor = texture(tex0, texCoord) * vec4(0.8f, 0.3f, 0.02f, 1.0f);
	//FragColor = texture(tex0, texCoord) * vec4(0.83f, 0.70f, 0.44f);
	FragColor = texture(tex0, texCoord) + color;
}