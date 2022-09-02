#include "StickerSheet.h"

StickerSheet::StickerSheet(const Image& picture, unsigned max) {}
// StickerSheet::~StickerSheet() {}
// StickerSheet::StickerSheet(const StickerSheet& other) {}
// const StickerSheet& StickerSheet::operator=(const StickerSheet& other) {}
int StickerSheet::addSticker(Image& sticker, unsigned x, unsigned y) { return 0; }
Image StickerSheet::render() const { return Image(); } //&?
void StickerSheet::changeMaxStickers(unsigned max) {}
void StickerSheet::removeSticker(unsigned index) {}
bool StickerSheet::translate(int num, int x, int y) { return false; }

//getters
Image* StickerSheet::getSticker(unsigned index) { return nullptr; }