#pragma once

struct Vector2f
{
	float x;
	float y;
};

struct Vector3f
{
	float x;
	float y;
	float z;

	Vector3f()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Vector3f(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
};
