#include "Image.h"

#include <iostream>

int main() {
  Image alma;

  std::cout << "Using Image::lighten to create `lighten.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.lighten(0.2);
  alma.writeToFile("../lighten.png");

  std::cout << "Using Image::saturate to create `saturate.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.saturate(0.2);
  alma.writeToFile("../saturate.png");

  std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.scale(2);
  alma.writeToFile("../scale2x.png");

  std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.scale(0.5);
  alma.writeToFile("../scale0.5x.png");

  std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.scale(0);
  alma.writeToFile("../scale0x.png");

  std::cout << "Using Image::illinify to create `illnify.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.illinify();
  alma.writeToFile("../illinify.png");

  //more scale tests, copy and pasted the format as usual

  std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.scale(200, 500);
  alma.writeToFile("../scale200-500x.png");

  std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.scale(500, 200);
  alma.writeToFile("../scale500-200x.png");

  std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.scale(0, 235);
  alma.writeToFile("../scale0-235x.png");

  std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.scale(235, 0);
  alma.writeToFile("../scale235-0x.png");

  std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.scale(713, 252);
  alma.writeToFile("../scale713-252x.png");

  std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.scale(252, 713);
  alma.writeToFile("../scale252-713x.png");

  std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.scale(19, 19);
  alma.writeToFile("../scale19-19x.png");

  std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.scale(213, 213);
  alma.writeToFile("../scale213-213x.png");

  return 0;
}
