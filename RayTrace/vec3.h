#pragma once VEC3_H

#include <iostream>
#include <cmath>


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

	double Length() const
	{
		return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	}
};

using color = vec3;

std::ostream& operator<<(std::ostream& out, const vec3& v)
{
	return out << v.v[0] << ' ' << v.v[1] << ' ' << v.v[2];
}

vec3 operator+(const vec3& v1, const vec3& v2)
{
	return vec3(v1.v[0] + v2.v[0], v1.v[1] + v2.v[1], v1.v[2] + v2.v[2]);
}

vec3 operator-(const vec3& v1, const vec3& v2)
{
	return vec3(v1.v[0] - v2.v[0], v1.v[1] - v2.v[1], v1.v[2] - v2.v[2]);
}

vec3 operator*(const vec3& v1, const vec3& v2)
{
	return vec3(v1.v[0] * v2.v[0], v1.v[1] * v2.v[1], v1.v[2] * v2.v[2]);
}

vec3 operator*(double t, const vec3& v1)
{
	return vec3(v1.v[0] * t, v1.v[1] * t, v1.v[2] * t);
}

vec3 operator*(const vec3& v1, double t)
{
	return vec3(t * v1);
}

vec3 operator/(const vec3& v1, const vec3& v2)
{
	return vec3(v1.v[0] / v2.v[0], v1.v[1] / v2.v[1], v1.v[2] / v2.v[2]);
}

vec3 operator/(const vec3& v1, double t)
{
	return vec3(v1.v[0] / t, v1.v[1] / t, v1.v[2] / t);
}

vec3 UnitVector(vec3 v)
{
	return v / v.Length();
}