#include "vec3.h"
#include "color.h"
#include "ray.h"
#include <iostream>

color RayColor(const ray& r)
{
    vec3 unit_direction = UnitVector(r.direction());
    double t = 0.5 * (unit_direction.y() + 1);
    return (1 - t) * color(1, 1, 1) + t * color(0.5, 0.7, 1);
}

int main()
{
    // Image
    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 480;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    // Viewport

    double viewport_width = 2;
    double viewport_height = static_cast<int>(viewport_width / aspect_ratio);
    double focal_length = 1;

    // Camera

    vec3 origin = vec3(0, 0, 0);
    vec3 horizontal = vec3(viewport_width, 0, 0);
    vec3 vertical = vec3(0, viewport_height, 0);
    vec3 refPoint = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    //Header
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // Rendering Image Data
    for (int j = image_height - 1; j >= 0; j--) // Columns -> top to bottom
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) // Columns -> left to right
        {
            double u = double(i) / (image_width - 1);
            double v = double(j) / (image_height - 1);

            ray r(origin, refPoint + u * horizontal + v * vertical);

            SetPixelColor(RayColor(r));
        }
    }

    std::cerr << "\nDone..\n";

    std::cin.get();
}