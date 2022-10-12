
#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.

  Animation animation;
  PNG png;
  png.readFromFile("/workspaces/cs225env/release-f22/mp_traversals/i.png");
  FloodFilledImage fli(png);
  // Point point1(29, 34);
  // BFS* traversal = nullptr;
  // ColorPicker* colorPicker = nullptr;
  // Point point2(30, 35);
  // DFS* traversal2 = nullptr;
  // fli.addFloodFill(*traversal, *colorPicker);
  // fli.addFloodFill(*traversal2, *colorPicker);
  animation = fli.animate(34);
  
  
  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("/workspaces/cs225env/release-f22/mp_traversals/myFloodFill.png");
  animation.write("/workspaces/cs225env/release-f22/mp_traversals/myFloodFill.gif");
  


  return 0;
}
