#ifndef TEXTURE_HEADER
#define TEXTURE_HEADER

#include<glad/glad.h>

class Texture2DMultisample {
public:
	GLuint ID;
	GLint width;
	GLint height;

	template <typename type>
	Texture2DMultisample(type* bytes, GLsizei width, GLsizei height, GLenum slot, GLenum format, GLenum pixelType);
	~Texture2DMultisample();

	template <typename type>
	void Init(type* bytes, GLint width, GLsizei height, GLenum slot, GLenum format, GLenum pixelType);
	template <typename type>
	static void Init(GLuint* ID, type* bytes, GLsizei width, GLsizei height, GLenum slot, GLenum format, GLenum pixelType, GLsizei* widthVar, GLsizei* heightVar);
	static void TexParameter(GLenum parameter, GLint value);
	void TexUnit(GLuint shader, const char* uniform, GLint unit);
	void Bind();
	static void Bind(GLuint ID);
	static void Unbind();
	void Delete();
	static void Delete(GLuint* ID);
};

#include "Texture2D.tpp"

#endif