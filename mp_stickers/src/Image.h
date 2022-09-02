/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */

#pragma once

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

class Image: public cs225::PNG {
    public:
    void lighten();
    void lighten(double amount);
    void darken(double amount);
    void saturate();
    void saturate(double amount);
    void rotateColor(int degrees);
    void scale(double factor);

    //getters
    unsigned int width() const;
    unsigned int height() const;

    //setters

    private:
    unsigned int width_;
    unsigned int height_;

};