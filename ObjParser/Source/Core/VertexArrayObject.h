#pragma once

#include "Logging.h"
#include "VertexBufferObject.h"
#include <glad/glad.h>

struct AttribPointerLayout
{
	unsigned int index;
	unsigned int size;
	unsigned int stride;
	unsigned int offset;
};

class VertexArrayObject
{
public:
	VertexArrayObject();
	~VertexArrayObject();

	void Bind() const;
	void Unbind() const;
	void AddBuffer(const VertexBufferObject* vbo, const AttribPointerLayout layout);
private:
	unsigned int _Id;
};

