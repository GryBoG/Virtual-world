#pragma once

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

#include "Logging.h"
#include "Material.h"

struct FaceData
{
	int pos;
	int texCoord;
	int normal;

	FaceData()
	{
		pos = 0;
		texCoord = 0;
		normal = 0;
	};

	FaceData(int posIndex, int texIndex, int normIndex)
	{
		pos = (posIndex < 0) ? 0 : posIndex;
		texCoord = (texIndex < 0) ? 0 : texIndex;
		normal = (normIndex < 0) ? 0 : normIndex;
	}

	void Log()
	{
		PRINT("FaceData " << pos << "/" << texCoord << "/" << normal);
	}

	bool operator==(const FaceData& other) const
	{
		return pos == other.pos && texCoord == other.texCoord && normal == other.normal; // or another approach as above
	}
};

struct Vertex
{
	FaceData triplet;

	std::vector<float> position;
	std::vector<float> textureCoordinates;
	std::vector<float> normals;
	
	Vertex(FaceData t, float posX, float posY, float posZ, float texU, float texV, float normX, float normY, float normZ)
	{
		/*position.reserve(3);
		textureCoordinates.reserve(2);
		normals.reserve(3);*/

		triplet = t;

		SetPosition(posX, posY, posZ);
		SetTextureCoordinates(texU, texV);
		SetNormals(normX, normY, normZ);
		
	};

	void Log()
	{
		triplet.Log();
		PRINT("(" << position[0] << ", " << position[1] << ", " << position[2] << ") (" << textureCoordinates[0] << ", " << textureCoordinates[1] << ") (" << normals[0] << ", " << normals[1] << ", " << normals[2] << ")");
	}

	void SetPosition(float posX, float posY, float posZ)
	{
		position.push_back(posX);
		position.push_back(posY);
		position.push_back(posZ);
	}

	void SetNormals(float normX, float normY, float normZ)
	{
		normals.push_back(normX);
		normals.push_back(normY);
		normals.push_back(normZ);
	}

	void SetTextureCoordinates(float texU, float texV)
	{
		textureCoordinates.push_back(texU);
		textureCoordinates.push_back(texV);
	}

	bool operator==(const Vertex& other) const
	{
		return triplet == other.triplet; // or another approach as above
	}
};

class ModelLoader
{
public:
	ModelLoader(std::string directory, std::string file);
	~ModelLoader();

	std::string material;

	inline std::vector<float> &GetVertexData() { return _vertexData; };
	inline std::vector<unsigned int> &GetIndexData() { return _indexData; };

private:
	std::vector<float> _vertexData;
	std::vector<unsigned int> _indexData;

	std::vector<FaceData> _faceData;
	std::vector<Vertex> _vertData;

	std::vector<std::string> SeparateString(std::string line, int startPos, std::string separator) const;
	void GenerateVertexData(std::vector<float> &v, std::vector<float> &t, std::vector<float> &n);
	void GenerateIndexData();
	std::vector<int> ParseFaceData(std::string line, int startPos, char separator);
	
};

