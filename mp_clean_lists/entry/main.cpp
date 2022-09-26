#include "List.h"
// #include "List-ListIterator.hpp"
#include <sstream>
#include <cassert>

int main() {
  //mp part 1
  // std::cout << "Empty list: ";
  List<int> list;
  // list.printv2();
  // std::cout << " expected: {}" << std::endl;
  // std::cout << "list.size() : " << list.size() << " expected: 0" << std::endl; 
  // std::cout << "list.empty() : " << list.empty() << " expected: true" << std::endl; 
  std::cout << "Insert (1) at back: ";
  list.insertBack(1);
  // list.printv2();
  // std::cout << " expected: {1} " << std::endl;
  std::cout << "Insert (0) at front: ";
  list.insertFront(0);
  // list.printv2();
  // std::cout << " expected: {0, 1} " << std::endl;
  // std::cout << "list.size() : " << list.size() << " expected: 2" << std::endl; 
  // std::cout << "list.empty() : " << list.empty() << " expected: false" << std::endl; 
  
  // // std::cout << "list2" << std::endl;
  // // List<int> list2(list);
  // // list2.printv2();
  // // std::cout << " expected: {0, 1} " << std::endl;
  // // std::cout << "list 2 Insert (90) at front: ";
  // // list2.insertFront(90);
  // // list2.printv2();
  // // std::cout << " expected: {90, 0, 1} " << std::endl;
  // // std::cout << "list 2 Insert (99) at back: ";
  // // list2.insertBack(99);
  // // list2.printv2();
  // // std::cout << " expected: {90, 0, 1, 99} " << std::endl;
  // // std::cout << "list2.size() : " << list2.size() << " expected: 4" << std::endl; 
  // // std::cout << "list2.empty() : " << list2.empty() << " expected: false" << std::endl; 

  // // std::cout << "list3" << std::endl;
  // // List<int> list3 = list;
  // // list3.printv2();
  // // std::cout << " expected: {0, 1} " << std::endl;
  // // std::cout << "list 3 Insert (80) at front: ";
  // // list3.insertFront(80);
  // // list3.printv2();
  // // std::cout << " expected: {80, 0, 1} " << std::endl;
  // // std::cout << "list 3 Insert (88) at back: ";
  // // list3.insertBack(88);
  // // list3.printv2();
  // // std::cout << " expected: {80, 0, 1, 88} " << std::endl;
  // // std::cout << "list3.size() : " << list3.size() << " expected: 4" << std::endl; 
  // // std::cout << "list3.empty() : " << list3.empty() << " expected: false" << std::endl; 

  std::cout << "Back to list" << std::endl;
  std::cout << "list.insertBack(2)" << std::endl;;
  list.insertBack(2);
  // list.printv2();
  // std::cout << " expected: {0, 1, 2}" << std::endl;
  // std::cout << "list.size() : " << list.size() << " expected: 3" << std::endl; 
  // std::cout << "list.empty() : " << list.empty() << " expected: false" << std::endl; 
  std::cout << "list.insertBack(3)" << std::endl;;
  list.insertBack(3);
  // list.printv2();
  // std::cout << " expected: {0, 1, 2, 3}" << std::endl;
  // std::cout << "list.size() : " << list.size() << " expected: 4" << std::endl; 
  // std::cout << "list.empty() : " << list.empty() << " expected: false" << std::endl; 
  std::cout << "list.insertBack(4)" << std::endl;;
  list.insertBack(4);
  // list.printv2();
  // std::cout << " expected: {0, 1, 2, 3, 4}" << std::endl;
    // std::cout << "list.size() : " << list.size() << " expected: 5" << std::endl; 
  // std::cout << "list.empty() : " << list.empty() << " expected: false" << std::endl; 
  std::cout << "list.insertBack(5)" << std::endl;;
  list.insertBack(5);
  std::cout << std::endl;
  list.printv2();
  std::cout << " expected: {0, 1, 2, 3, 4, 5}" << std::endl;
  std::cout << std::endl;
  list.printv2back();
  std::cout << " expected: {5, 4, 3, 2, 1, 0}" << std::endl;
  std::cout << std::endl;
  std::cout << "list.size() : " << list.size() << " expected: 6" << std::endl; 
  std::cout << "list.empty() : " << list.empty() << " expected: false" << std::endl; 
  // std::cout << "list.reverse(): " << std::endl;
  // std::cout << std::endl;
  // list.reverse();
  // std::cout << std::endl;
  // list.printv2();
  // std::cout << " expected: {5, 4, 3, 2, 1, 0}" << std::endl;
  // std::cout << std::endl;
  // list.printv2back();
  // std::cout << " expected: {0, 1, 2, 3, 4, 5}" << std::endl;


  // std::cout << "list01" << std::endl;
  // List<int> list01;
  // list01.insertBack(0);
  // list01.insertBack(1);
  // list01.printv2();
  // std::cout << " expected: {0, 1}" << std::endl;
  // list01.printv2back();
  // std::cout << " expected: {1, 0}" << std::endl;
  // std::cout << "list.size() : " << list01.size() << " expected: 2" << std::endl; 
  // std::cout << "list.empty() : " << list01.empty() << " expected: false" << std::endl; 
  // list01.reverse();
  // list01.printv2();
  // std::cout << " expected: {1, 0}" << std::endl;
  // list01.printv2back();
  // std::cout << " expected: {0, 1}" << std::endl;

  // std::cout << std::endl;
  // std::cout << "list07" << std::endl;
  // List<int> list07;
  // for (int i = 0; i < 7; i++) {
  //   list07.insertBack(i);
  // }
  // std::cout << std::endl;
  // list07.printv2();
  // std::cout << " expected: {0, 1, 2, 3, 4, 5, 6}" << std::endl;
  // std::cout << std::endl;
  // list07.printv2back();
  // std::cout << " expected: {6, 5, 4, 3, 2, 1, 0}" << std::endl;
  // std::cout << "list.size() : " << list07.size() << " expected: 7" << std::endl; 
  // std::cout << "list.empty() : " << list07.empty() << " expected: false" << std::endl; 
  // std::cout << std::endl;
  // list07.reverse();
  // std::cout << std::endl;
  // std::cout << std::endl;
  // list07.printv2();
  // std::cout << " expected: {6, 5, 4, 3, 2, 1, 0}" << std::endl;
  // std::cout << std::endl;
  // list07.printv2back();
  // std::cout << " expected: {0, 1, 2, 3, 4, 5, 6}" << std::endl;


  // std::cout << "\nlist: ";
  // list.printv2();
  // std::cout << " expected: {0, 1, 2, 3, 4, 5}" << std::endl;
  // std::cout << "list split at 2" << std::endl;
  // List<int> list4 = list.split(1);
  // list.printv2();
  // std::cout << " expected: {0, 1}" << std::endl;
  // list4.printv2();
  // std::cout << " expected: {2, 3, 4, 5}" << std::endl;

  // // done with this part of the mp at least fot now since it seems to be working correctly
  //  straight from the test case, please help what it going on here
  // const int kListSize = 6;
  // const int kSplitNum = 1;

  //   List<int> list;
  //   for (int i = 0; i < kListSize; i++) {
  //       list.insertBack(i);
  //   }
  //   // std::cout << "\nlist: ";
  //   // list.printv2();
  //   // std::cout << " expected: {0, 1, 2, 3, 4, 5}" << std::endl;

  //   stringstream s;
  //   list.print(s);  

  //   assert("< 0 1 2 3 4 5 >" == s.str());

  //   stringstream s2;

  //   // std::cout << "list split at 2" << std::endl;
  //   List<int> list4 = list.split(kSplitNum);

  //   list.print(s2);  

  //   list.printv2();

  //   assert("< 0 >" == s2.str());

  //   stringstream s3;

  //   list4.print(s3);  

  //   list4.printv2();

  //   assert("< 1 2 3 4 5 >" == s3.str());

  //   // list.printv2();
  //   // std::cout << " expected: {0, 1}" << std::endl;
  //   // list4.printv2();
  //   // std::cout << " expected: {2, 3, 4, 5}" << std::endl;

  //   //copied to test it in main
  //   //TEST_CASE("List::split simple", "[weight=5][part=1][valgrind]") {
  //   List<int> list3;

  //   list3.insertBack(1);
  //   list3.insertBack(2);
  //   list3.insertBack(3);
  //   list3.insertBack(4);

  //   List<int> slist = list3.split(2);
  //   stringstream s1, s4;

  //   std::cout << "list3" << std::endl;
  //   list3.print(s1);
  //   list3.printv2();
  //   std::cout << "slist" << std::endl;
  //   slist.print(s4);
  //   slist.printv2();

  //   assert( "< 1 2 >" == s1.str() );
  //   assert( "< 3 4 >" == s4.str() );




  // List<int> list;
  // for (int i = 0; i < 6; i++) {
  //   list.insertBack(i);
  // }
  // list.printv2();
  // std::cout << "list.size() : " << list.size() << " expected: 6" << std::endl; 
  // std::cout << "list.empty() : " << list.empty() << " expected: false" << std::endl; 
  

  // // mp part 2
  // std::cout << std::endl;
  // std::cout << "list.reverseNth(3): " << std::endl;
  // std::cout << std::endl;
  // list.print();
  // std::cout << std::endl;
  // list.reverseNth(3);
  // std::cout << std::endl;
  // list.printv2();
  // std::cout << " expected: {2, 1, 0, 5, 4, 3}"<< std::endl;
  // std::cout << std::endl;
  // list.printv2back();
  // std::cout << " expected: {3, 4, 5, 0, 1, 2}"<< std::endl;

  // std::cout << std::endl;
  // std::cout << "list.reverseNth(4): " << std::endl;
  // std::cout << std::endl;
  // list.print(); // {0, 1, 2, 3, 4, 5}
  // std::cout << std::endl;
  // list.reverseNth(4);
  // std::cout << std::endl;
  // list.printv2();
  // std::cout << " expected: {3, 2, 1, 0, 5, 4}"<< std::endl;
  // std::cout << std::endl;
  // list.printv2back();
  // std::cout << " expected: {4, 5, 0, 1, 2, 3}"<< std::endl;

  // std::cout << "insertBack(6)" << std::endl;
  // list.insertBack(6);
  // std::cout << std::endl;
  // std::cout << "list.reverseNth(4): " << std::endl;
  // std::cout << std::endl;
  // list.print(); // {0, 1, 2, 3, 4, 5, 6}
  // std::cout << std::endl;
  // list.reverseNth(4);
  // std::cout << std::endl;
  // list.printv2();
  // std::cout << " expected: {3, 2, 1, 0, 6, 5, 4}"<< std::endl;
  // std::cout << std::endl;
  // list.printv2back();
  // std::cout << " expected: {4, 5, 6, 0, 1, 2, 3}"<< std::endl;

  // std::cout << "insertBack(6)" << std::endl;
  // list.insertBack(6);
  // std::cout << std::endl;
  // std::cout << "list.reverseNth(3): " << std::endl;
  // std::cout << std::endl;
  // list.print(); // {0, 1, 2, 3, 4, 5, 6}
  // std::cout << std::endl;
  // list.reverseNth(3);
  // std::cout << std::endl;
  // list.printv2();
  // std::cout << " expected: {2, 1, 0, 5, 4, 3, 6}"<< std::endl;
  // std::cout << std::endl;
  // list.printv2back();
  // std::cout << " expected: {6, 3, 4, 5, 0, 1, 2}"<< std::endl;

  // std::cout << "insertBack(6)" << std::endl;
  // list.insertBack(6);
  // std::cout << "insertBack(7)" << std::endl;
  // list.insertBack(7);
  // std::cout << std::endl;
  // std::cout << "list.reverseNth(4): " << std::endl;
  // std::cout << std::endl;
  // list.print(); // {0, 1, 2, 3, 4, 5, 6, 7}
  // std::cout << std::endl;
  // list.reverseNth(4);
  // std::cout << std::endl;
  // list.printv2();
  // std::cout << " expected: {3, 2, 1, 0, 7, 6, 5, 4}"<< std::endl;
  // std::cout << std::endl;
  // list.printv2back();
  // std::cout << " expected: {4, 5, 6, 7, 0, 1, 2, 3}"<< std::endl;

  // std::cout << "insertBack(6)" << std::endl;
  // list.insertBack(6);
  // std::cout << "insertBack(7)" << std::endl;
  // list.insertBack(7);
  // std::cout << std::endl;
  // std::cout << "list.reverseNth(3): " << std::endl;
  // std::cout << std::endl;
  // list.print(); // {0, 1, 2, 3, 4, 5, 6, 7}
  // std::cout << std::endl;
  // list.reverseNth(3);
  // std::cout << std::endl;
  // list.printv2();
  // std::cout << " expected: {2, 1, 0, 5, 4, 3, 7, 6}"<< std::endl;
  // std::cout << std::endl;
  // list.printv2back();
  // std::cout << " expected: {6, 7, 3, 4, 5, 0, 1, 2}"<< std::endl;

  // std::cout << "insertBack(6)" << std::endl;
  // list.insertBack(6);
  // std::cout << "insertBack(7)" << std::endl;
  // list.insertBack(7);
  // std::cout << "insertBack(8)" << std::endl;
  // list.insertBack(8);
  // std::cout << std::endl;
  // std::cout << "list.reverseNth(4): " << std::endl;
  // std::cout << std::endl;
  // list.print(); // {0, 1, 2, 3, 4, 5, 6, 7, 8}
  // std::cout << std::endl;
  // list.reverseNth(4);
  // std::cout << std::endl;
  // list.printv2();
  // std::cout << " expected: {3, 2, 1, 0, 7, 6, 5, 4, 8}"<< std::endl;
  // std::cout << std::endl;
  // list.printv2back();
  // std::cout << " expected: {8, 4, 5, 6, 7, 0, 1, 2, 3}"<< std::endl;



  // std::cout << "list.reverseNth(4): " << std::endl;
  // list.reverseNth(4);
  // list.printv2();
  // std::cout << " expected: {3, 2, 1, 0, 5, 4"<< std::endl;
  // std::cout << "list.reverseNth(2): " << std::endl;
  // list.reverseNth(2);
  // list.printv2();
  // std::cout << " expected: {1, 0, 3, 2, 5, 4}"<< std::endl;
  // std::cout << "list.reverseNth(5): " << std::endl;
  // list.reverseNth(2);
  // list.printv2();
  // std::cout << " expected (call reverse): {0, 1, 3, 4, 2, 5}" << std::endl;
  // std::cout << "list.insertBack(6)";
  // list.insertBack(6);
  // list.printv2();
  // std::cout << " expected: {0, 1, 3, 4, 2, 5, 6}" << std::endl;
  // std::cout << "list.reverseNth(6): " << std::endl;
  // list.reverseNth(6);
  // list.printv2();
  // std::cout << " expected (call reverse): {6, 5, 2, 4, 3, 1, 0}" << std::endl;

  // list.reverse();
  List<int> list2;

  list2.insertBack(6);
  list2.insertBack(2);
  list2.insertBack(9);
  list2.insertBack(4);
  list2.insertBack(8);
  list2.insertBack(43);
  list2.insertBack(2);
  list2.insertBack(200);
  list2.insertBack(2);
  list2.insertBack(235);
  list2.insertBack(8675);
  // list2.insertBack(-1);
  // list2.insertBack(-5);
  list2.insertBack(132);
  list2.insertBack(7);

  // list2.insertBack(-5);
  // list2.insertBack(-1);
  // list2.insertBack(2);
  // list2.insertBack(2);
  // list2.insertBack(2);
  // list2.insertBack(4);
  // list2.insertBack(6);
  // list2.insertBack(7);
  // list2.insertBack(8);
  // list2.insertBack(9);
  // list2.insertBack(43);
  // list2.insertBack(132);
  // list2.insertBack(200);
  // list2.insertBack(235);
  // list2.insertBack(8675);


  //mergeWith
  // list2.printv2();
  // std::cout << " expected: {2, 2, 2, 4, 6, 7, 8, 9, 43, 132, 200, 235, 8675}" << std::endl;
  // list2.printv2back();
  // std::cout << " expected: {8675, 235, 200, 132, 43, 9, 8, 7, 6, 4, 2, 2, 2}" << std::endl;
  // list.mergeWith(list2);
  // list2.printv2();
  // std::cout << " expected: {}" << std::endl;
  // list2.printv2back();
  // std::cout << " expected: {}" << std::endl;
  // list.printv2();
  // std::cout << " expected: {0, 1, 2, 2, 2, 2, 3, 4, 4, 5, 6, 7, 8, 9, 43, 132, 200, 235, 8675}" << std::endl;
  // list.printv2back();
  // std::cout << " expected: {8675, 235, 200, 132, 43, 9, 8, 7, 6, 5, 4, 4, 3, 2, 2, 2, 2, 2, 0}" << std::endl;

  //mergesort
  list2.printv2();
  list2.printv2back();
  // list.reverse();
  // std::cout << "sort: " << std::endl;
  // List<int> list3;
  // list3.insertBack(6);
  // List<int> list4;
  // list4.insertBack(2);
  // list4.insertBack(9);
  // list3.mergeWith(list4);
  // list2.sort();
  // std::cout << "final: " << std::endl;
  // list2.printv2();
  // list2.printv2back();

  //iterator
  List<int>::ListIterator listIter = list.end();
  // for (int i = 0; i + 1 < list.size(); i++) {
  //   std::cout << "*listIter: " << *listIter << std::endl;
  //   listIter++;
  // }

  // std::cout << "*listIter: " << *listIter << std::endl;
  // listIter++;
  // std::cout << "listIter: " << listIter << std::endl;
  listIter--;
  std::cout << "*listIter: " << *listIter << std::endl;

  return 0;
}
