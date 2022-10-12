#include <cmath>
#include <iterator>
#include <iostream>

#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator(ImageTraversal* traversal, const Point& point, const PNG& png, double tolerance) : traversal_(traversal), point_(point), png_(png), tolerance_(tolerance) {
  /** @todo [Part 1] */
  // std::cout << "traversal point: " << point.x << " " << point.y << std::endl;
  // point_ = point;
  // std::cout << "traversal point_: " << point_.x << " " << point_.y << std::endl;
}

ImageTraversal::Iterator::Iterator() {
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
 //this is where most of the logic of this mp should go.
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  // point_ = pop();
  std::cout << "operator++ on: " << point_ << std::endl;

  //store the top of the data structure, while removing it from the stack/queue
  point_ = traversal_->pop();

  //if this point is the end of the traversal, return, cannot do operation++ from here
  if (point_ == *(traversal_->end())) { //end point is Point(-1, -1) //point_.x == -1 && point_.y == -1
    std::cout << "You have reached the end of the traversal, cannot do operation++ from here." << std::endl;
    return *this;
  }

  //add the top Point's children to the traversal

  Point right = Point(point_.x + 1, point_.y);
  std::cout << "right: " << right << std::endl;
      if (// right.x >= 0 
          // && right.y >= 0 
          // && right.x < png_.width() 
          // & right.y < png_.height() 
          calculateDelta(png_.getPixel(right.x, right.y), png_.getPixel(start_.x, start_.y)) < tolerance_) {
        traversal_->add(right);
      }

  Point below = Point(point_.x, point_.y + 1);
  std::cout << "below: " << below << std::endl;
      if (// below.x >= 0 
          // && below.y >= 0 
          // && below.x < png_.width() 
          // && below.y < png_.height() 
          calculateDelta(png_.getPixel(below.x, below.y), png_.getPixel(start_.x, start_.y)) < tolerance_) {
        traversal_->add(below);
      }


  // size_t i = 0;
  // for (; i + 1 < point_.x; i++) {
  // }
  int num = static_cast<int>(static_cast<int>(point_.x) - static_cast<int>(1));
  std::cout << "this is num: " << num << std::endl;
  Point left = Point(static_cast<int>(static_cast<int>(point_.x) - static_cast<int>(1)), point_.y);
  std::cout << "left: " << left << std::endl;
      if (num >= 0 &&
          // && left.x >= 0 
          // && left.y >= 0 
          // && left.x < png_.width() 
          // && left.y < png_.height() 
          calculateDelta(png_.getPixel(left.x, left.y), png_.getPixel(start_.x, start_.y)) < tolerance_) {
        traversal_->add(left);
      }


  // size_t j = 0;
  // for (; j + 1 < point_.y; j++) {
  // }
  int num2 = static_cast<int>(static_cast<int>(point_.y) - static_cast<int>(1));
  std::cout << "this is num2: " << num2 << std::endl;
  Point above = Point(point_.x, static_cast<int>(static_cast<int>(point_.y) - static_cast<int>(1)));
  std::cout << "above: " << above << std::endl;
      if (num2 >= 0 &&
          // && above.x >= 0 
          // && above.y >= 0 
          // && above.x < png_.width() 
          // && above.y < png_.height() 
          calculateDelta(png_.getPixel(above.x, above.y), png_.getPixel(start_.x, start_.y)) < tolerance_) {
        traversal_->add(above);
      }


  //access the top Point of the stack
  //this can return nullptr if nothing is there
  point_ = traversal_->peek();

  auto* copy = traversal_;
  while (!copy->empty()) {
    std::cout << "traversal copy: " << copy->peek() << std::endl;
    copy->pop();
  }

  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return point_;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  std::cout << "point_: " << point_ << std::endl;
  std::cout << "other.point_: " << other.point_ << std::endl;
  std::cout << "!(point_ == other.point_) " << !(point_ == other.point_) << std::endl; 
  if (other.point_.x > 400) {
    return false; //safety measure for encountering max int value
  }
  return (!(point_ == other.point_));
  // return false;
}

