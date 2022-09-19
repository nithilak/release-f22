/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() : head_(NULL), tail_(NULL), length_(0) { 
  // @TODO: graded in MP3.1
    // head_ = NULL;
    // tail_ = NULL;
    // // length_ = 0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  if (tail_ == nullptr){
    if (head_ == nullptr) {

    }
    return NULL;
  }
  return List<T>::ListIterator(tail_ -> next); //should be NULL/nullptr when I set it manually
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  // if (length_ >= 2) {
    // std::cout << "delete: " << std::endl;
    for (ListNode* current = head_; current != nullptr;) {
      ListNode* temp = current;
      current -> prev = nullptr;
      current = current->next;
      head_ = current;
      // printv2();
      temp -> prev = nullptr;
      temp -> next = nullptr;
      delete temp;
      temp = nullptr;
    }
  // }
  // if (head_ != nullptr) {
  //   delete head_;
  // }
  head_ = nullptr;
  // if (tail_ != nullptr) {
  //   delete tail_;
  // }
  tail_ = nullptr;
  //length_ = 0;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1

  ListNode * newNode = new ListNode(ndata);
  newNode -> prev = NULL;
  // newNode -> next = NULL;

  if (length_ == 0) {
    newNode -> next = NULL;
    head_ = newNode;
    // newNode -> next = NULL;
    // head_ -> next = tail_;
    tail_ = head_;
  } else {
    ListNode* temp = head_;
    head_ = newNode;
    head_ -> next = temp;
    temp -> prev = head_;
    // head_ -> next = tail_;
    if (tail_ == NULL) {
      tail_ = temp;
      // tail_ -> next = NULL; //not so sure about this one
      // head -> next should have alrady been nullptr
    }
  
  }
  length_++;

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1

  if (length_ == 0) {
    insertFront(ndata); //could just make this a helper function between both functions
    return;
  }
  //copied from insertFront (old)
  ListNode * newNode = new ListNode(ndata);
  if (length_ == 1) {
    tail_ = newNode;
    tail_ -> prev = head_;
    head_ -> next = tail_;
  } else {
    ListNode* temp = tail_;
    tail_ -> next = newNode;
    tail_ = tail_ -> next;
    tail_ -> prev = temp;
  }
  tail_ -> next = nullptr;
  length_++; //thanks for reminding me, testing
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1

  if (start == NULL) {
    return NULL;
  }

  if (splitPoint >= length_) {
    return NULL;
  }

  length_ = splitPoint;

  ListNode * curr = start;

  if (length_ <= 0) {
    // head_ = nullptr;
    // tail_ = nullptr;
    length_ = 0;
    return NULL;
  }

  if (length_ == 1) {
    if (splitPoint == 0) {
      ListNode* temp = head_;
      head_ = nullptr;
      tail_ = nullptr;
      length_ = 0;
      return temp;
    } else {
      return NULL;
    }

  }

  if (splitPoint <= 0) {
    splitPoint = 0;
    length_ = 0;
    ListNode* temp = head_;
    head_ = tail_->next;
    tail_ = nullptr;
    // length_ = 0;
    return temp;
  }

  splitPoint--;

  for (int i = 0; i < length_ && (i < splitPoint) && curr != NULL && curr != tail_; i++) {
    // std::cout << "i: " << i << std::endl;
    // std::cout << "curr: " << curr << std::endl;
    // std::cout << "curr data: " << curr->data << std::endl;
    // std::cout << "curr->next: " << curr->next << std::endl;
    curr = curr->next;
  }
  // tail_ -> next = nullptr;
  if (curr == NULL) {
    // curr -> prev = nullptr;
    return NULL;
  }

  if (curr != NULL) {
    ListNode* temp = curr;
    curr = curr -> next;
    tail_ = temp;
    curr->prev->next = NULL;
    curr->prev = NULL;
  }

  // ListNode* temp = curr;
  // curr = curr -> next;
  // temp -> next = nullptr;

  // if (curr != NULL) {
  //   ListNode* temp2 = curr;
  //   tail_ = temp;
  //     // tail_ -> prev = temp; //prev to that
  //     // curr->prev->next = NULL;
  //     curr->prev = NULL;
  //     // return curr;
  // }

  return curr;
}

