#include "Image.h"
#include <iostream>

void Image::lighten() {
    double kMax = 1;
    adjustLuminance(0.1, kMax);
}
void Image::lighten(double amount) {
    // std::cout << "amount lighten: " << amount << std::endl;
    if (amount == 0) {
        return;
    }
    double kMax = 1;
    // errorCheckAmount(amount);
    adjustLuminance(amount, kMax);
}
void Image::darken() {
   double kMax = 1;
   adjustLuminance(-0.1, kMax);
}
void Image::darken(double amount) { //copied from lighten(double amount), change 2 things
    // std::cout << "amount darken: " << amount << std::endl;
    if (amount == 0) {
        return;
    }
    double kMax = 1;
    // errorCheckAmount(amount);
    adjustLuminance(-1*amount, kMax);
}
void Image::saturate() {
    double kMax = 1;
    adjustSaturation(0.1, kMax); //no need to error check here, but just to make sure, here is a note
}
void Image::saturate(double amount) {
    double kMax = 1;
    // errorCheckAmount(amount);
    adjustSaturation(amount, kMax);
}
void Image::desaturate() {
   double kMax = 1;
   adjustSaturation(0.1, kMax);
}
void Image::desaturate(double amount) {
   double kMax = 1;
//    errorCheckAmount(amount);
   adjustSaturation(amount, kMax);
}
void Image::grayscale() { //copied from adjustLuminance(double amount), then adjusted/slightly modified to fit this function
   setHue(0); //no need to error check here, but here is a note just to make sure
}
void Image::rotateColor(double degrees) {
    double kMax = 360;
    // errorCheckAmount(degrees, kMax); //negative values are allowed here
    // while (degrees > kMax) {
    //     degrees -= 360;
    // }
    adjustHue(degrees, kMax);
}
void Image::illinify() { //assume valid input
    //copied from adjustHue(double amount), changed one thing (set elem to 11 or 216 based on closeness)
    //void Image::adjustHue(double amount) { //copied from adjustLuminance, changed l -> h
    for (unsigned row = 0; row < height(); row++) {
        for (unsigned col = 0; col < width(); col++) {
            double& elem = getPixel(col, row).h;
            if (elem < 0) {
                throw std::runtime_error("h of pixel " + std::to_string(col) + ", " + std::to_string(row) + " is below 0: " + std::to_string(elem));
            }
            if (elem > 360) {
                throw std::runtime_error("h of pixel " + std::to_string(col) + ", " + std::to_string(row) + " is greater than 360: " + std::to_string(elem));
            }
            // if (elem <= 360) {
                if (elem > 266.5 || elem < 113.5) { //should be greater than 0
                    elem = 11;
                } else { //elem >= 113.5, should be less than or equal to 360
                    elem = 216;
                }
            // }
        }
    }
    //}
}
void Image::scale(double factor) {
    // factor = factor + 1; //this was there so that this function could compile at the start
    std::cout << "factor: " << std::to_string(factor) << std::endl;
    if (factor == 1) {
        return;
    }
    if (factor <= 0) {
        throw std::invalid_argument("factor cannot be less than or equal to zero: " + std::to_string(factor));
    }
    //each x value (col) starts in its corresponding location of 2x
    //each y value (row) starts in its corresponding location of 2y


    //make a new image with 2x width and 2y height
    const unsigned kWidth = this->width();
    const unsigned kHeight = this->height();
    if (factor == 0) {
        for (unsigned row = 0; row < kHeight; row ++) {
            for (unsigned col = 0; col < kWidth; col++) {
                this->getPixel(col, row) = cs225::HSLAPixel(0, 0, 0, 0);
            }
        }
        // resize(1, 1); //so that the file does not crash
        resize(0, 0);
        return;
    }
    // const unsigned kArea = kWidth * kHeight;
    const unsigned kscaled_width = (kWidth * factor);
    const unsigned kscaled_height = (kHeight * factor);
    // const unsigned kscaled_area = kscaled_width * kscaled_height;

    // cs225::HSLAPixel* original_image = new cs225::HSLAPixel[kArea]; //this is an array

    //store this on the free store later
    // cs225::HSLAPixel* scaled_image = new cs225::HSLAPixel[kscaled_area]; //this is an array

    if (factor > 1) {
        const unsigned kArea = kWidth * kHeight;
        cs225::HSLAPixel* original_image = new cs225::HSLAPixel[kArea]; //this is an array
        //iterate through original image
        unsigned count = 0;
        for (unsigned row = 0; row < kHeight; row ++) {
            for (unsigned col = 0; col < kWidth; col++) {
                //make each starting col be 2x
                // const cs225::HSLAPixel& current_pixel = this->getPixel(col, row); //makes a copy, here each time //not anymore
                original_image[count] = cs225::HSLAPixel(0, 0, 0, 0); // current_pixel;
                count++;
                //fill in the square formed by 2x by 2y
                //2*col --- before 2*(col + 1)
                //2*row --- before 2*(row + 1)

                // unsigned col_start = factor * col;
                // unsigned col_end = factor * (col + 1);
                // unsigned row_start = factor * row;
                // unsigned row_end = factor * (row + 1);
                // for (unsigned x = col_start; x < col_end; x++) {
                //     for (unsigned y = row_start; y < row_end; y++) {
                //         //scaled_array at (x, y) should be filled in with 
                //         //the current color at (row, col)
                //                             //current row    //current col
                //         unsigned current_xy = (factor * (y)) + x;
                //         scaled_image[current_xy] = current_pixel;
                //     }
                // }
            }
        }

        //update imageData_;
        // delete imageData_;
        // imageData_ = scaled_image; //not on the free store
        //update width_;
        // width_ = scaled_width;
        //update height_;
        // height_ = scaled_height;

        //resize the image with scaled_width and scaled_height
        resize(kscaled_width, kscaled_height);
        //update image to match scaled_image
        unsigned current_pos = 0;
        // for (unsigned row = 0; row < kscaled_height; row++) {
        //     for (unsigned col = 0; col < kscaled_width; col++) {
        //         this->getPixel(col, row) = scaled_image[current_pos]; //cs225::HSLAPixel(0, 5, 7)
        //         current_pos++;
        //     }
        // }

        current_pos = 0;
        if (factor > 1) {
            for (unsigned row = 0; row < kHeight; row++) {
                for (unsigned col = 0; col < kWidth; col++) {
                    for (unsigned y = factor*row; y < factor*(row + 1); y++) {
                        for (unsigned x = factor*col; x < factor*(col + 1); x++) {
                            this->getPixel(x, y) = cs225::HSLAPixel(1, 1, 1, 1);
                            //original_image[current_pos]; // cs225::HSLAPixel(0, 5, 7)
                        }
                    }
                    current_pos++;
                }
            }
        }
        delete[] original_image;
    } else if (factor > 0 && factor < 1) {
        const unsigned kscaled_area = kscaled_width * kscaled_height;
        cs225::HSLAPixel* scaled_image = new cs225::HSLAPixel[kscaled_area]; //this is an array
        // else { //if (factor < 1)
            const double kfactor = factor;
            unsigned current_pos = 0;
            for (unsigned row = 0; row < kHeight;) {
                for (unsigned col = 0; col < kWidth;) {
                    // for (unsigned y = factor*row; y < factor*(row + 1); y++) {
                    //     for (unsigned x = factor*col; x < factor*(col + 1); x++) {
                    //         this->getPixel(x, y) = original_image[current_pos]; // cs225::HSLAPixel(0, 5, 7)
                    //     }
                    // }
                    // if (row + col > 500) {
                        std::cout << "row: " << row << " col: " << col << std::endl;
                    // }
                    scaled_image[current_pos] = this->getPixel(col, row);
                    current_pos++;
                    for (int i = 0; i < 1/kfactor; i++) {
                        // std::cout << "i: " << i << " 1/kfactor: " << 1/kfactor << std::endl;
                        col++;
                    }
                }
                for (int i = 0; i < 1/kfactor; i++) {
                    std::cout << "i: " << i << " 1/kfactor: " << 1/kfactor << std::endl;
                    row++;
                }
            }
        // }
        unsigned current_pos2 = 0;
        resize(kscaled_width, kscaled_height);
        for (unsigned row = 0; row < kscaled_height; row++) {
            for (unsigned col = 0; col < kscaled_width; col++) {
                this->getPixel(col, row) = scaled_image[current_pos2];
                current_pos2++;
            }
        }

        delete[] scaled_image;
    }

    // current_pos = 0;
    // for (unsigned row = 0; row < kHeight; row++) {
    //     for (unsigned col = 0; col < kWidth; col++) {
    //         this->getPixel(col, row) = original_image[current_pos]; //cs225::HSLAPixel(0, 5, 7)
    //         current_pos++;
    //     }
    // }

    // delete[] scaled_image;
    // delete[] original_image;
}
void Image::scale(unsigned w, unsigned h) {
    // unsigned num = w * h;
    double width = this->width();
    double height = this->height();
    double w2 = w;
    double h2 = h;
    if (w == width && h == height) {
        return;
    }
    if (w > width && h > height) {
        if (w > h) {
            scale(w2/width);
        } else {
            scale(h2/height);
        }
    } else if (w <= width && h <= height) {
        if (w > h) {
            scale(h2/height);
        } else { //(h >= w)
            scale(w2/width);
        }
    } else if (w > width) {
        scale(h2/height);
    } else if (h > height) {
        scale(w2/width);
    } else {
        throw std::runtime_error("something went wrong");
    }
}

