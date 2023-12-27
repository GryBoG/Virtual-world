#pragma once
#include "Reader.h"

 std::string Reader::Open(const char* filePath)
{
	std::string streamString;
	std::ifstream file;
	// ensure ifstream objects can throw exceptions:
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// Open file
		file.open(filePath);
		std::stringstream stream;
		// Read file's buffer contents into streams
		stream << file.rdbuf();
		// Convert stream to string
		streamString = stream.str();
		file.close();
	}
	catch(std::ifstream::failure& e)
	{
		PRINT("ERROR: Could not read file at '" << filePath << "'");
	}
	
	return streamString;
}
