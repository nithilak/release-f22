/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once

#include "Image.h"

class StickerSheet {
    public:
    StickerSheet(const Image& image, int amount);
    void addSticker(Image& image, int x, int y) const;
    Image render() const; //&?
    void changeMaxStickers(int num);
    void removeSticker(int num);
    bool translate(int num, int x, int y);

    //getters
    Image* getSticker(int num);

    //setters

    private:
};