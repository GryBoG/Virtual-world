#pragma once
#include <string>
#include <fstream>
#include <sstream>

#include "Logging.h"

class Reader
{
public:
	static std::string Open(const char* filePath);
};