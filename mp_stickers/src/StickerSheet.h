/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once

#include "Image.h"

class StickerSheet {
    public:
    StickerSheet(const Image& picture, unsigned max);
    // ~StickerSheet();
    // StickerSheet(const StickerSheet& other);
    // const StickerSheet& operator=(const StickerSheet& other);
    int addSticker(Image& sticker, unsigned x, unsigned y);
    Image render() const; //&?
    void changeMaxStickers(unsigned max);
    void removeSticker(unsigned index);
    bool translate(int num, int x, int y);

    //getters
    Image* getSticker(unsigned index);

    //setters

    private:
    // Image picture_;
    // unsigned max_;
};