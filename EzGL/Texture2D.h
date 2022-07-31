#ifndef TEXTURE_HEADER
#define TEXTURE_HEADER

#ifdef GL_API_GLAD_OPENGL_3
#include <glad/glad.h>
#endif

class Texture2D {
public:
	#ifdef GL_API_GLAD_OPENGL_3
	GLuint ID;
	GLint width;
	GLint height;
	#endif

	#ifdef GL_API_GLAD_OPENGL_3
	template <typename type>
	Texture2D(type* bytes, GLsizei width, GLsizei height, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType);
	#endif
	~Texture2D();

	#ifdef GL_API_GLAD_OPENGL_3
	template <typename type>
	void Init(type* bytes, GLint width, GLsizei height, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType);
	template <typename type>
	static void Init(GLuint* ID, type* bytes, GLsizei width, GLsizei height, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType, GLsizei* widthVar, GLsizei* heightVar);
	static void TexParameter(GLenum parameter, GLint value);
	void TexUnit(GLuint shader, const char* uniform, GLint unit);
	template <typename type>
	void Data(GLint level, GLint internalFormat, GLenum format, GLenum pixelType, type* bytes);
	template <typename type>
	static void Data(GLsizei width, GLsizei height, GLint level, GLint internalFormat, GLenum format, GLenum pixelType, type* bytes);
	#endif
	void Bind();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Bind(GLuint ID);
	#endif
	static void Unbind();
	void Delete();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Delete(GLuint* ID);
	#endif
};

#include "Texture2D.tpp"

#endif