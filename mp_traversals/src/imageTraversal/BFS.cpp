#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <queue>
#include <vector>

#include "cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "BFS.h"

using namespace cs225;

/**
 * Initializes a breadth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * @param png The image this BFS is going to traverse
 * @param start The start point of this BFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this BFS
 */
BFS::BFS(const PNG & png, const Point & start, double tolerance) : start_(start), png_(png), tolerance_(tolerance), visited(png_.width(), std::vector<bool>(png_.height(), false)) {  
  /** @todo [Part 1] */
  if (tolerance_ < 0) {
    tolerance_ = 0;
  }
  add(start_);
}
//copied from here:
// DFS::DFS(const PNG & png, const Point & start, double tolerance) : png_(png), start_(start), tolerance_(tolerance), visited(png_.width(), std::vector<bool>(png_.height(), false)) {  
//   /** @todo [Part 1] */
//   if (tolerance_ < 0) {
//     tolerance_ = 0;
//   }
//   add(start_);
// }

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator BFS::begin() {
  /** @todo [Part 1] */
  while (!queue.empty()) {
    queue.pop();
  }
  add(start_);
  return ImageTraversal::Iterator(this, queue.front()); //stack.top()
}
//copied from here:
// ImageTraversal::Iterator DFS::begin() {
//   /** @todo [Part 1] */
//   while (!stack.empty()) {
//     stack.pop();
//   }
//   add(start_);
//   return ImageTraversal::Iterator(); //stack.top()
// }

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator BFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator(this, Point(-1, -1));
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void BFS::add(const Point & point) {
  /** @todo [Part 1] */
  if (!visited.at(point.x).at(point.y)) {
    queue.push(point);
  }

  if (tolerance_ < 100) {

  }

  // //     (col, row)
  // //left (1, 0)
  // queue.push(Point(point.x + 1, point.y));
  // //down (0, 1)
  // queue.push(Point(point.x, point.y + 1));
  // //right (-1, 0)
  // size_t i = 0;
  // for (; i + 1 < point.x; i++) {
  // }
  // queue.push(Point(i, point.y));
  // //up (0, -1)
  // size_t j = 0;
  // for (; j + 1 < point.x; j++) {
  // }
  // queue.push(Point(point.x, j));
  // // int count = 0;

  // while (!queue.empty() && count < 100) {
  //   // path_.push_back(queue.front());
  //   queue.pop();
  //   // count++;
  //   // add(queue.front());
  // }
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point BFS::pop() {
  /** @todo [Part 1] */
  std::cout << "pop" << std::endl;
  if (!queue.empty()) {
    Point temp = queue.front();
    queue.pop();
    visited.at(temp.x).at(temp.y) = true;
    std::cout << "Point: " << temp.x << " " << temp.y << std::endl;
    return temp;
  }
  return Point(-1, -1);
}
//copied from here:
// Point DFS::pop() {
//   /** @todo [Part 1] */
//   if (!stack.empty()) {
//     Point temp = stack.top();
//     stack.pop();
//     visited.at(temp.x).at(temp.y) = true;
//     std::cout << "Point: " << temp.x << " " << temp.y << std::endl;
//     return temp;
//   }
//   return Point(0, 0);
// }

/**
 * Returns the current Point in the traversal.
 */
Point BFS::peek() const {
  /** @todo [Part 1] */
  if (!queue.empty()) {
    return queue.front();
  }
  return Point(-1, -1); //from DFS.cpp turns out that Point(0, 0) is the default
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
  /** @todo [Part 1] */
  return queue.empty();
}
