#ifndef MAIN_HEADER
#define MAIN_HEADER

#include "Graphics.h"

namespace Main {
	void Awake();
	void Start();
	void Update();
	void GraphicsCode(Graphics* graphics);
	void TestFunc(Graphics* graphics);
	//void window_size_callback(GLFWwindow* window, int width, int height);
}

#endif