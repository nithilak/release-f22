/**
 * @file sketchify.cpp
 * Implementation of the sketchify function.
 */
#pragma GCC diagnostic ignored "-Wuninitialized"
#include <cstdlib>
#include <cmath>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using namespace cs225;

/**
 * Creates a new output image.

 * @param w width of the image
 * @param h height of the image

 * @return a pointer to the newly-created image
 */
PNG* setupOutput(unsigned w, unsigned h) {
    // std::cout << "enter setupOutput" << std::endl;
    PNG* image = new PNG(w, h);
    // std::cout << "image width: " << image->width() << "height: " << image->height() << std::endl;
    return image;
}

/**
 * Used to customize the color of the sketchified image.

 * @return a pointer to the color to use when sketchifying
 */
HSLAPixel* myFavoriteColor() {
    HSLAPixel *p = new HSLAPixel(-1, 0.8, 0.5);
    // HSLAPixel* ptr = &p;
    return p;
}

void sketchify(std::string inputFile, std::string outputFile) {
    // Load in.png
    PNG* original = new PNG();

    std::cout << "test1" << std::endl;

    original->readFromFile(inputFile);
    std::cout << "test1.2" << std::endl;
    std::cout << "original width: " << original->width() << "height: " << original->height() << std::endl;
    unsigned width = original->width();
    unsigned height = original->height();
    std::cout << "variables width: " << width << "height: " << height << std::endl;

    std::cout << "test2" << std::endl;

    // Create out.png
    PNG* output = new PNG();
    output = setupOutput(width, height);

    std::cout << "output width: " << output->width() << "height: " << output->height() << std::endl;

    std::cout << "test3" << std::endl;

    // Load our favorite color to color the outline
    HSLAPixel* myPixel = myFavoriteColor();

    std::cout << "test4" << std::endl;

    // Go over the whole image, and if a pixel differs from that to its upper
    // left, color it my favorite color in the output
    for (unsigned y = 1; (0 < y) && (y < height); y++) {
        // std::cout << "test5" << std::endl;
        // std::cout << "y: " << y << std::endl;
        for (unsigned x = 1; (0 < x) && (x < width); x++) {
            // std::cout << "test6" << std::endl;
            // std::cout << "x: " << x << std::endl;
            // Calculate the pixel difference
            HSLAPixel& prev = original->getPixel(x - 1, y - 1);
            HSLAPixel& curr = original->getPixel(x, y);
            double diff = std::fabs(curr.h - prev.h);

            // std::cout << "test7" << std::endl;

            // std::cout << "*output: " << *output << std::endl;

            // If the pixel is an edge pixel,
            // color the output pixel with my favorite color
            HSLAPixel& currOutPixel = (*output).getPixel(x, y);
            // std::cout << "test7.1" << std::endl;
            if (diff > 20) {
                // std::cout << "test7.2" << std::endl;
                currOutPixel = *myPixel;
                // std::cout << "test7.3" << std::endl;
            }

            // currOutPixel = *myPixel;

            // std::cout << "test8" << std::endl;
            // break;
        }
        // std::cout << "test8.2" << std::endl;
        // break;
    }

    std::cout << "test9" << std::endl;

    // Save the output file
    output->writeToFile(outputFile);

    std::cout << "test10" << std::endl;

    // Clean up memory
    delete myPixel;
    delete output;
    delete original;
}
