#include "Image.h"

void Image::lighten() {}
void Image::lighten(double amount) {}
// void Image::darken() {}
void Image::darken(double amount) {}
void Image::saturate() {}
void Image::saturate(double amount) {}
// void Image::desaturate() {}
// void Image::desaturate(double amount) {}
// void Image::grayscale();
void Image::rotateColor(double degrees) {}
// void Image::Illinify() {}
void Image::scale(double factor) {}
// void scale(unsigned w, unsigned h) {}

//getters
unsigned int Image::width() const { return width_; }
unsigned int Image::height() const { return height_; }