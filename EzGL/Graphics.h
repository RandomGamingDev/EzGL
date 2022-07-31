#ifndef GRAPHICS_HEADER
#define GRAPHICS_HEADER

#include <iostream>
#include <any>

#ifdef GL_API_GLAD_OPENGL_3
#include <glad/glad.h>
#endif
#ifdef WINDOW_API_GLFW
#include <GLFW/glfw3.h>
#endif

#include"Camera.h"

#define arrsize(arr) sizeof(arr) / sizeof(arr[0])

class Graphics {
public:
	#ifdef WINDOW_API_GLFW
	GLFWwindow* window;
	#endif
	const char* title;
	int width, height;
	#ifdef WINDOW_API_GLFW
	GLFWmonitor* fullDisplay;
	#endif
	Camera camera;
	std::any data;

	Graphics();
	#ifdef WINDOW_API_GLFW
	Graphics(const char* title, int width, int height, GLFWmonitor* fullDisplay, void(*GraphicsCode)(Graphics*), std::any data);
	#endif
	~Graphics();

	#ifdef WINDOW_API_GLFW
	void Init(const char* title, int width, int height, GLFWmonitor* fullDisplay, void(*GraphicsCode)(Graphics*), std::any data);
	static void StaticInit(Graphics* graphics, const char* title, int width, int height, GLFWmonitor* fullDisplay, void(*GraphicsCode)(Graphics*), std::any data, GLFWwindow** windowVar, const char** titleVar, int* widthVar, int* heightVar, GLFWmonitor** fullDisplayVar, std::any* dataVar);
	#endif
	static void WindowLibInit();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Draw(GLsizei size, GLenum type);
	static void DrawInstanced(GLsizei size, GLenum type, GLsizei numInstances);
	#endif
	static void PollEvents();
	#ifdef WINDOW_API_GLFW
	void OnResizeEvent(GLFWwindowsizefun onResize);
	static void OnResizeEvent(GLFWwindow* window, GLFWwindowsizefun onResize);
	#endif
	void SwapBuffers();
	#ifdef WINDOW_API_GLFW
	static void SwapBuffers(GLFWwindow* window);
	#endif
	#ifdef GL_API_GLAD_OPENGL_3
	static void Enable(GLenum toEnable);
	static void Disable(GLenum toDisable);
	static void ClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	static void Clear(GLbitfield toClear);
	static void Blend(GLenum toBlend, GLenum howBlend);
	#endif
	static void Hint(int toHint, int value);
	#ifdef WINDOW_API_GLFW
	void CreateWindow(const char* title, int width, int height, GLFWmonitor* fullDisplay);
	static void CreateWindow(const char* title, int width, int height, GLFWmonitor* fullDisplay, GLFWwindow** windowVar, const char** titleVar, int* widthVar, int* heightVar, GLFWmonitor** fullDisplayVar);
	#endif
	void MakeContextCurrent();
	#ifdef WINDOW_API_GLFW
	static void MakeContextCurrent(GLFWwindow* window);
	#endif
	static void LoadGL();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Viewport(GLsizei topLeftX, GLsizei topLeftY, GLsizei bottomRightX, GLsizei bottomRightY);
	#endif
	void DestroyWindow();
	#ifdef WINDOW_API_GLFW
	static void DestroyWindow(GLFWwindow* window);
	#endif
	void SetTitle(const char* title);
	#ifdef WINDOW_API_GLFW
	static void SetTitle(GLFWwindow* window, const char* title);
	#endif
	int WindowShouldClose();
	#ifdef WINDOW_API_GLFW
	static int WindowShouldClose(GLFWwindow* window);
	#endif
	static void Terminate();
	template <typename type>
	type GetData();
	template <typename type>
	static type GetData(std::any data);
	template <typename type>
	void SetWindowPointer(type* ptr);
	#ifdef WINDOW_API_GLFW
	template <typename type>
	static void SetWindowPointer(GLFWwindow* window, type* ptr);
	#endif
	template <typename type>
	type* GetWindowPointer();
	#ifdef WINDOW_API_GLFW
	template <typename type>
	static type* GetWindowPointer(GLFWwindow* window);
	#endif
};

#include "Graphics.tpp"

#endif