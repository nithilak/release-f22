/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once

#include "Image.h"
#include <vector>

struct Point {
    unsigned x;
    unsigned y;
    Point() : x(0), y(0) {}
    Point(unsigned x2,  unsigned y2) : x(x2), y(y2) {}
};

struct ImagePoint {
    Image image; //could make these pointers, but that could be a bad idea
    Point point;
    ImagePoint(const Image& image2, const Point& point2) : image(image2), point(point2) {}
};

class StickerSheet {
    public:
    StickerSheet();
    StickerSheet(const Image& picture, unsigned max);
    ~StickerSheet();
    StickerSheet(const StickerSheet& other);
    const StickerSheet& operator=(const StickerSheet& other);
    void changeMaxStickers(unsigned max);
    int addSticker(Image& sticker, unsigned x, unsigned y);
    bool translate(unsigned index, unsigned x, unsigned y);
    void removeSticker(unsigned index);
    Image render() const; //&?

    //getters
    Image* getSticker(unsigned index);
    unsigned getMax() const;
    const std::vector<ImagePoint>& getLayers() const; //returns a copy, not a const reference
    const Image& getPicture() const;

    //setters

    //helpers
    // Image* getImage(unsigned index) const { return nullptr; }
    const Image* getStickerConst(unsigned index) const;
    void copyConstructor(const StickerSheet& other);

    private:
    unsigned max_;
    Image* picture_;
    std::vector<ImagePoint> layers_;
};