/* Your code here! */
#include "maze.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <random>
#include <cstdlib>
#include <ctime>

// SquareMaze::SquareMaze() {
//     /**Your code here*/
// }

void SquareMaze::makeMaze(int width, int height) {
    /**Your code here*/
    // maze = {};
    std::vector<bool> maze2(width, height);
    maze = maze2;

    std::srand(std::time(nullptr));

    std::default_random_engine engine;

    int i = 0;
    while (i < 100) { //disjoint set is not one big set
        int row = rand() % height;
        int col = rand() % width;
        std::cout << row << " " << col << std::endl;
        i++;
    }

}

bool SquareMaze::canTravel(int x, int y, int dir) const {
    /**Your code here*/
    return false;
}

void SquareMaze::setWall(int x, int y, int dir, bool exists) {
    /**Your code here*/
}


std::vector<int> SquareMaze::solveMaze() {
    /**Your code here*/
    std::vector<int> output;
    return output;
}

cs225::PNG* SquareMaze::drawMaze() const {
    /**Your code here*/
    return nullptr;
}


cs225::PNG* SquareMaze::drawMazeWithSolution() {
    /**Your code here*/
    return nullptr;
}


