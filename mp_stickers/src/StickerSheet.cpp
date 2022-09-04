#include "StickerSheet.h"

StickerSheet::StickerSheet() : max_(0), picture_(new Image[max_ + 1]), current_layer_(0) {
}
StickerSheet::StickerSheet(const Image& picture, unsigned max) : max_(max), picture_(new Image[max_ + 1]), current_layer_(0) {
    picture_[0] = picture;
}
StickerSheet::~StickerSheet() {
    //delete picture_;
    picture_ = nullptr;
}
StickerSheet::StickerSheet(const StickerSheet& other) {
    picture_ = new Image();
    Image temp = other.render();
    picture_ = &(temp);
    changeMaxStickers(other.getMax());
}
const StickerSheet& StickerSheet::operator=(const StickerSheet& other) {
    if (this == &other) {
        return *this;
    }
    return *this;
}
int StickerSheet::addSticker(Image& sticker, unsigned x, unsigned y) { 
    //iterate through all of sticker
    if (current_layer_ + 1 > max_) {
        return -1;
    } else {
        current_layer_++;
    }
    // Image layer;
    // for (unsigned row = 0; row < sticker.height(); row++) {
    //     for (unsigned col = 0; col < sticker.width(); col++) {
    //         layer.getPixel(x + col, y + row) = sticker.getPixel(x + col, y + row);
    //     }
    // }
    // picture_[current_layer_] = layer;
    return current_layer_; 
}
Image StickerSheet::render() const { return Image(); } //&?
void StickerSheet::changeMaxStickers(unsigned max) { max_ = max; }
void StickerSheet::removeSticker(unsigned index) {}
bool StickerSheet::translate(int num, int x, int y) { return false; }

//getters
Image* StickerSheet::getSticker(unsigned index) { return nullptr; }
unsigned StickerSheet::getMax() const { return max_; }

//helpers
Image* StickerSheet::getStickerConst(unsigned index) const { return nullptr; }