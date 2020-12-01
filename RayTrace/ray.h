#pragma once
#include "vec3.h"

struct ray
{
	vec3 _origin;
	vec3 _direction;

	ray () {}

	ray(vec3& origin, vec3& direction) 
		: _origin(origin), _direction(direction) { }

	vec3 origin() const { return _origin; }
	vec3 direction() const { return _direction; }

	vec3 at(double t) const
	{
		return _origin + t * _direction;
	}
};