#include "List.h"

int main() {

  std::cout << "Empty list: ";
  List<int> list;
  list.print();
  std::cout << std::endl;
  std::cout << "Insert (1) at front: ";
  list.insertFront(1);
  list.print();
  std::cout << " expected: {1} " << std::endl;
  std::cout << "Insert (0) at back: ";
  list.insertBack(0);
  list.print();
  std::cout << " expected: {0, 1} " << std::endl;
  std::cout << "list.size() : " << list.size() << " expected: 2" << std::endl; 
  std::cout << "list.empty() : " << list.size() << " expected: false" << std::endl; 
  
  std::cout << "list2" << std::endl;
  List<int> list2(list);
  list2.print();
  std::cout << " expected: {0, 1} " << std::endl;
  std::cout << "list 2 Insert (90) at front: ";
  list2.insertFront(90);
  list2.print();
  std::cout << " expected: {90, 0, 1} " << std::endl;
  std::cout << "list 2 Insert (99) at back: ";
  list2.insertBack(99);
  std::cout << " expected: {90, 0, 1, 99} " << std::endl;
  std::cout<< std::endl;
  std::cout << "list2.size() : " << list2.size() << " expected: 4" << std::endl; 
  std::cout << "list2.empty() : " << list2.size() << " expected: false" << std::endl; 

  std::cout << "list3" << std::endl;
  List<int> list3 = list2;
  list3.print();
  std::cout << " expected: {0, 1} " << std::endl;
  std::cout << "list 3 Insert (80) at front: ";
  list3.insertFront(80);
  list3.print();
  std::cout << " expected: {80, 0, 1} " << std::endl;
  std::cout << "list 3 Insert (88) at back: ";
  list3.insertBack(88);
  list3.print();
  std::cout << " expected: {80, 0, 1, 88} " << std::endl;
  std::cout << "list3.size() : " << list3.size() << " expected: 4" << std::endl; 
  std::cout << "list3.empty() : " << list3.size() << " expected: false" << std::endl; 

  std::cout << "Back to list" << std::endl;
  std::cout << "list.insertBack(2)";
  list.insertBack(2);
  list.print();
  std::cout << std::endl;
  std::cout << "list.insertBack(3)";
  list.insertBack(3);
  list.print();
  std::cout << std::endl;
  std::cout << "list.insertBack(4)";
  list.insertBack(4);
  list.print();
  std::cout << std::endl;
  std::cout << "list.insertBack(5)";
  list.insertBack(5);
  list.print();
  std::cout << std::endl;
  std::cout << "list.reverse(): " << std::endl;
  list.reverse();
  list.print();
  std::cout << std::endl;
  std::cout << "list.reverseNth(3): " << std::endl;
  list.reverseNth(3);
  list.print();
  std::cout << " expected: {3, 4, 5, 2, 1}"<< std::endl;
  std::cout << "list.reverseNth(4): " << std::endl;
  list.reverseNth(4);
  list.print();
  std::cout << " expected: {2, 5, 4, 3, 1}"<< std::endl;
  std::cout << "list.reverseNth(2): " << std::endl;
  list.reverseNth(2);
  list.print();
  std::cout << " expected: {5, 2, 4, 3, 1}"<< std::endl;
  std::cout << "list.reverseNth(5): " << std::endl;
  list.reverseNth(2);
  list.print();
  std::cout << " expected (call reverse): {1, 3, 4, 2, 5}" << std::endl;
  std::cout << "list.insertBack(6)";
  list.insertBack(6);
  list.print();
  std::cout << " expected: {1, 3, 4, 2, 5, 6}" << std::endl;
  std::cout << "list.reverseNth(6): " << std::endl;
  list.reverseNth(6);
  list.print();
  std::cout << " expected (call reverse): {6, 5, 2, 4, 3, 1}" << std::endl;

  return 0;
}
