#include "Image.h"
#include "StickerSheet.h"

int main() {
  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  Image myImage;
  myImage.readFromFile("../alma.png");
  // for (unsigned row = 0; row < myImage.height(); row++) {
  //   for (unsigned col = 0; col < myImage.width(); col++) {
  //     myImage.getPixel(col, row) = cs225::HSLAPixel();
  //   }
  // }
  // myImage.darken(0.2);
  StickerSheet sticker_sheet(myImage, 1);
  Image i_sticker;
  i_sticker.readFromFile("../i.png");
  sticker_sheet.addSticker(i_sticker, 0, 0);
  sticker_sheet.changeMaxStickers(2);
  sticker_sheet.addSticker(i_sticker, 1000, 0);
  // sticker_sheet.addSticker(i_sticker, 0, 100);
  // sticker_sheet.addSticker(i_sticker, 0, 1000);
  // sticker_sheet.changeMaxStickers(3);
  // sticker_sheet.addSticker(i_sticker, 0, 1000);
  // sticker_sheet.addSticker(i_sticker, 20, 40);
  // // sticker_sheet.changeMaxStickers(1);
  myImage = sticker_sheet.render();
  
  //copied from test case "StickerSheet::changeMaxStickers() does not discard original stickers when resized smaller"
  // StickerSheet sheet(myImage, 5); //changed alma -> myImage
  // sheet.addSticker(i_sticker, 20, 200); //changed i -> i_sticker

  // sheet.changeMaxStickers(3);
  //end copy
  
  // myImage = sheet.render();
  myImage.scale(300, 500);
  myImage.writeToFile("../myImage2.png");

  return 0;
}
