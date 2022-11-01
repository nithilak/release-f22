#include <iostream>
#include "dsets.h"
#include "maze.h"
#include "cs225/PNG.h"

using namespace std;

int main()
{
    // Write your own main here
    cout << "Add your own tests here! Modify main.cpp" << endl;
    cout << "default constructor" << endl;
    DisjointSets dset;
    cout << "setsize: " << dset.setsize() << endl;
    dset.print();
    cout << "add 2 elements" << endl;
    dset.addelements(2);
    cout << "setsize: " << dset.setsize() << endl;
    dset.print();
    cout << "add 1 element" << endl;
    dset.addelements(1);
    cout << "setsize: " << dset.setsize() << endl;
    dset.print();
    cout << "add 3 elements" << endl;
    dset.addelements(3);
    cout << "setsize: " << dset.setsize() << endl;
    dset.print();
    cout << "add 2 elements" << endl;
    dset.addelements(2);
    cout << "setsize: " << dset.setsize() << endl;
    dset.print();
    cout << "add 4 elements" << endl;
    dset.addelements(4);
    cout << "setsize: " << dset.setsize() << endl;
    dset.print();

    cout << "find every element" << endl;

    for (int i = 0; i < dset.setsize(); i++) {
        cout << i << ": " << dset.find(i) << endl;
    }

    cout << "size of every element" << endl;

    for (int i = 0; i < dset.setsize(); i++) {
        cout << i << ": " << dset.size(i) << endl;
    }

    cout << "set union the last two sets" << endl;

    dset.setunion(1, 7); //change this to the other order, and it should flip
    // dset.setunion(7, 9); //test this separately

    cout << "find every element" << endl;

    for (int i = 0; i < dset.setsize(); i++) {
        cout << i << ": " << dset.find(i) << endl;
    }

    cout << "size of every element" << endl;

    for (int i = 0; i < dset.setsize(); i++) {
        cout << i << ": " << dset.size(i) << endl;
    }


    // cout << "2: " << dset.size(0) << endl;
    // cout << "1: " << dset.size(3) << endl;
    // cout << "3: " << dset.size(6) << endl;
    // cout << "2: " << dset.size(8) << endl;
    // cout << "4: " << dset.size(12) << endl;

    return 0;
}
