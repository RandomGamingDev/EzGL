#include "Texture2D.h"

#ifdef GL_API_GLAD_OPENGL_3

Texture2D::~Texture2D() {
	Delete();
}

void Texture2D::TexParameter(GLenum parameter, GLint value) {
	glTexParameteri(GL_TEXTURE_2D, parameter, value);
}

void Texture2D::TexUnit(GLuint shader, const char* uniform, GLint unit) {
	glUseProgram(ID);
	glUniform1i(glGetUniformLocation(shader, uniform), unit);
}

void Texture2D::Bind() {
	Bind(ID);
}

void Texture2D::Bind(GLuint ID) {
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture2D::Unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::Delete() {
	Delete(&ID);
}

void Texture2D::Delete(GLuint* ID) {
	glDeleteTextures(1, ID);
}

#endif
