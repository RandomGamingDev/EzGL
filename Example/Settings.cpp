#include<iostream>
#include<thread>

#define STB_IMAGE_IMPLEMENTATION   
#include <stb_image.h>

#include"Main.h"

#include "EzGL.h"

int main() {
	Main::Awake();
	Graphics::WindowLibInit();
	Graphics::WindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	Graphics::WindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	Graphics::WindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	stbi_set_flip_vertically_on_load(true);
	Graphics graphics;
	const char* testString = "testString";
	std::thread mainGraphicsThread(&Graphics::Init, &graphics, "Testing", 2000, 800, nullptr, Main::GraphicsCode, testString);
	Graphics graphics2;
	std::thread mainGraphicsThread2(&Graphics::Init, &graphics2, "Testing", 800, 800, nullptr, Main::TestFunc, testString);
	Main::Start();
	while (true) Main::Update();
	mainGraphicsThread.join();
	mainGraphicsThread2.join();
	Graphics::Terminate();
	return 0;
}