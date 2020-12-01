#pragma once VEC3_H

#include <iostream>

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

vec3 operator+(const vec3& v1, const vec3& v2)
{
	return vec3(v1.v[0] + v2.v[0], v1.v[1] + v2.v[1], v1.v[2] + v2.v[2]);
}

vec3 operator-(const vec3& v1, const vec3& v2)
{
	return vec3(v1.v[0] - v2.v[0], v1.v[1] - v2.v[1], v1.v[2] - v2.v[2]);
}

vec3 operator/(const vec3& v1, const vec3& v2)
{
	return vec3(v1.v[0] / v2.v[0], v1.v[1] / v2.v[1], v1.v[2] / v2.v[2]);
}

vec3 operator/(const vec3& v1, double& t)
{
	return vec3(v1.v[0] / t, v1.v[1] / t, v1.v[2] / t);
}

vec3 operator*(const vec3& v1, const vec3& v2)
{
	return vec3(v1.v[0] * v2.v[0], v1.v[1] * v2.v[1], v1.v[2] * v2.v[2]);
}

vec3 operator*(const vec3& v1, double& t)
{
	return vec3(v1.v[0] * t, v1.v[1] * t, v1.v[2] * t);
}


