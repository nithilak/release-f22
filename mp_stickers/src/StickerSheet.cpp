#include "StickerSheet.h"

StickerSheet::StickerSheet() : picture_(new Image()), max_(0) {
}
StickerSheet::StickerSheet(const Image& picture, unsigned max) : picture_(&picture), max_(max) {}
// StickerSheet::~StickerSheet() {
//   delete picture_;
// }
// StickerSheet::StickerSheet(const StickerSheet& other) {
    // picture_ = new Image();
    // Image copy = *(other.getSticker());
    // *picture_ = copy;
    // max_ = other.getmax();
// }
// const StickerSheet& StickerSheet::operator=(const StickerSheet& other) {}
int StickerSheet::addSticker(Image& sticker, unsigned x, unsigned y) { return 0; }
Image StickerSheet::render() const { return Image(); } //&?
void StickerSheet::changeMaxStickers(unsigned max) { max_ = max; }
void StickerSheet::removeSticker(unsigned index) {}
bool StickerSheet::translate(int num, int x, int y) { return false; }

//getters
Image* StickerSheet::getSticker(unsigned index) { return nullptr; }
//unsigned StickerSheet::getMax() { return max_; }

//helpers