/**
  * Modifies List using the rules for a TripleRotate.
  *
  * This function will to a wrapped rotation to the left on every three 
  * elements in the list starting for the first three elements. If the 
  * end of the list has a set of 1 or 2 elements, no rotation all be done 
  * on the last 1 or 2 elements.
  * 
  * You may NOT allocate ANY new ListNodes!
  */
template <typename T>
void List<T>::tripleRotate() {
  // @todo Graded in MP3.1
  if (length_ == 0 || head_ == nullptr) {
    return;
  }
  if (length_ < 3) {
    return;
  }
  int size = length_;
  ListNode* curr = head_->next;

  if (curr == head_->next) {
    ListNode* one = curr -> prev;
    ListNode* before = nullptr;
    // ListNode* two = curr;
    ListNode* three = curr -> next;
    ListNode* after = three -> next;

    if ((one == nullptr) || (three == nullptr)) {
      return;
    }

    one->prev = three;
    three->next = one;
    one->next = after;
    if (after != nullptr) {
      after->prev = one;
    }
    curr->prev = before;
    

    head_ = curr;
    if (after != nullptr) {
      curr = after->next;
      after->prev = one;
    } else {
      // curr = nullptr;
    }

    size -= 3;
    // this->printv2();
  }


  while (size > 3 && curr != nullptr && curr->next != tail_) {
    ListNode* one = curr -> prev;
    ListNode* before = one -> prev;
    // ListNode* two = curr;
    ListNode* three = curr -> next;
    ListNode* after = three -> next;

    if ((one == nullptr) || (three == nullptr)) {
      return;
    }

    curr->prev = before;
    three->next = one;
    one->prev = three;
    one->next = after;
    before->next = curr;

    if (after != nullptr) {
      curr = after->next;
      after->prev = one;
    } else {
      // curr = nullptr;
    }

    // curr -> next -> next = first;

    // first -> prev = curr -> next;

    // first -> next = last;

    // curr -> prev = before;
    
    size -= 3;
    // this->printv2();
  }
  if (size == 3 && curr != nullptr) {
    std::cout << "curr->data: " << curr->data << std::endl;
    ListNode* one = curr -> prev;
    ListNode* before = one -> prev;
    // ListNode* two = curr;
    ListNode* three = curr -> next;
    ListNode* after = three -> next;

    if ((one == nullptr) || (three == nullptr)) {
      return;
    }

    // curr->prev = before;
    // // this->printv2();
    // three->next = one;
    // // this->printv2();
    // one->prev = three;
    // // this->printv2();
    // one->next = after;
    // // this->printv2();

    curr->prev = before;
    three->next = one;
    one->prev = three;
    one->next = after;
    before->next = curr;

    // if (after != nullptr) {
    //   curr = after->next;
    //   after->prev = three;
    // } else {
      // tail_ = one;
      // tail_->next = nullptr;
      // curr = nullptr;
    // }

    tail_ = one;

    size -= 3;
    // this->printv2();
  }
}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2
  // std::cout << "start reverse: " << startPoint << " " << endPoint << std::endl;
  // std::cout << "data: " << startPoint->data << " " << endPoint->data << std::endl;
  if (startPoint == endPoint || startPoint == nullptr || endPoint == nullptr) {
    return;
  }
  // if (startPoint->next == endPoint) {
  //   std::cout << "Swap: " << startPoint << " " << endPoint << std::endl;
  //   std::cout << "Swap: " << startPoint->data << " " << endPoint->data << std::endl;
  //   Swap(startPoint, endPoint);
  //   std::cout << "result: " << startPoint << " " << endPoint << std::endl;
  //   return;
  // }
  // std::cout << "Swap: " << startPoint << " " << endPoint << std::endl;
  // std::cout << "Swap: " << startPoint->data << " " << endPoint->data << std::endl;
  // // Swap(startPoint, endPoint);
  // std::cout << "result: " << startPoint << " " << endPoint << std::endl;
  
  // ListIterator startIter = ListIterator(startPoint);
  // // std::cout << "start iter" << std::endl;
  // startIter++;
  // if (startIter == endPoint) {
  //   return;
  // }
  // ListIterator endIter = ListIterator(endPoint);
  // // std::cout << "end iter" << std::endl;
  // endIter--;
  // std::cout << "iters: " << &*startIter << " " << &*endIter << std::endl;
  // std::cout << "data: " << *startIter << " " << *endIter << std::endl;
  // // std::cout << "data again: " << (startIter)->data << " " << (endIter)->data << std::endl;
  // // std::cout << "begin() -> next == startIter" << (begin() -> next == startIter) << std::endl;
  // reverse(&*begin(), NULL); 

  if (startPoint->next == endPoint) {
    return;
  }

  // reverse(startPoint->next, endPoint->prev);
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  return NULL;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  return NULL;
}

