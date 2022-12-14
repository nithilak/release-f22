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
    void darken();
    void darken(double amount);
    void saturate();
    void saturate(double amount);
    void desaturate();
    void desaturate(double amount);
    void grayscale();
    void rotateColor(double degrees);
    void illinify();
    void scale(double factor);
    void scale(unsigned w, unsigned h);

    //helpers
    void adjustLuminance(double amount); //copied from lighten(double amount), change 2 things
    void errorCheckAmount(double amount); //does not include max in valid range, used to have an upper check of unsigned max
    void adjustSaturation(double amount); //copied from adjustLuminance, changed l -> s
    void adjustHue(double amount); //copied from adjustLuminance, changed l -> h
    void setHue(double value); //copied from setHue, changed two things (removed error checking and set elem to be value)
    bool checkElemWithinBoundsZeroAndMax(double elem, double max);
};