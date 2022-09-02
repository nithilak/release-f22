#include "StickerSheet.h"

StickerSheet::StickerSheet(const Image& image, int amount) {}
void StickerSheet::addSticker(Image& image, int x, int y) const {}
Image StickerSheet::render() const { return Image(); } //&?
void StickerSheet::changeMaxStickers(int num) {}
void StickerSheet::removeSticker(int num) {}
bool StickerSheet::translate(int num, int x, int y) { return false; }

//getters
Image* StickerSheet::getSticker(int num) { return nullptr; }