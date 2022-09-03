/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once

#include "Image.h"

class StickerSheet {
    public:
    StickerSheet();
    StickerSheet(const Image& picture, unsigned max);
    ~StickerSheet();
    StickerSheet(const StickerSheet& other);
    const StickerSheet& operator=(const StickerSheet& other);
    void changeMaxStickers(unsigned max);
    int addSticker(Image& sticker, unsigned x, unsigned y);
    bool translate(int num, int x, int y);
    void removeSticker(unsigned index);
    Image render() const; //&?

    //getters
    Image* getSticker(unsigned index);
    unsigned getMax() const;

    //setters

    //helpers
    // Image* getImage(unsigned index) const { return nullptr; }
    Image* getStickerConst(unsigned index) const;

    private:
    const Image* picture_;
    unsigned max_;
};