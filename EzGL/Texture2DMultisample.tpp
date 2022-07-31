#ifndef TEXTURE2DMULTISAMPLE_TEMPLATE
#define TEXTURE2DMULTISAMPLE_TEMPLATE

template <typename type>
Texture2DMultisample::Texture2DMultisample(type* bytes, GLsizei width, GLsizei height, GLenum slot, GLenum format, GLenum pixelType) {
	Init<type>(bytes, width, height, slot, format, pixelType);
}

template <typename type>
void Texture2DMultisample::Init(type* bytes, GLint width, GLsizei height, GLenum slot, GLenum format, GLenum pixelType) {
	Init<type>(&ID, bytes, width, height, slot, format, pixelType, &this->width, &this->height);
}

template <typename type>
void Texture2DMultisample::Init(GLuint* ID, type* bytes, GLsizei width, GLsizei height, GLenum slot, GLenum format, GLenum pixelType, GLsizei* widthVar, GLsizei* heightVar) {
	*widthVar = width;
	*heightVar = height;

	glGenTextures(1, ID);
	glActiveTexture(slot);
	Bind(*ID);
	Data<type>(width, height, 0, format, pixelType, bytes);
}

#endif
