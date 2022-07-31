#ifndef FBO_HEADER
#define FBO_HEADER

#ifdef GL_API_GLAD_OPENGL_3
#include <glad/glad.h>
#endif

class FBO {
public:
	#ifdef GL_API_GLAD_OPENGL_3
	GLuint ID;
	#endif
	
	FBO();
	~FBO();

	void Init();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Init(GLuint* ID);
	#endif
	void Bind();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Bind(GLuint ID);
	#endif
	static void Unbind();
	#ifdef GL_API_GLAD_OPENGL_3
	static void LinkTexture(GLuint texture);
	static void LinkRBO(GLuint RBO);
	#endif
	void Delete();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Delete(GLuint* ID);
	#endif
};

#endif