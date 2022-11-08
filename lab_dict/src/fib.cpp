/**
 * @file fib.cpp
 * Contains Fibonacci-number generating functions both utilizing and not
 * utilizing memoization.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "fib.h"

#include <map>
#include <iostream>
#include <vector>

using std::map;

/**
 * Calculates the nth Fibonacci number where the zeroth is defined to be
 * 0.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long fib(unsigned long n)
{
    /* Your code goes here! */
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    std::vector<unsigned long> output = {0, 1};
    for (int i = 1; i < static_cast<int>(n); i++) {
        output.push_back(output.at(0) + output.at(1));
        output.erase(output.begin());
    }
    return output.at(output.size() - 1);
}

/**
 * Calculates the nth Fibonacci number where the zeroth is defined to be
 * 0. This version utilizes memoization.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long memoized_fib(unsigned long n)
{
    /* Your code goes here! */
    static std::map<unsigned long, unsigned long> map {{0, 0}, {1, 1}};

    const std::map<unsigned long, unsigned long>::iterator& find = map.find(n);
    
    if (find != map.end()) {
        return find->second;
    } else {
        unsigned long output = memoized_fib(n - 1) + memoized_fib(n - 2);
        map[n] = output;
        // std::cout << "output: " << output << std::endl;
        return output;
    }
}
