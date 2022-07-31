#include "Texture2DMultisample.h"

Texture2DMultisample::~Texture2DMultisample() {
	Delete();
}

void Texture2DMultisample::TexParameter(GLenum parameter, GLint value) {
	glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, parameter, value);
}

void Texture2DMultisample::TexUnit(GLuint shader, const char* uniform, GLint unit) {
	glUseProgram(ID);
	glUniform1i(glGetUniformLocation(shader, uniform), unit);
}

void Texture2DMultisample::Bind() {
	Bind(ID);
}

void Texture2DMultisample::Bind(GLuint ID) {
	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, ID);
}

void Texture2DMultisample::Unbind() {
	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, 0);
}

void Texture2DMultisample::Delete() {
	Delete(&ID);
}

void Texture2DMultisample::Delete(GLuint* ID) {
	glDeleteTextures(1, ID);
}
