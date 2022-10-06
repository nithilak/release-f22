#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"

/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * 
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */                                                                                                                 //copied from BFS.cpp (visited constructor)
DFS::DFS(const PNG & png, const Point & start, double tolerance) : png_(png), start_(start), tolerance_(tolerance), visited(png_.width(), std::vector<bool>(png_.height(), false)) {  
  /** @todo [Part 1] */
  if (tolerance_ < 0) {
    tolerance_ = 0;
  }
  add(start_);
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  while (!stack.empty()) {
    stack.pop();
  }
  add(start_);
  std::cout << "start: " << start_.x << " " << start_.y << std::endl;
  return ImageTraversal::Iterator(this, start_, start_, png_, tolerance_); //stack.top()
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator(this, Point(-1, -1), start_, png_, tolerance_);
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
  //copied from BFS.cpp, queue -> stack
  //we do not control what they do with these points, only if it is included or not
  //tolerance is declared here so that it can be used in the upper class, I think
  // std::cout << "Point: " << point.x << " " << point.y << std::endl;
  stack.push(point); //not even the next after this? ok then
  // //     (col, row)
  // //left (1, 0)
  // if (!visited.at(point.x + 1).at(point.y)) {
  //   // std::cout << "Point left: " << point.x + 1 << " " << point.y << std::endl;
  //   stack.push(Point(point.x + 1, point.y));
  // }
  // //down (0, 1)
  // if (!visited.at(point.x).at(point.y + 1)) {
  //   // std::cout << "Point down: " << point.x << " " << point.y + 1 << std::endl;
  //   stack.push(Point(point.x, point.y + 1));
  // }
  // //right (-1, 0)
  // size_t i = 0;
  // for (; i + 1 < point.x; i++) {
  // }
  // if (!visited.at(i).at(point.y)) {
  //   // std::cout << "Point right: " << i << " " << point.y << std::endl;
  //   stack.push(Point(i, point.y));
  // }
  // //up (0, -1)
  // size_t j = 0;
  // for (; j + 1 < point.x; j++) {
  // }
  // if (!visited.at(point.x).at(j)) {
  //   // std::cout << "Point up: " << point.x << " " << j << std::endl;
  //   stack.push(Point(point.x, j));
  // }
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  if (!stack.empty()) {
    Point temp = stack.top();
    stack.pop();
    visited.at(temp.x).at(temp.y) = true;
    std::cout << "Point: " << temp.x << " " << temp.y << std::endl;
    return temp;
  }
  return Point(0, 0);
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  //copied from Point DFS::pop(), then modified a little bit
  if (!stack.empty()) {
    return stack.top();
  }
  return Point(0, 0);
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  return stack.empty();
}
