#pragma once

#include <vector>
#include "Logging.h"
#include <glad/glad.h>

class IndexBuffer
{
public:
	IndexBuffer(std::vector<unsigned int> &data);
	~IndexBuffer();

	void Bind();
	void Unbind();
	void LogIndices(std::vector<unsigned int> &data);
	void LogIndices(std::vector<unsigned int> &indices, std::vector<float> &vertices);
private:
	unsigned int _Id;
};

