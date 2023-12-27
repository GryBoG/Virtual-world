#include "VertexBufferObject.h"

VertexBufferObject::VertexBufferObject(std::vector<float> &data)
{
	glGenBuffers(1, &_Id);
	PRINT("VBO >> VBO generated " << data.size());
	//LogBuffer(data);

	Bind();
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), std::data(data), GL_STATIC_DRAW);
}

VertexBufferObject::~VertexBufferObject()
{
	glDeleteBuffers(1, &_Id);
}

void VertexBufferObject::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, _Id);
	PRINT("VBO >> Binding " << _Id);
}

void VertexBufferObject::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	PRINT("VBO >> Unbinding");
}

void VertexBufferObject::LogBuffer(std::vector<float> &data)
{
	for (int i = 0; i < data.size(); i++)
	{
		if (i % 8 == 0 && i < (data.size()))
		{
			PRINT("Vertex " <<  (i/8) << " [" << data[i] << "," << data[i + 1] << "," << data[i + 2] << "] :: [" << data[i+3] << "," << data[i+4] << "] :: [" << data[i+5] << "," << data[i + 6] << "," << data[i + 7] <<"]");
		}
	}
}
