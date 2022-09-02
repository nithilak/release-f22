#include "Image.h"

void Image::lighten() {}
void Image::lighten(double amount) {}
void Image::darken(double amount) {}
void Image::saturate() {}
void Image::saturate(double amount) {}
void Image::rotateColor(int degrees) {}
void Image::scale(double factor) {}

//getters
unsigned int Image::width() const { return width_; }
unsigned int Image::height() const { return height_; }