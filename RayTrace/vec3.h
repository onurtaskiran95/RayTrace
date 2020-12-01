#pragma once VEC3_H

struct vec3
{
	double v[3];

	vec3() 
		: v{ 0,0,0 } { };

	vec3(double x, double y, double z)
		: v{ x, y, z } { };

	double x() const { return v[0]; };
	double y() const { return v[1]; };
	double z() const { return v[2]; };

};