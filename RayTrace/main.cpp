#include "color.h"
#include "vec3.h"

#include <iostream>

int main()
{
    // Image 
    const int image_width = 256;
    const int image_height = 256;

    // PPM file format
    // P3       -> means this is a RGB color image in ASCII
    // 256 256  -> width & height of the image
    // 255      -> maximum value for each color
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // Image data
    for (int j = image_height -1; j >= 0; j--) // Columns -> top to bottom
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) // Columns -> left to right
        {
            color pixel_color(double(i) / (image_width-1), double(j) / (image_height-1), double(i+j)/(image_height + image_width -2));
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone..\n";
}