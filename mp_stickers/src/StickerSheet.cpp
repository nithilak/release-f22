#include "StickerSheet.h"

StickerSheet::StickerSheet() : max_(0), picture_(new Image()), layers_(std::vector<ImagePoint>()) {
}
StickerSheet::StickerSheet(const Image& picture, unsigned max) : max_(max), picture_(new Image()), layers_(std::vector<ImagePoint>()) {
    *picture_ = picture;
    // std::cout << "(picture_ == &picture)" << (picture_ == &picture) << std::endl;
    // std::cout << "(*picture_ == picture)" << (*picture_ == picture) << std::endl;
}
StickerSheet::~StickerSheet() {
    changeMaxStickers(0);
    delete picture_;
    picture_ = nullptr;
}
StickerSheet::StickerSheet(const StickerSheet& other) {
    if (this == &other) {
        return;
    }
    copyConstructor(other);
}
const StickerSheet& StickerSheet::operator=(const StickerSheet& other) {
    if (this == &other) {
        return *this;
    }
    copyConstructor(other);
    return *this;
}
int StickerSheet::addSticker(Image& sticker, unsigned x, unsigned y) { 
    //iterate through all of sticker
    if (layers_.size() >= max_) { //neither number here can go belows zero
        return -1; 
    } // else {
    //     current_layer_++;
    // }
    // Image layer = *picture_;
    // int h = layer.height();
    // int w = layer.width();
    // int sticker_height = sticker.height();
    // int sticker_width = sticker.width();
    // int x2 = x;
    // int y2 = y;
    // int row_diff = sticker_height - (h - y2);
    // int col_diff = sticker_width - (w - x2);
    // if (row_diff >= sticker_height || col_diff >= sticker_width) {
    //     return -1;
    // }
    layers_.push_back(ImagePoint(sticker, Point(x, y)));
    return layers_.size() - 1; 
}
Image StickerSheet::render() const { 
    Image layer = *picture_;
    for (size_t i = 0; i < layers_.size(); i++) {
        const ImagePoint& pair = (layers_.at(i));
        const Image& sticker = pair.image;
        unsigned layer_height = layer.height();
        unsigned layer_width = layer.width();
        unsigned sticker_height = sticker.height();
        unsigned sticker_width = sticker.width();
        unsigned x = pair.point.x;
        unsigned y = pair.point.y;
        // int x2 = pair.point.x;
        // int y2 = pair.point.y;

        // std::cout << "width(): " << layer.width() << std::endl;
        // std::cout << "height(): " << layer.height() << std::endl;

        // int row_diff = sticker_height - (h - y2);
        unsigned max_row_size = y + sticker_height;
        // std::cout << "row_diff: " << row_diff << std::endl;
        // std::cout << "max_row_size: " << max_row_size << std::endl;
        // int col_diff = sticker_width - (w - x2);
        unsigned max_col_size = x + sticker_width;
        // std::cout << "col_diff: " << col_diff << std::endl;
        // std::cout << "max_col_size: " << max_col_size << std::endl;
        if (max_row_size <= layer_height && max_col_size <= layer_width) {
            // removeSticker(i);
            // i--;
            // continue;
            // break;
        } else if (max_row_size > layer_height && max_col_size > layer_width) {
            layer.resize(max_col_size, max_row_size);
        } else if (max_row_size > layer_height) {
            layer.resize(layer_width, max_row_size);
        } else if (max_col_size > layer_width) {
            layer.resize(max_col_size, layer_height);
        }
        // layer.resize(10000, 10000); //this is here for testing purposes only
        // std::cout << "width(): " << layer.width() << std::endl;
        // std::cout << "height(): " << layer.height() << std::endl;
        for (unsigned row = 0; (row < sticker_height) && ((y + row) < layer.height()); row++) {
            for (unsigned col = 0; (col < sticker_width) && ((x + col) < layer.width()); col++) {
                const cs225::HSLAPixel& kcurrent_pixel = sticker.getPixel(col, row);
                if (kcurrent_pixel.a != 0) {
                    layer.getPixel(x + col, y + row) = kcurrent_pixel;
                    // std::cout << "(layer.getPixel(x + col, y + row) == kcurrent_pixel)" << (layer.getPixel(x + col, y + row) == kcurrent_pixel) << std::endl;
                    // std::cout << "(&layer.getPixel(x + col, y + row) == &kcurrent_pixel)" << (&layer.getPixel(x + col, y + row) == &kcurrent_pixel) << std::endl;
                }
            }
        }
    }
    return layer; 
} //&?
void StickerSheet::changeMaxStickers(unsigned max) { 
    // int max_2 = max_;
    // int max2 = max;
    while (max < layers_.size()) {
        //because the layers are all not necessarily filled to the max_ quantity
        // for (int i = max_2 - 1; (i >= max2) && (layers_.size() > 0); i--) { //int conversion here
            layers_.erase(layers_.begin() + max);
        // }
    }
    max_ = max; 
}
void StickerSheet::removeSticker(unsigned index) {
    if (index >= layers_.size()) {
        // throw std::invalid_argument("index out of bounds");
        // return NULL;
        return;
    }
    layers_.erase(layers_.begin() + index);
}
bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) { 
    if (index >= layers_.size()) { //index cannot be less than zero in this function
        // throw std::invalid_argument("index out of bounds");
        return false;
    }
    Point& point = layers_.at(index).point;
    point.x = x;
    point.y = y;

    // layers_.at(index).second().x = x;
    // layers_.at(index).second().y = y;
    return true;
}

//getters
Image* StickerSheet::getSticker(unsigned index) { 
    if (index >= layers_.size()) { //index cannot be less than zero here
        // throw std::invalid_argument("index out of bounds");
        // return NULL;
        return nullptr;
    }
    return &(layers_.at(index).image);
}
unsigned StickerSheet::getMax() const { return max_; }
const std::vector<ImagePoint>& StickerSheet::getLayers() const { return layers_; }
const Image& StickerSheet::getPicture() const { return *picture_; }

//helpers
const Image* StickerSheet::getStickerConst(unsigned index) const { 
    if (index >= layers_.size()) {
        // throw std::invalid_argument("index out of bounds");
        return nullptr;
    }
    const Image* image = &(layers_.at(index).image);
    return image; 
}

void StickerSheet::copyConstructor(const StickerSheet& other) {
    delete picture_; 
    // if (*picture_ != other.getPicture()) {
        picture_ = new Image();
        Image copy = other.getPicture();
        *picture_ = copy;
    // }
    changeMaxStickers(other.getMax());
    layers_ = other.getLayers();
}