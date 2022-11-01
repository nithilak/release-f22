/* Your code here! */
#include "dsets.h"

void DisjointSets::addelements(int num) {
    /**Your code here*/
    if (num <= 0) {
        return;
    }
    //counter is the new index
    int counter = disjointSets.size();
    for (int i = 0; i < num; i++) {
        disjointSets.push_back(counter);
    }
    disjointSets.at(counter) = (-1)*num;
}

int DisjointSets::find(int elem) {
    /**Your code here*/
    int size = disjointSets.size();
    if (size == 0 || elem < 0 || elem >= size) {
        return -1;
    }
    int current = elem;
    while (current >= 0) {
        int next = disjointSets.at(current);
        if (next < 0) {
            return next;
        }
        current = next;
    }
    return -1;
}

void DisjointSets::setunion(int a, int b) {
    /**Your code here*/
    if (find(a) == find(b)) {
        return;
    }
    int setsize = disjointSets.size();
    if (a >= 0 && b >= 0 && a < setsize && b < setsize) {
        int b_index = find(b);
        int a_index = find(a);
        disjointSets.at(b_index) -= disjointSets.at(a_index);
        disjointSets.at(a_index) = b_index;
    }
}

int DisjointSets::size(int elem) {
    /**Your code here*/
    if (elem >= 0 || elem < disjointSets.size()) {
        return -1*(disjointSets.at(find(elem)));
    }
    return -1;
}





