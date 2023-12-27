#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(std::vector<unsigned int> &data)
{
	glGenBuffers(1, &_Id);
	PRINT("IBO >> IBO generated. Indices size: " << data.size());
	//LogIndices(data);
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(unsigned int), std::data(data), GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &_Id);
}

void IndexBuffer::Bind()
{
	PRINT("IBO >> Binding " << _Id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _Id);
}

void IndexBuffer::Unbind()
{
	PRINT("IBO >> Unbinding");
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::LogIndices(std::vector<unsigned int> &data)
{
	for (int i = 0; i < data.size(); i++)
	{
		if (i % 3 == 0 && i < (data.size()))
		{
			PRINT("Index " << data[i] << "/" << data[i+1] << "/" << data[i+2]);
		}
	}
}

void IndexBuffer::LogIndices(std::vector<unsigned int> &indices, std::vector<float> &vertices)
{
	for (int i = 0; i < indices.size(); i++)
	{
		if (i % 3 == 0 && i < (indices.size()))
		{
			PRINT("Index " << indices[i] << "/" << indices[i + 1] << "/" << indices[i + 2] << " :: [" << 
				vertices[indices[i] * 8] << ", " << vertices[indices[i] * 8+1] << ", " << vertices[indices[i] * 8+2] << "] [" <<
				vertices[indices[i+1] * 8] << ", " << vertices[indices[i + 1] * 8+1] << ", " << vertices[indices[i + 1] * 8+2] << "] [" <<
				vertices[indices[i+2] * 8] << ", " << vertices[indices[i + 2] * 8+1] << ", " << vertices[indices[i + 2] * 8+2] << "]"
			);
		}
	}
}
