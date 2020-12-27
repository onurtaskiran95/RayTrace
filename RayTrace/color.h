#pragma once

#include "vec3.h"

void SetPixelColor(vec3 pixel_color)
{
    std::cout << (int)(255.999 * pixel_color.x()) << ' '
        << (int)(255.999 * pixel_color.y()) << ' '
        << (int)(255.999 * pixel_color.z()) << '\n';
}