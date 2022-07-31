#include "Graphics.h"

#ifdef GL_API_GLAD_OPENGL_3

#ifdef WINDOW_API_GLFW

Graphics::Graphics() {}

Graphics::Graphics(const char* title, int width, int height, GLFWmonitor* fullDisplay, void(*GraphicsCode)(Graphics*), std::any data) {
	Init(title, width, height, fullDisplay, GraphicsCode, data);
}

Graphics::~Graphics() {
	DestroyWindow();
}

void Graphics::Init(const char* title, int width, int height, GLFWmonitor* fullDisplay, void(*GraphicsCode)(Graphics*), std::any data) {
	StaticInit(this, title, width, height, fullDisplay, GraphicsCode, data, &this->window, &this->title, &this->width, &this->height, &this->fullDisplay, &this->data);
}

void Graphics::StaticInit(Graphics* graphics, const char* title, int width, int height, GLFWmonitor* fullDisplay, void(*GraphicsCode)(Graphics*), std::any data, GLFWwindow** windowVar, const char** titleVar, int* widthVar, int* heightVar, GLFWmonitor** fullDisplayVar, std::any* dataVar) {
	CreateWindow(title, width, height, fullDisplay, windowVar, titleVar, widthVar, heightVar, fullDisplayVar);
	MakeContextCurrent(*windowVar);
	LoadGL();
	Viewport(0, 0, width, height);
	SetWindowPointer<Graphics>(*windowVar, graphics);
	*dataVar = data;
	GraphicsCode(graphics);
}

void Graphics::WindowLibInit() {
	glfwInit();
}

void Graphics::Draw(GLsizei size, GLenum type) {
	glDrawElements(GL_TRIANGLES, size, type, 0);
}

void Graphics::DrawInstanced(GLsizei size, GLenum type, GLsizei numInstances) {
	glDrawElementsInstanced(GL_TRIANGLES, size, type, 0, numInstances);
}

void Graphics::PollEvents() {
	glfwPollEvents();
}

void Graphics::OnResizeEvent(GLFWwindowsizefun onResize) {
	OnResizeEvent(window, onResize);
}

void Graphics::OnResizeEvent(GLFWwindow* window, GLFWwindowsizefun onResize) {
	glfwSetWindowSizeCallback(window, onResize);
}

void Graphics::SwapBuffers() {
	SwapBuffers(window);
}

void Graphics::SwapBuffers(GLFWwindow* window) {
	glfwSwapBuffers(window);
}

void Graphics::Enable(GLenum toEnable) {
	glEnable(toEnable);
}

void Graphics::Disable(GLenum toDisable) {
	glDisable(toDisable);
}

void Graphics::ClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
	glClearColor(r, g, b, a);
}

void Graphics::Clear(GLbitfield toClear) {
	glClear(toClear);
}

void Graphics::Blend(GLenum toBlend, GLenum howBlend) {
	glBlendFunc(toBlend, howBlend);
}

void Graphics::Hint(int toHint, int value) {
	glfwWindowHint(toHint, value);
}

void Graphics::CreateWindow(const char* title, int width, int height, GLFWmonitor* fullDisplay) {
	CreateWindow(title, width, height, fullDisplay, &this->window, &this->title, &this->width, &this->height, &this->fullDisplay);
}

void Graphics::CreateWindow(const char* title, int width, int height, GLFWmonitor* fullDisplay, GLFWwindow** windowVar, const char** titleVar, int* widthVar, int* heightVar, GLFWmonitor** fullDisplayVar) {
	*titleVar = title;
	*widthVar = width;
	*heightVar = height;
	*fullDisplayVar = fullDisplay;
	*windowVar = glfwCreateWindow(width, height, title, fullDisplay, nullptr);
	if (windowVar == nullptr) {
		std::cout << "Failed to create window\n";
		return;
	}
}

void Graphics::MakeContextCurrent() {
	MakeContextCurrent(window);
}

void Graphics::MakeContextCurrent(GLFWwindow* window) {
	glfwMakeContextCurrent(window);
}

void Graphics::LoadGL() {
	gladLoadGL();
}

void Graphics::Viewport(GLsizei topLeftX, GLsizei topLeftY, GLsizei bottomRightX, GLsizei bottomRightY) {
	glViewport(topLeftX, topLeftY, bottomRightX, bottomRightY);
}

void Graphics::DestroyWindow() {
	DestroyWindow(window);
}

void Graphics::DestroyWindow(GLFWwindow* window) {
	glfwDestroyWindow(window);
}

void Graphics::SetTitle(const char* title) {
	SetTitle(window, title);
}

void Graphics::SetTitle(GLFWwindow* window, const char* title) {
	glfwSetWindowTitle(window, title);
}

int Graphics::WindowShouldClose() {
	return WindowShouldClose(window);
}

int Graphics::WindowShouldClose(GLFWwindow* window) {
	return glfwWindowShouldClose(window);
}

void Graphics::Terminate() {
	glfwTerminate();
}

#endif

#endif
