#pragma once

#include "Logging.h"
#include "glad/glad.h"
#include "Vendor/stb_image.h"

class Texture
{
public:
	Texture(std::string);
	~Texture();

	void Bind(unsigned int slot = 0);
private:
	unsigned int _textureId;
};

