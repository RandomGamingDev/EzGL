#ifndef TEXTURE2D_TEMPLATE
#define TEXTURE2D_TEMPLATEa

#ifdef GL_API_GLAD_OPENGL_3

template <typename type>
Texture2D::Texture2D(type* bytes, GLsizei width, GLsizei height, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType) {
	Init<type>(bytes, width, height, slot, internalFormat, format, pixelType);
}

template <typename type>
void Texture2D::Init(type* bytes, GLint width, GLsizei height, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType) {
	Init<type>(&ID, bytes, width, height, slot, internalFormat, format, pixelType, &this->width, &this->height);
}

template <typename type>
void Texture2D::Init(GLuint* ID, type* bytes, GLsizei width, GLsizei height, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType, GLsizei* widthVar, GLsizei* heightVar) {
	*widthVar = width;
	*heightVar = height;

	glGenTextures(1, ID);
	glActiveTexture(slot);
	Bind(*ID);
	Data<type>(width, height, 0, internalFormat, format, pixelType, bytes);
	glGenerateMipmap(GL_TEXTURE_2D);
}

template <typename type>
void Texture2D::Data(GLint level, GLint internalFormat, GLenum format, GLenum pixelType, type* bytes) {
	Data<type>(width, height, level, internalFormat, format, pixelType, bytes);
}

template <typename type>
void Texture2D::Data(GLsizei width, GLsizei height, GLint level, GLint internalFormat, GLenum format, GLenum pixelType, type* bytes) {
	GLint detail = level == 0 ? 1 : 2 * level;
	glTexImage2D(GL_TEXTURE_2D, level, internalFormat, width / detail, height / detail, 0, format, pixelType, bytes);
}

#endif

#endif