//helpers

void Image::adjustLuminance(double amount, double max) { //copied from lighten(double amount), change 2 things
    for (unsigned row = 0; row < height(); row++) {
        for (unsigned col = 0; col < width(); col++) {
            double& elem = getPixel(col, row).l;
            if (elem + amount >= 1) {
                elem = 1;
            } else if (elem + amount <= 0) {
                elem = 0;
            } else {
                elem += amount;
            }
        }
    }
}

void Image::adjustSaturation(double amount, double max) { //copied from adjustLuminance, changed l -> s
    for (unsigned row = 0; row < height(); row++) {
        for (unsigned col = 0; col < width(); col++) {
            double& elem = getPixel(col, row).s;
            if (elem + amount >= 1) {
                elem = 1;
            } else if (elem + amount <= 0) {
                elem = 0;
            } else {
                elem += amount;
            }     
        }
    }
}

void Image::adjustHue(double amount, double max) { //copied from adjustLuminance, changed l -> h
    for (unsigned row = 0; row < height(); row++) {
        for (unsigned col = 0; col < width(); col++) {
            double& elem = getPixel(col, row).h;
            // if (checkElemWithinBoundsZeroAndMax(elem + amount, max)) {
                elem = (elem + amount);
                while (getPixel(col, row).h > 360) {
                    elem -= 360;
                    if (elem < 0) {
                        throw std::runtime_error("getPixel(" + std::to_string(col) + ", " + std::to_string(row) + ").h is less than 0");
                    }
                }
                while (elem < 0) {
                    elem += 360;
                    if (elem > 360) {
                        throw std::runtime_error("getPixel(" + std::to_string(col) + ", " + std::to_string(row) + ").h is less than 0");
                    }
                }
            // }       
        }
    }
}

