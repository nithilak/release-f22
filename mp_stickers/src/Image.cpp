#include "Image.h"

void Image::lighten() {
    adjustLuminance(0.1);
}
void Image::lighten(double amount) {
    errorCheckAmount(amount, 1);
    adjustLuminance(amount);
}
// void Image::darken() {
//    adjustLuminance(-0.1);
// }
void Image::darken(double amount) { //copied from lighten(double amount), change 2 things
    errorCheckAmount(amount, 1);
    adjustLuminance(-1*amount);
}
void Image::saturate() {
    adjustSaturation(0.1); //no need to error check here, but just to make sure, here is a note
}
void Image::saturate(double amount) {
    errorCheckAmount(amount, 1);
    adjustSaturation(amount);
}
// void Image::desaturate() {
//    adjustSaturation(0.1);
// }
// void Image::desaturate(double amount) {
//    errorCheckAmount(amount);
//    adjustSaturation(amount);
// }
// void Image::grayscale() { //copied from adjustLuminance(double amount), then adjusted/slightly modified to fit this function
//    setHue(0) //no need to error check here, but here is a note just to make sure
// }
void Image::rotateColor(double degrees) {
    errorCheckAmount(degrees, 360);
    adjustHue(degrees);
}
// void Image::illinify() {
    //copied from adjustHue(double amount), changed one thing (set elem to 11 or 216 based on closeness)
    //void Image::adjustHue(double amount) { //copied from adjustLuminance, changed l -> h
    // for (unsigned row = 0; row < height(); row++) {
    //     for (unsigned col = 0; col < width(); col++) {
    //         double& elem = getPixel(row, col).h;
    //         if (elem < 0) {
    //             throw std::runtime_error("l of pixel " + std::to_string(row) + ", " + std::to_string(col) + " is below 0.");
    //         }
    //         if (elem > 1) {
    //             throw std::runtime_error("l of pixel " + std::to_string(row) + ", " + std::to_string(col) + " is greater than 1.");
    //         }
    //         if (elem < 1) {
    //             if (elem < 113.5) { //should be greater than 0
    //                 elem = 11;
    //             } else { //elem >= 113.5, should be less than or equal to 360
    //                 elem = 216;
    //             }
    //         }
    //     }
    // }
    //}
// }
void Image::scale(double factor) {}
// void Image::scale(unsigned w, unsigned h) {}

//helpers

void Image::adjustLuminance(double amount) { //copied from lighten(double amount), change 2 things
    for (unsigned row = 0; row < height(); row++) {
        for (unsigned col = 0; col < width(); col++) {
            double& elem = getPixel(row, col).l;
            if (elem < 0) {
                throw std::runtime_error("l of pixel " + std::to_string(row) + ", " + std::to_string(col) + " is below 0.");
            }
            if (elem > 1) {
                throw std::runtime_error("l of pixel " + std::to_string(row) + ", " + std::to_string(col) + " is greater than 1.");
            }
            if (elem < 1) {
                elem += amount;
            }
        }
    }
}

void Image::adjustSaturation(double amount) { //copied from adjustLuminance, changed l -> s
    for (unsigned row = 0; row < height(); row++) {
        for (unsigned col = 0; col < width(); col++) {
            double& elem = getPixel(row, col).s;
            if (elem < 0) {
                throw std::runtime_error("l of pixel " + std::to_string(row) + ", " + std::to_string(col) + " is below 0.");
            }
            if (elem > 1) {
                throw std::runtime_error("l of pixel " + std::to_string(row) + ", " + std::to_string(col) + " is greater than 1.");
            }
            if (elem < 1) {
                elem += amount;
            }
        }
    }
}

void Image::adjustHue(double amount) { //copied from adjustLuminance, changed l -> h
    for (unsigned row = 0; row < height(); row++) {
        for (unsigned col = 0; col < width(); col++) {
            double& elem = getPixel(row, col).h;
            if (elem < 0) {
                throw std::runtime_error("l of pixel " + std::to_string(row) + ", " + std::to_string(col) + " is below 0.");
            }
            if (elem > 1) {
                throw std::runtime_error("l of pixel " + std::to_string(row) + ", " + std::to_string(col) + " is greater than 1.");
            }
            if (elem < 1) {
                elem += amount;
            }
        }
    }
}

void Image::setHue(double value) { //copied from setHue, changed two things (removed error checking and set elem to be value)
    // errorCheckAmount(value, 360);
    for (unsigned row = 0; row < height(); row++) {
        for (unsigned col = 0; col < width(); col++) {
            double& elem = getPixel(row, col).h;
            elem = value;
        }
    }
}

void Image::errorCheckAmount(double amount, double max) {
    if (amount < 0) {
        throw std::invalid_argument("amount " + std::to_string(amount) + " must be a non-negative value and less than or equal to " + std::to_string(max) + ", to stay in the range [0, 1]");
    }
    if (amount > max) {
        throw std::invalid_argument("amount " + std::to_string(amount) +  " must be less than or equal to " + std::to_string(max) + " and a non-negative value, to stay in the range [0, 1]");
    }
}