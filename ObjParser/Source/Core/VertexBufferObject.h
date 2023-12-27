#pragma once

#include <vector>
#include "Logging.h"
#include <glad/glad.h>

class VertexBufferObject
{
public:
	VertexBufferObject(std::vector<float> &data);
	~VertexBufferObject();

	void Bind() const;
	void Unbind() const;
	void LogBuffer(std::vector<float> &data);
private:
	unsigned int _Id;
};