void Image::setHue(double value) { //copied from setHue, changed two things (removed error checking and set elem to be value)
    // errorCheckAmount(value, 360);
    for (unsigned row = 0; row < height(); row++) {
        for (unsigned col = 0; col < width(); col++) {
            double& elem = getPixel(col, row).h;
            elem = value;
        }
    }
}

void Image::errorCheckAmount(double amount) {
    if (amount < 0) {
        // throw std::invalid_argument("amount " + std::to_string(amount) + " must be a non-negative value and greater than zero and less than or equal to " + std::to_string(max) + ", to stay in the range [0, 1]");
        throw std::invalid_argument("amount " + std::to_string(amount) + " must be a non-negative value and greater than zero");
    }
    // if (amount > max) {
    //     throw std::invalid_argument("amount " + std::to_string(amount) +  " must be less than or equal to " + std::to_string(max) + " and a non-negative value, to stay in the range [0, 1]");
    // }
}

bool Image::checkElemWithinBoundsZeroAndMax(double elem, double max) { //could be unsigned max instead
    // if (elem < 0) {
    //     // throw std::runtime_error("l of pixel " + std::to_string(col) + ", " + std::to_string(row) + " is below 0.");
    // }
    // if (elem > max) {
    //     // throw std::runtime_error("l of pixel " + std::to_string(col) + ", " + std::to_string(row) + " is greater than " + std::to_string(max) + ".");
    // }
    return (!(elem <= 0) && !(elem >= max));
}