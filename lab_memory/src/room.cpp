/**
 * @file room.cpp
 * Implementation of the Room class.
 */

#include <iostream>
#include "room.h"

Room::Room()
    : capacity(0), count(0), max_letters(26), letters(nullptr), letterCount(0)
{ //could call the other construtor here, but chose not to to maintain the previous code
    letters = new Letter[max_letters];
}

Room::Room(const std::string& init_name, int init_capacity)
    : name(init_name),
      capacity(init_capacity),
      count(0),
      max_letters(26),
      letterCount(0)
{
    letters = new Letter[max_letters];
}

Room::Room(const Room& other)
{
    copy(other);
}

Room& Room::operator=(const Room& other)
{
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

Room::~Room()
{
    clear();
}

void Room::addLetter(const Letter& L)
{
    if (letterCount < 0) {
        std::cout << "Letter count is less than 0." << std::endl;
    }
    if (letterCount >= 26) {
        std::cout << "Letter count has reached max capacity, no more letters can be added." << std::endl;
    } else {
        // letters[letterCount] = L;
        count += L.count;
        letterCount++;
    }
}

int Room::spaceRemaining()
{
    return capacity - count;
}

void Room::print(std::ostream & stream /* = std::cout */)
{
    stream << name << " (" << count << "/" << capacity << "):";
    for (int L = 0; L < letterCount; L++)
        stream << " " << letters[L].letter;
    stream << std::endl;
}

void Room::clear()
{
    if (letters != nullptr) {
        delete[] letters;
        letters = nullptr;
    }
}

void Room::copy(const Room& other)
{
    name = other.name;
    capacity = other.capacity;
    count = other.count;
    letterCount = other.letterCount;
    letters = other.letters;

}
