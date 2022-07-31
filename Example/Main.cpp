#include <iostream>
#include <filesystem>
#include <array>

#include "EzGL.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <stb_image.h>

#include "Main.h"

const std::string parentDir = std::filesystem::current_path().string();

bool firstClick = true;
float speed = 0.1f, sensitivity = 100.0f;

void Inputs(Camera* camera, GLFWwindow* window) {
	// Handles key inputs
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		camera->Position += speed * camera->Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		camera->Position += speed * -glm::normalize(glm::cross(camera->Orientation, camera->Up));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		camera->Position += speed * -camera->Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		camera->Position += speed * glm::normalize(glm::cross(camera->Orientation, camera->Up));
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		camera->Position += speed * camera->Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
		camera->Position += speed * -camera->Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		speed = 0.0001f;
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE) {
		speed = 0.01f;
	}


	// Handles mouse inputs
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		// Hides mouse cursor
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		// Prevents camera from jumping on the first click
		if (firstClick) {
			glfwSetCursorPos(window, (camera->width / 2), (camera->height / 2));
			firstClick = false;
		}

		// Stores the coordinates of the cursor
		double mouseX;
		double mouseY;
		// Fetches the coordinates of the cursor
		glfwGetCursorPos(window, &mouseX, &mouseY);

		// Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
		// and then "transforms" them into degrees 
		float rotX = sensitivity * (float)(mouseY - (camera->height / 2)) / camera->height;
		float rotY = sensitivity * (float)(mouseX - (camera->width / 2)) / camera->width;

		// Calculates upcoming vertical change in the Orientation
		glm::vec3 newOrientation = glm::rotate(camera->Orientation, glm::radians(-rotX), glm::normalize(glm::cross(camera->Orientation, camera->Up)));

		// Decides whether or not the next vertical Orientation is legal or not
		if (abs(glm::angle(newOrientation, camera->Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
			camera->Orientation = newOrientation;

		// Rotates the Orientation left and right
		camera->Orientation = glm::rotate(camera->Orientation, glm::radians(-rotY), camera->Up);

		// Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
		glfwSetCursorPos(window, (camera->width / 2), (camera->height / 2));
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
		// Unhides cursor since camera is not looking around anymore
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		// Makes sure the next time the camera looks around it doesn't jump
		firstClick = true;
	}
}

//Awake starts before anything else
void Main::Awake() {
	std::cout << "The program is awake!\nWireframe is starting...\n";
}

//Start starts after WireframeInit
void Main::Start() {
	std::cout << "Wireframe has started!\n";
}

//Update loops
void Main::Update() {
	std::cout << "This should be looping on a seperate thread\n";
}

GLfloat vertices[] =
{ //     COORDINATES     /        COLORS              /   TexCoord  //
	-0.5f, 0.0f,  0.5f,     0.0f, 0.0f, 0.0f, 0.0f,    0.0f, 0.0f, // Bottom
	-0.5f, 0.0f, -0.5f,     0.0f, 0.0f, 0.0f, 0.0f,    0.0f, 0.5f,
	 0.5f, 0.0f, -0.5f,     0.0f, 0.0f, 0.0f, 0.0f,	   0.5f, 0.5f,
	 0.5f, 0.0f,  0.5f,     0.0f, 0.0f, 0.0f, 0.0f,	   0.5f, 0.0f,
	-0.5f, 1.0f,  0.5f,     0.0f, 0.0f, 0.0f, 0.0f,	   0.5f, 0.5f, // Top
	-0.5f, 1.0f, -0.5f,     0.0f, 0.0f, 0.0f, 0.0f,	   0.5f, 1.0f,
	 0.5f, 1.0f, -0.5f,     0.0f, 0.0f, 0.0f, 0.0f,	   1.0f, 1.0f,
	 0.5f, 1.0f,  0.5f,     0.0f, 0.0f, 0.0f, 0.0f,	   1.0f, 0.5f,
	-0.5f, 1.0f,  0.5f,     0.0f, 0.0f, 0.0f, 0.0f,	   0.5f, 1.0f, // Side // Top Right
	-0.5f, 0.0f,  0.5f,     0.0f, 0.0f, 0.0f, 0.0f,	   0.5f, 0.5f, // Bottom Right
	-0.5f, 1.0f, -0.5f,     0.0f, 0.0f, 0.0f, 0.0f,	   0.0f, 1.0f
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3,
	6, 5, 4,
	7, 6, 4,
	1, 9, 8,
	10, 1, 8
};

GLfloat rectangleVertices[] =
{
	// Coords    // texCoords
	 1.0f, -1.0f,  1.0f, 0.0f,
	-1.0f, -1.0f,  0.0f, 0.0f,
	-1.0f,  1.0f,  0.0f, 1.0f,

	 1.0f,  1.0f,  1.0f, 1.0f,
	 1.0f, -1.0f,  1.0f, 0.0f,
	-1.0f,  1.0f,  0.0f, 1.0f
};

void OnResize(GLFWwindow* window, int width, int height) {
	if (width == 0 || height == 0) return;
	Graphics::Viewport(0, 0, width, height);
	Graphics* graphics = Graphics::GetWindowPointer<Graphics>(window);
	graphics->width = width;
	graphics->height = height;
	graphics->camera.Resize(width, height);
}

// Make this pass the graphics class instead
void Main::GraphicsCode(Graphics* graphics) {
	// Make it so that this works not just with files, but so that you can get the file output and then input it
	ShaderData shaders[] = { 
		ShaderData(Shader::GetShaderData("default.vert"), GL_VERTEX_SHADER, "VERT"), 
		ShaderData(Shader::GetShaderData("default.frag"), GL_FRAGMENT_SHADER, "FRAG")
	};
	Shader shader(shaders, arrsize(shaders));
	ShaderData FBOshaders[] = {
		ShaderData(Shader::GetShaderData("FBO.vert"), GL_VERTEX_SHADER, "VERT"),
		ShaderData(Shader::GetShaderData("FBO.frag"), GL_FRAGMENT_SHADER, "FRAG")
	};
	Shader FBOshader(FBOshaders, arrsize(FBOshaders));
	FBOshader.Activate();

	FBOshader.Activate();
	glUniform1i(glGetUniformLocation(FBOshader.ID, "screenTexture"), 0);

	VAO VAO1;
	VAO1.Bind();

	VBO<GLfloat> VBO1(vertices, sizeof(vertices), GL_STATIC_DRAW);

	EBO<GLuint> EBO1(indices, sizeof(indices), GL_STATIC_DRAW);
	
	GLint test = 10;
	UBO UBO1(&test, sizeof(GLint), GL_STATIC_DRAW, "test", shader.ID, 0);
	UBO1.Unbind();
	UBO1.BindBase(0);

	VAO1.LinkAttrib<GLfloat>(VBO1.ID, 0, 3, GL_FLOAT, 9, 0);
	VAO1.LinkAttrib<GLfloat>(VBO1.ID, 1, 4, GL_FLOAT, 9, 3);
	VAO1.LinkAttrib<GLfloat>(VBO1.ID, 2, 2, GL_FLOAT, 9, 7);
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	unsigned int rectVAO, rectVBO;
	glGenVertexArrays(1, &rectVAO);
	glGenBuffers(1, &rectVBO);
	glBindVertexArray(rectVAO);
	glBindBuffer(GL_ARRAY_BUFFER, rectVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(rectangleVertices), &rectangleVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));


	auto fboStatus = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if (fboStatus != GL_FRAMEBUFFER_COMPLETE)
		std::cout << "Framebuffer error:" << fboStatus << std::endl;

	int width, height, numColorChannels;
	stbi_uc* bytes = stbi_load((parentDir + "/Textures/test.png").c_str(), &width, &height, &numColorChannels, 0);
	Texture2D brickTex(bytes, width, height, GL_TEXTURE0, GL_RGBA, GL_RGB, GL_UNSIGNED_BYTE);
	brickTex.Unbind();
	stbi_image_free(bytes);
	brickTex.TexUnit(shader.ID, "tex0", 0);

	//Enable(GL_DEPTH_TEST);

	//Enable(GL_CULL_FACE);

	graphics->Enable(GL_BLEND);

	graphics->Blend(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	graphics->camera.Resize(graphics->width, graphics->height, glm::vec3(0.0f, 0.0f, 2.0f));

	VBO1.Bind();
	VAO1.Bind();

	while (!graphics->WindowShouldClose()) {
		//std::cout << std::any_cast<const char*>(graphics->data);
		FBO	FBO1 = FBO();

		Texture2D frameBufTex = Texture2D(static_cast<char*>(nullptr), graphics->width, graphics->height, GL_TEXTURE0, GL_RGBA, GL_RGB, GL_UNSIGNED_BYTE);
		frameBufTex.TexParameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		frameBufTex.TexParameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		FBO1.LinkTexture(frameBufTex.ID);

		RBO RBO1 = RBO(GL_DEPTH24_STENCIL8, graphics->width, graphics->height);
		FBO1.LinkRBO(RBO1.ID);

		VBO1.Bind();
		VAO1.Bind();
		graphics->SetTitle("ballz");
		FBO1.Bind();

		graphics->ClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		graphics->Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		graphics->Enable(GL_DEPTH_TEST);

		shader.Activate();

		Inputs(&graphics->camera, graphics->window);
		graphics->camera.Matrix(45.0f, 0.1f, 100.0f, shader.ID, "camMatrix");

		brickTex.Bind();
		
		vertices[0] += 0.0001f;

		void* ptr = VBO1.Map(GL_WRITE_ONLY);
		memcpy(ptr, vertices, sizeof(vertices));
		VBO1.Unmap();

		graphics->DrawInstanced(arrsize(indices), GL_UNSIGNED_INT, 2);
		
		brickTex.Unbind();
		
		VBO1.Unbind();
		VAO1.Unbind();

		FBO1.Unbind();

		FBOshader.Activate();
		glBindVertexArray(rectVAO);
		graphics->Disable(GL_DEPTH_TEST);
		frameBufTex.Bind();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
		frameBufTex.Unbind();

		graphics->PollEvents();
		graphics->OnResizeEvent(OnResize);
		graphics->SwapBuffers();
	}
}

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

void Main::TestFunc(Graphics* graphics) {
	// Create Vertex Shader Object and get its reference
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// Attach Vertex Shader source to the Vertex Shader Object
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(vertexShader);

	// Create Fragment Shader Object and get its reference
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// Attach Fragment Shader source to the Fragment Shader Object
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(fragmentShader);

	// Create Shader Program Object and get its reference
	GLuint shaderProgram = glCreateProgram();
	// Attach the Vertex and Fragment Shaders to the Shader Program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	// Wrap-up/Link all the shaders together into the Shader Program
	glLinkProgram(shaderProgram);

	// Delete the now useless Vertex and Fragment Shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);



	// Vertices coordinates
	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
		-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
		0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
		0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
	};

	// Indices for vertices order
	GLuint indices[] =
	{
		0, 3, 5, // Lower left triangle
		3, 2, 4, // Lower right triangle
		5, 4, 1 // Upper triangle
	};

	// Create reference containers for the Vartex Array Object, the Vertex Buffer Object, and the Element Buffer Object
	GLuint VAO, VBO, EBO;

	// Generate the VAO, VBO, and EBO with only 1 object each
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Make the VAO the current Vertex Array Object by binding it
	glBindVertexArray(VAO);

	// Bind the VBO specifying it's a GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Introduce the vertices into the VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Bind the EBO specifying it's a GL_ELEMENT_ARRAY_BUFFER
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	// Introduce the indices into the EBO
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Configure the Vertex Attribute so that OpenGL knows how to read the VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// Enable the Vertex Attribute so that OpenGL knows to use it
	glEnableVertexAttribArray(0);

	// Bind both the VBO and VAO to 0 so that we don't accidentally modify the VAO and VBO we created
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	// Bind the EBO to 0 so that we don't accidentally modify it
	// MAKE SURE TO UNBIND IT AFTER UNBINDING THE VAO, as the EBO is linked in the VAO
	// This does not apply to the VBO because the VBO is already linked to the VAO during glVertexAttribPointer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);



	// Main while loop
	while (!glfwWindowShouldClose(graphics->window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		glUseProgram(shaderProgram);
		// Bind the VAO so OpenGL knows to use it
		glBindVertexArray(VAO);
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(graphics->window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(shaderProgram);
	// Delete window before ending the program
	glfwDestroyWindow(graphics->window);
}