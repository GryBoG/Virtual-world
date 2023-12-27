#pragma once

#include<string>
#include<vector>

#include "Core/Shader.h"
#include "Core/Reader.h"
#include "Core/Vecs.h"

class Material
{
public:
	Material();
	Material(std::string filePath, Shader &shader);
	~Material();

	float specularExponent;
	Vector3f ambientColor;
	Vector3f diffuseColor;
	Vector3f specularColor;

private:
	Shader _shader;
	void SetUniforms();
	std::vector<std::string> SeparateString(std::string line, int startPos, std::string separator) const;
};

