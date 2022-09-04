#include "StickerSheet.h"

StickerSheet::StickerSheet() : max_(0), picture_(new Image()), current_layer_(0), render_(*picture_), layers_(std::vector<Image>()) {
}
StickerSheet::StickerSheet(const Image& picture, unsigned max) : max_(max), picture_(new Image[max_ + 1]), current_layer_(0), render_(picture_[0]) {
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
    picture_[current_layer_] = sticker;
    return current_layer_; 
}
Image StickerSheet::render() const { 
    Image layer = picture_[0];
    int h = layer.height();
    int w = layer.width();
    int s_h = sticker.height();
    int s_w = sticker.width();
    int x2 = x;
    int y2 = y;

    std::cout << "width(): " << layer.width() << std::endl;
    std::cout << "height(): " << layer.height() << std::endl;

    int row_diff = s_h - (h - y2);
    std::cout << "row_diff: " << row_diff << std::endl;
    int col_diff = s_w - (w - x2);
    std::cout << "col_diff: " << col_diff << std::endl;
    if (row_diff > 0 && col_diff > 0) {
        layer.resize(w + col_diff , h + row_diff);
    } else if (row_diff > 0) {
        layer.resize(w, h + row_diff);
    } else if (col_diff > 0) {
        layer.resize(w + col_diff , h + row_diff);
    }
    std::cout << "width(): " << layer.width() << std::endl;
    std::cout << "height(): " << layer.height() << std::endl;
    for (unsigned row = 0; row < sticker.height(); row++) {
        for (unsigned col = 0; col < sticker.width(); col++) {
            layer.getPixel(x + col, y + row) = sticker.getPixel(col, row);
        }
    }
    render_ = layer;
    return render_; 
} //&?
void StickerSheet::changeMaxStickers(unsigned max) { 
    if (max < max_) {
        for (int i = max_; i > max; i--) { //int conversion here
            removeSticker(i);
        }
    }
    max_ = max; 
}
void StickerSheet::removeSticker(unsigned index) {
    if (index == max_) {
        if (current_max_ == max_) {
            current_max_ = static_cast<int>(current_max_) - 1;
        }
        max_ = static_cast<int>(max_) - 1;
    }
    if (index < max_) {
        int max_2 = max_;
        int index2 = index;
        Image* temp = new Image[max_2 - index2];
        int count = 0;
        for (int i = index2 + 1; i < max_; i++) {
            temp[count] = picture_[i];
            count++;
        }
        changeMaxStickers(index2 - 1);
        changeMaxStickers(max_2 - 1);
        for (int i = index2; i < max_; i++) {
            picture
        }

    }
}
bool StickerSheet::translate(int num, int x, int y) { return false; }

//getters
Image* StickerSheet::getSticker(unsigned index) { return nullptr; }
unsigned StickerSheet::getMax() const { return max_; }

//helpers
Image* StickerSheet::getStickerConst(unsigned index) const { return nullptr; }