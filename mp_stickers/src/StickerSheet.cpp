#include "StickerSheet.h"

StickerSheet::StickerSheet() : picture_(new Image()), max_(0) {
}
StickerSheet::StickerSheet(const Image& picture, unsigned max) : picture_(&picture), max_(max) {}
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
int StickerSheet::addSticker(Image& sticker, unsigned x, unsigned y) { return 0; }
Image StickerSheet::render() const { return Image(); } //&?
void StickerSheet::changeMaxStickers(unsigned max) { max_ = max; }
void StickerSheet::removeSticker(unsigned index) {}
bool StickerSheet::translate(int num, int x, int y) { return false; }

//getters
Image* StickerSheet::getSticker(unsigned index) { return nullptr; }
unsigned StickerSheet::getMax() const { return max_; }

//helpers
Image* StickerSheet::getStickerConst(unsigned index) const { return nullptr; }