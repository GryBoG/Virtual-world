#pragma once
#include <Windows.h>
#include <gl/gl.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include <vector>

#include "glmath.h"

#define CHUNK_WIDTH 20
#define DISTANCE 20

class world_chunk {
public:
	world_chunk() {}
	~world_chunk() {}

	void generate_mesh() {
		vertices.clear();
		indices.clear();

		const float y = 0.f; //высота по умолчанию в данный момент
		//const int step = 1;
		//assert(CHUNK_WIDTH % step); //шаг должен быть кратен ширине, иначе последние ряды треугольников могут быть уже чем все остальные
		int max_x = position.x + CHUNK_WIDTH;
		int max_z = position.z + CHUNK_WIDTH;
		for (int x = position.x; x < max_x - 1; x += 1) {
			for (int z = position.z; z < max_z - 1; z += 1) {
				vec3 p1, p2, p3;

				//создаем первый треугольник
				p1 = vec3((float)x, y, (float)z);
				p2 = vec3((float)x + 1, y, (float)z);
				p3 = vec3((float)x, y, (float)z + 1);
				vertices.push_back(p1);
				vertices.push_back(p2);
				vertices.push_back(p3);

				//создаем второй треугольник
				p1 = vec3((float)x, y, (float)z + 1);
				p2 = vec3((float)x + 1, y, (float)z + 1);
				p3 = vec3((float)x + 1, y, (float)z);
				vertices.push_back(p1);
				vertices.push_back(p2);
				vertices.push_back(p3);
			}
		}
	}

	vec3 position;
	std::vector<vec3> vertices;
	std::vector<unsigned int> indices;
};

class world_generator
{
public:
	world_generator() {}
	~world_generator() {}

	int init() {

		return 1;
	}

	void shutdown() {



	}

	void draw() {
		for (int i = 0; i < number_of_chunks; i++) {

		}
	}

	int number_of_chunks;
};

