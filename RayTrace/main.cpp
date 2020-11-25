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
            int r = i; // Red channel is increase to the right
            int g = j; // Green channel is decreasing to the bottom
            int b = (i+j)/2; // Blue channel averages Red and Green channel in each pixel

            std::cout << r << ' ' << g << ' ' << b << '\n'; // -> Pixel output
        }
    }

    std::cerr << "\nDone..\n";
}