#include "UBO.h"

#ifdef GL_API_GLAD_OPENGL_3

UBO::~UBO() {
	Delete();
}

void UBO::Unmap() {
	glUnmapBuffer(GL_UNIFORM_BUFFER);
}

void UBO::Bind() {
	Bind(ID);
}

void UBO::Bind(GLuint ID) {
	glBindBuffer(GL_UNIFORM_BUFFER, ID);
}

void UBO::Unbind() {
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void UBO::BindBase(GLuint index) {
	BindBase(ID, index);
}

void UBO::BindBase(GLuint ID, GLuint index) {
	glBindBufferBase(GL_UNIFORM_BUFFER, index, ID);
}

void UBO::UnbindBase(GLuint index) {
	glBindBufferBase(GL_UNIFORM_BUFFER, index, 0);
}


void UBO::BindRange(GLuint index, GLuint offset, GLsizeiptr size) {
	BindRange(ID, index, offset, size);
}

void UBO::BindRange(GLuint ID, GLuint index, GLuint offset, GLsizeiptr size) {
	glBindBufferRange(GL_UNIFORM_BUFFER, index, ID, offset, size);
}

void UBO::UnbindRange(GLuint index, GLuint offset, GLsizeiptr size) {
	glBindBufferRange(GL_UNIFORM_BUFFER, index, 0, offset, size);
}

void UBO::Delete() {
	Delete(&ID);
}

void UBO::Delete(GLuint* ID) {
	glDeleteBuffers(1, ID);
}

#endif
