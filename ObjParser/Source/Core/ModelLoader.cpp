#include "ModelLoader.h"

ModelLoader::ModelLoader(std::string directory, std::string file)
{
	std::ifstream infile;
	infile.open(directory + "/" + file);

	std::vector<std::string> d;

	std::vector<float> vertPos;
	std::vector<float> texCoords;
	std::vector<float> normals;


	for (std::string currentLine; std::getline(infile, currentLine); )
	{
		if (currentLine.find("v ", 0) != currentLine.npos)
		{
			d = SeparateString(currentLine, 2, " ");
			for (int i = 0; i < d.size(); i++)
			{
				vertPos.push_back(std::stof(d[i]));
			}
		}
		else if (currentLine.find("vt", 0) != currentLine.npos)
		{
			d = SeparateString(currentLine, 2, " ");
			for (int i = 0; i < d.size(); i++)
			{
				texCoords.push_back(std::stof(d[i]));
			}
		}
		else if (currentLine.find("vn", 0) != currentLine.npos)
		{
			d = SeparateString(currentLine, 2, " ");
			for (int i = 0; i < d.size(); i++)
			{
				normals.push_back(std::stof(d[i]));
			}
		}
		else if (currentLine.find("f ", 0) != currentLine.npos)
		{
			std::vector<int> fData = ParseFaceData(currentLine, 2, '/');//-1);
		}
		else if (currentLine.find("mtllib", 0) != currentLine.npos)
		{
			d = SeparateString(currentLine, 6, " ");
			material = directory + "/" + d[0];
		}
	}
	infile.close();

	GenerateVertexData(vertPos, texCoords, normals);
	GenerateIndexData();

	PRINT("MODEL LOADER >> Loaded file at " << directory);
	PRINT("MODEL LOADER >> Vertices(v): " << vertPos.size() << "  Texture Coordinates(vt): " << texCoords.size() << "  Vertex Normals(vn): " << normals.size());
}

ModelLoader::~ModelLoader()
{
}

// non separator = start of triplet, look for first value, if after previous value the next character is a separtor/whtiespace, insert 0, repeat until a triple is formed
std::vector<std::string> ModelLoader::SeparateString(std::string line, int startPos, std::string separator) const
{
	std::vector<std::string> data;
	int index = line.find_first_not_of(separator, startPos); // Starting position to iterate
	for (int i = index; i < line.size(); i = index)
	{
		int start = line.find_first_not_of(separator, index);	// Look for next non-separator character
		int end = line.find_first_of(separator, index);				// Look for next separator character

		index = line.find_first_not_of(separator, end);		// Update index to 'end'. This is where the next search should begin
		data.push_back(line.substr(start, end - start));
	}

	return data;
}

/// <summary>
/// Generates an index buffer for OpenGL
/// </summary>
void ModelLoader::GenerateIndexData()
{

	for (int f = 0; f < _faceData.size(); f++)
	{
		for (int i = 0; i < _vertData.size(); i++)
		{
			if (_faceData[f] == _vertData[i].triplet)
			{
				_indexData.push_back(i);
				break;
			}
		}
	}
}

/// <summary>
/// Generates a vertex buffer for OpenGL
/// </summary>
/// <param name="v">List of vertex positions</param>
/// <param name="t">List of texture coordinates</param>
/// <param name="n">List of normals</param>
void ModelLoader::GenerateVertexData(std::vector<float> &v, std::vector<float> &t, std::vector<float> &n)
{
	// Vertex structure: v,v,v,  t,t,  n,n,n

	int vertPosOffset = 3;
	int texCoordsOffset = 2;
	int normOffset = 3;

	// Add vertex equal operation
	for (int i = 0; i < _faceData.size(); i++) // v/t/n
	{
		Vertex x(_faceData[i],
			v[vertPosOffset * (_faceData[i].pos - 1)],
			v[(vertPosOffset * ( _faceData[i].pos - 1)) + 1],
			v[(vertPosOffset * (_faceData[i].pos - 1)) + 2],
			(t.size() > 0) ? t[(texCoordsOffset * ((_faceData[i].texCoord - 1 < 0) ? 0 : _faceData[i].texCoord - 1))] : 0,
			(t.size() > 0) ? t[(texCoordsOffset * ((_faceData[i].texCoord - 1 < 0) ? 0 : _faceData[i].texCoord - 1) + 1)] : 0,
			(n.size() > 0) ? n[(normOffset * ((_faceData[i].normal - 1 < 0) ? 0 : _faceData[i].normal - 1))] : 0,
			(n.size() > 0) ? n[(normOffset * ((_faceData[i].normal - 1 < 0) ? 0 : _faceData[i].normal - 1)) + 1] : 0,
			(n.size() > 0) ? n[(normOffset * ((_faceData[i].normal - 1 < 0) ? 0 : _faceData[i].normal - 1)) + 2] : 0);

		
		if (std::find(_vertData.begin(), _vertData.end(), x) != _vertData.end())
		{
			//PRINT("DUPLICATE!");
		}
		else
		{
			//PRINT("NO DUPLICATE");
			//x.Log();
			_vertData.push_back(x);
			_vertexData.push_back(x.position[0]);
			_vertexData.push_back(x.position[1]);
			_vertexData.push_back(x.position[2]);
			_vertexData.push_back(x.textureCoordinates[0]);
			_vertexData.push_back(x.textureCoordinates[1]);
			_vertexData.push_back(x.normals[0]);
			_vertexData.push_back(x.normals[1]);
			_vertexData.push_back(x.normals[2]);
		}

	}
}

// TODO Refactor
/// <summary>
/// Parse an .Obj face data e.g. f v or f v/vt/vn or f v//vn
/// </summary>
/// <param name="line">The data to parse in string</param>
/// <param name="startPos">Starting position to parse. Normally 2 to ignore "f "</param>
/// <param name="separator">The separator to use. Should be "/"</param>
/// <returns>Returns a list of int of indices</returns>
std::vector<int> ModelLoader::ParseFaceData(std::string line, int startPos, char separator)
{
	std::vector<int> data;

	//PRINT(line);
	std::vector<std::string> _sss = SeparateString(line, startPos, " ");
	int index = line.find_first_not_of(separator, startPos); // Starting position to iterate
	for (int i = 0; i < _sss.size(); i++)
	{
		//PRINT(_sss[i]);
		// 0/0/0
		for (int j = 0; j < _sss[i].size();)
		{
			int start = _sss[i].find_first_not_of("/", j);
			int end = _sss[i].find_first_of("/", start);

			data.push_back(stof(_sss[i].substr(start, end - start)));
			if (end == std::string::npos)
			{
				break;
			}
			else

			{
				j = end;
			}
		}

		// TODO Test f 0//0
		// TODO Use MTL
		if (_sss[i].find("/") == std::string::npos)
		{
			//PRINT(0);
			//PRINT(0);
			data.push_back(0);
			data.push_back(0);

		}
	}

	for (int f = 0; f < data.size(); f += 3)
	{
		FaceData fData(data[f], data[f + 1], data[f + 2]);
		_faceData.push_back(fData);
	}

	return data;
}