//helper function

// template <typename T>
// bool List<T>::operator==(const List<T> & otherList) const {
//   if (!((head_ == otherList.head_) && (tail_ == otherList.tail_) && (length_ == otherList.length_))) {
//     return false;
//   }

//   auto* current_other = otherList.head_; 
//   for (auto* current = head_; (current != nullptr) && (current_other != nullptr); current = current->next) {
    
//     if (current != current_other) {
//       return false;
//     }
//     current_other = current_other->next;
//   }

//   return false;
// }

//helpers

template <typename T>
//copied from List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
void List<T>::Swap(ListNode *& startPoint, ListNode *& endPoint) {
  // std::cout << "start Swap" << std::endl;
  // std::cout << "points: " << startPoint << " " << endPoint << std::endl;
  // std::cout << "data: " << startPoint->data << " " << endPoint->data << std::endl;
  
  if (startPoint == endPoint || (startPoint == nullptr && endPoint == nullptr)) {
    return;
  }

  // if (endPoint == nullptr) {
  //   endPoint = startPoint;
  //   endPoint->prev = startPoint->prev;
  //   endPoint->next = startPoint->next;
  //   startPoint->prev = nullptr;
  //   startPoint->next = nullptr;
  //   startPoint = nullptr;
  //   return;
  // }

  // if (startPoint == nullptr) {
  //   startPoint = endPoint;
  //   startPoint->prev = endPoint->prev;
  //   startPoint->next = endPoint->next;
  //   endPoint->prev = nullptr;
  //   endPoint->next = nullptr;
  //   endPoint = nullptr;
  //   return;
  // }

  
  // ListNode* temp_prev = startPoint->prev;
  // ListNode* temp_next = startPoint->next;

  // startPoint->prev = endPoint->prev;
  // startPoint->next = endPoint->next;

  // endPoint->prev = temp_prev;
  // endPoint->next = temp_next;
  
  ListNode* temp = startPoint;
  startPoint = endPoint;
  endPoint = temp;

  ListNode* temp_prev = startPoint->prev;
  startPoint->prev = endPoint->prev;
  endPoint->prev = temp_prev;

  // std::cout << "startPoint: " << startPoint << std::endl;
  // std::cout << "endPoint: " << endPoint << std::endl;
  // std::cout << "startPoint->next: " << startPoint->next << std::endl;
  // std::cout << "endPoint->next: " << endPoint->next << std::endl;

  ListNode* temp_next = startPoint->next;
  startPoint->next = nullptr;
  // endPoint->next = nullptr;



  // std::cout << "points: " << startPoint << " " << endPoint << std::endl;
  // std::cout << "data: " << startPoint->data << " " << endPoint->data << std::endl;
  // std::cout << "exit Swap" << std::endl;
}
