#include "List.h"
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
  std::cout << "list.insertBack(2)";
  list.insertBack(2);
  // list.printv2();
  // std::cout << " expected: {0, 1, 2}" << std::endl;
  // std::cout << "list.size() : " << list.size() << " expected: 3" << std::endl; 
  // std::cout << "list.empty() : " << list.empty() << " expected: false" << std::endl; 
  std::cout << "list.insertBack(3)";
  list.insertBack(3);
  // list.printv2();
  // std::cout << " expected: {0, 1, 2, 3}" << std::endl;
  // std::cout << "list.size() : " << list.size() << " expected: 4" << std::endl; 
  // std::cout << "list.empty() : " << list.empty() << " expected: false" << std::endl; 
  std::cout << "list.insertBack(4)";
  list.insertBack(4);
  // list.printv2();
  // std::cout << " expected: {0, 1, 2, 3, 4}" << std::endl;
    // std::cout << "list.size() : " << list.size() << " expected: 5" << std::endl; 
  // std::cout << "list.empty() : " << list.empty() << " expected: false" << std::endl; 
  std::cout << "list.insertBack(5)";
  list.insertBack(5);
  list.printv2();
  std::cout << " expected: {0, 1, 2, 3, 4, 5}" << std::endl;
  list.printv2back();
  std::cout << " expected: {5, 4, 3, 2, 1, 0}" << std::endl;
  std::cout << "list.size() : " << list.size() << " expected: 6" << std::endl; 
  std::cout << "list.empty() : " << list.empty() << " expected: false" << std::endl; 
  std::cout << "list.reverse(): " << std::endl;
  list.reverse();
  list.printv2();
  std::cout << " expected: {5, 4, 3, 2, 1, 0}" << std::endl;


  std::cout << "list01" << std::endl;
  List<int> list01;
  list01.insertBack(0);
  list01.insertBack(1);
  list01.printv2();
  std::cout << " expected: {0, 1}" << std::endl;
  list01.printv2back();
  std::cout << " expected: {1, 0}" << std::endl;
  std::cout << "list.size() : " << list01.size() << " expected: 2" << std::endl; 
  std::cout << "list.empty() : " << list01.empty() << " expected: false" << std::endl; 
  list01.reverse();
  list01.printv2();
  std::cout << " expected: {1, 0}" << std::endl;
  list01.printv2back();
  std::cout << " expected: {0, 1}" << std::endl;


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
  // std::cout << "list.reverseNth(3): " << std::endl;
  // list.reverseNth(3);
  // list.printv2();
  // std::cout << " expected: {2, 1, 0, 5, 4, 3}"<< std::endl;
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

  return 0;
}
