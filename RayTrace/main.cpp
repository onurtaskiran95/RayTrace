#include "vec3.h"

#include <iostream>


void set_pixel(std::ostream& out, vec3 pixel_color)
{
    out << (int)(255.999 * pixel_color.x()) << ' '
        << (int)(255.999 * pixel_color.y()) << ' '
        << (int)(255.999 * pixel_color.z()) << '\n';
}

int main()
{
    // Image Resolution
    const int image_width = 512;
    const int image_height = 512;

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // Rendering Image Data
    for (int j = image_height - 1; j >= 0; j--) // Columns -> top to bottom
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) // Columns -> left to right
        {
            vec3 pixel_color(double(i) / (image_width - 1), double(j) / (image_height - 1), double(i + j) / (image_height + image_width - 2));
            set_pixel(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone..\n";

    std::cin.get();
}