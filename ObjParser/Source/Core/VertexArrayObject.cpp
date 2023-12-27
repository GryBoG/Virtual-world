#include "VertexArrayObject.h"

VertexArrayObject::VertexArrayObject()
{
	glGenVertexArrays(1, &_Id);
	Bind();

	PRINT("VAO >> VAO generated and bound.");
}

VertexArrayObject::~VertexArrayObject()
{
	glDeleteVertexArrays(1, &_Id);
}

void VertexArrayObject::Bind() const
{
	glBindVertexArray(_Id);
}

void VertexArrayObject::Unbind() const
{
	glBindVertexArray(0);
}

void VertexArrayObject::AddBuffer(const VertexBufferObject* vbo, const AttribPointerLayout layout)
{
	vbo->Bind();
	PRINT("VAO >> Attrib Pointer enabled: " << layout.index << " " << layout.size << " " << layout.stride << " " << layout.offset);
	glVertexAttribPointer(layout.index, layout.size, GL_FLOAT, GL_FALSE, layout.stride * sizeof(float), (const void*)(layout.offset * sizeof(float)));
	glEnableVertexAttribArray(layout.index);
}
