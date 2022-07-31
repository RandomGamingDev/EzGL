#include "FBO.h"

#ifdef GL_API_GLAD_OPENGL_3

FBO::FBO() {
	Init();
}

FBO::~FBO() {
	Delete();
}

void FBO::Init() {
	Init(&ID);
}

#ifdef GL_API_GLAD_OPENGL_3

void FBO::Init(GLuint* ID) {
	glGenFramebuffers(1, ID);
	Bind(*ID);
}

#endif

void FBO::Bind() {
	Bind(ID);
} 

void FBO::Bind(GLuint ID) {
	glBindFramebuffer(GL_FRAMEBUFFER, ID);
}

void FBO::Unbind() {
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FBO::LinkTexture(GLuint texture) {
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);
}

void FBO::LinkRBO(GLuint RBO) {
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, RBO);
}

void FBO::Delete() {
	Delete(&ID);
}

void FBO::Delete(GLuint* ID) {
	glDeleteFramebuffers(1, ID);
}

#endif
