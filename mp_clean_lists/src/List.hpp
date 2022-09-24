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

  //splitPoint < length_

  if (splitPoint <= 0) {
    splitPoint = 0;
    // length_ = 0; 
    // ListNode* temp = head_;
    //do not need to change this, the main function takes care of it for us
    // head_ = nullptr;
    // tail_ = nullptr;
    // length_ = 0;std::cout << "list" << std::endl;
    return head_;
  }

  //splitPoint >= 0

  ListNode * curr = start;

  if (length_ <= 0) {
    // head_ = nullptr;
    // tail_ = nullptr;
    // length_ = 0; //do not mess with this
    return NULL;
  }

  //length >= 1

  // if (length_ == 1) {
  //   if (splitPoint == 1) {
  //     // ListNode* temp = head_;
  //     // head_ = nullptr;
  //     // tail_ = nullptr;
  //     // length_ = 0; //do not mess with this, main does it, this is just a helper function
  //     // return temp;
  //     return head_;
  //   } else {
  //     return NULL;
  //   }
  // }

  //length >= 2 //does not matter, works for length_ = 1 too because head_ exists

  if (splitPoint == 1) {
    // std::cout << "splitPoint == 1" << std::endl;
    // ListNode* temp = head_;
    // head_ = head_->next;
    // temp -> next = nullptr;
    // temp -> prev = nullptr; //just in case
    // head_->prev = nullptr;
    // length_ = 1; //do not mess with this, the main function does it for you, this is a helper, not the main
    // std::cout << "head_" << head_ << std::endl;
    // return temp;
    if (head_ == nullptr) {
      return NULL;
    }
    // std::cout << "head_->data" << head_->data << std::endl;
    ListNode* temp = head_->next;
    head_->next = nullptr;
    if (temp != nullptr) {
      temp -> prev = nullptr;
    }
    tail_ = head_;
    return temp;
  }

  // length_ = splitPoint;

  // splitPoint--; //to make this the index to stop at

  for (int i = 0; (i + 1 < splitPoint) && curr != NULL; i++) { //i <= length_ && // && curr != tail_ //not necessary, if it fails, let it fail.
    // std::cout << "i: " << i << std::endl;
    // std::cout << "curr: " << curr << std::endl;
    // std::cout << "curr data: " << curr->data << std::endl;
    // std::cout << "curr->next: " << curr->next << std::endl;
    curr = curr->next;
  }
  // tail_ -> next = nullptr;
  // if (curr == NULL) {
  //   // curr -> prev = nullptr;
  //   return NULL;
  // }

  if (curr == NULL) {
    return NULL;
  }

  ListNode* temp = curr;
  curr = curr -> next;
  tail_ = temp;
  if (tail_ != nullptr) {
    tail_ -> next = nullptr;
  }
  // curr->prev->next = NULL;
  curr->prev = NULL;

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
    // std::cout << "curr->data: " << curr->data << std::endl;
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
  std::cout << "start reverse: " << startPoint << " " << endPoint << std::endl;
  std::cout << "data: " << startPoint->data << " " << endPoint->data << std::endl;
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

  // ListNode* start = startPoint;
  // ListNode* end = endPoint;
  while (startPoint != endPoint) {
    if (startPoint == nullptr || endPoint == nullptr) {
      break;
    }
    if (startPoint->next == endPoint) {
      Swap(startPoint, endPoint);
      break;
    }
    Swap(startPoint, endPoint);
    startPoint = startPoint -> next;
    endPoint = endPoint -> prev;
  }

  // endPoint = start;
  // startPoint = end;

  // Swap(startPoint, endPoint);
  // // start = start -> next;
  // // end = end -> prev;
  // Swap(startPoint->next, endPoint->prev);
  // ListNode* temp1 = startPoint->next;
  // ListNode* temp2 = endPoint->prev;
  // // Swap(start, end);
  // Swap(temp1->next, temp2->prev);

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

  if (startPoint != nullptr && startPoint->next == endPoint) {
    return;
  }

  // reverse(startPoint->next, endPoint->prev);
  std::cout << "end reverse: " << startPoint << " " << endPoint << std::endl;
  std::cout << "data: " << startPoint->data << " " << endPoint->data << std::endl;
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
  if (n > size()) {
    reverse();
    return;
  }

  ListNode* current = head_;
  for (int count = size(); current != nullptr && count >= n; count -= n) {
    ListNode* temp = current;
    for (int i = 0; i < n; i++) {
      if (current->next != nullptr) {
        current = current->next;
      } else {
        break;
      }
    }
    reverse(temp, current);
  }
  if (current != nullptr) {
    reverse(current, tail_);
  }
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
  ListNode* output = nullptr; //ok compiler, I'll initialize this to nullptr
  ListNode* current_one = first;
  ListNode* current_two = second;
  if (current_one == nullptr && current_two == nullptr) {
    return output;
  }
  if (current_one == nullptr) {
    return current_two;
  } else if (current_two == nullptr) {
    return current_one;
  }
  //no more nullptr cases

  if (current_one != nullptr && current_two != nullptr) {
    if (current_two->data < current_one->data ) {
      output = current_one;
    } else {
      output = current_two;
    }
    current_one = current_one->next;
    current_two = current_two->next;
  }

  ListNode* temp = output;

  while (current_one != nullptr && current_two != nullptr) {
    if (current_two->data < current_one->data) {
      output->next = current_one;
    } else {
      output->next = current_two;
    }
    output = output->next;
    current_one = current_one->next;
    current_two = current_two->next;
  }

  if (current_one != nullptr) {
    while (current_one != nullptr) {
      output->next = current_one;
      output = output->next;
      current_one = current_one->next;
    }
  } else {
    while (current_two != nullptr) {
      output->next = current_two;
      output = output->next;
      current_two = current_two->next;
    }
  }
  return temp;
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
  if (chainLength <= 1 || start == nullptr) {
    return start;
  }
  if (chainLength == 2) {
    if (start->next != nullptr && start->data > start->next->data) {
      Swap(start, start->next);
    }
    return start;
  }

  int num = chainLength/2;

  mergesort(start, num);

  ListNode* current = start;  
  int i = 0;
  for (; current != nullptr && i < num + 1; i++) {
    current = current->next;
  }

  mergesort(current, i); //chainLength - num


  return start;
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
  std::cout << "start Swap" << std::endl;
  std::cout << "points: " << startPoint << " " << endPoint;
  std::cout << " data: ";
  if (startPoint != nullptr) {
    std::cout << startPoint->data << " ";
  } else {
    std::cout << "nan" << " ";
  }
  if (endPoint != nullptr) {
    std::cout << endPoint->data << " ";
  } else {
    std::cout << "nan" << " ";
  }
  std::cout << std::endl;

  std::cout << "before: " << startPoint->prev << " " << endPoint->prev;
  std::cout << " data: ";
  if (startPoint->prev != nullptr) {
    std::cout << startPoint->prev->data << " ";
  } else {
    std::cout << "nan" << " ";
  }
  if (endPoint->prev != nullptr) {
    std::cout << endPoint->prev->data << " ";
  } else {
    std::cout << "nan" << " ";
  }
  std::cout << std::endl;
  
  std::cout << "after: " << startPoint->next << " " << endPoint->next;
  std::cout << " data: ";
  if (startPoint->next != nullptr) {
    std::cout << startPoint->next->data << " ";
  } else {
    std::cout << "nan" << " ";
  }
  if (endPoint->next != nullptr) {
    std::cout << endPoint->next->data << " ";
  } else {
    std::cout << "nan" << " ";
  }
  std::cout << std::endl;

  if (startPoint == endPoint || (startPoint == nullptr && endPoint == nullptr)) {
    return;
  }

  // if (startPoint == nullptr || endPoint == nullptr) {
  //   return;
  // }
  
  if (endPoint == nullptr) {
    endPoint = startPoint;
    endPoint->prev = startPoint->prev;
    endPoint->next = startPoint->next;
    startPoint->prev = nullptr;
    startPoint->next = nullptr;
    startPoint = nullptr;
    return;
  }

  if (startPoint == nullptr) {
    startPoint = endPoint;
    startPoint->prev = endPoint->prev;
    startPoint->next = endPoint->next;
    endPoint->prev = nullptr;
    endPoint->next = nullptr;
    endPoint = nullptr;
    return;
  }

    ListNode* prev_both = startPoint->prev;
    ListNode* next_both = endPoint->next;

    ListNode* temp = startPoint;
    ListNode* temp2 = endPoint;

    ListNode* temp_next = startPoint->next;
    ListNode* temp2_prev = endPoint->prev;
    
    if (prev_both != nullptr) {
      prev_both->next = temp2;
    } else {
      head_ = temp2;
    }
    temp2->prev = prev_both;

    temp->next = next_both;
    if (next_both != nullptr) {
      next_both->prev = temp;
    } else {
      tail_ = temp;
    }

    //change this part

    if (startPoint -> next == endPoint) {
      temp2->next = temp;
      temp->prev = temp2;
    } else {
      // ListNode* temp_next = temp->next;
      // ListNode* temp2_prev = temp2->prev;

      temp2->next = temp_next;
      temp->prev = temp2_prev;
    }

    startPoint = temp2;
    endPoint = temp;


  // if (startPoint -> next == endPoint) {
  //   ListNode* prev_both = startPoint->prev;
  //   ListNode* next_both = endPoint->next;

  //   ListNode* temp = startPoint;
  //   ListNode* temp2 = endPoint;
    
  //   prev_both->next = temp2;
  //   temp2->prev = prev_both;

  //   temp->next = next_both;
  //   next_both->prev = temp;

  //   temp2->next = temp;
  //   temp->prev = temp2;

  //   startPoint = temp2;
  //   endPoint = temp;

  //   return;
  // }



  //old code

  
  // ListNode* temp_prev = startPoint->prev;
  // ListNode* temp_next = startPoint->next;

  // ListNode* temp_prev2 = endPoint->prev;
  // ListNode* temp_next2 = endPoint->next;

  // ListNode* start_before = nullptr;
  // ListNode* start_after = nullptr;
  // ListNode* end_before = nullptr;
  // ListNode* end_after = nullptr;
  // if (temp_prev != nullptr) {
  //   start_before = temp_prev->prev;      //before   //prev     // startPoint    //next    //after
  // }
  // if (temp_next != nullptr) {
  //   start_after = temp_next->next;
  // }

  // if (temp_prev2 != nullptr) {
  //   end_before = temp_prev2->prev;      //before   //prev     // endPoint    //next    //after
  // }
  // if (temp_next2 != nullptr) {
  //   end_after = temp_next2->next;
  // }

  // startPoint->prev = endPoint->prev;
  // startPoint->next = endPoint->next;

  // endPoint->prev = temp_prev;
  // endPoint->next = temp_next;

  //update the collatoral damage

  // if (start_before != nullptr) {
  //   start_before->next = temp_prev->prev;      //before   //prev     // startPoint    //next    //after
  // }
  // if (temp_next != nullptr) {
  //   start_after = temp_next->next;
  // }

  // if (temp_prev2 != nullptr) {
  //   end_before = temp_prev2->prev;      //before   //prev     // endPoint    //next    //after
  // }
  // if (temp_next2 != nullptr) {
  //   end_after = temp_next2->next;
  // }

  
  // ListNode* temp = startPoint;
  // startPoint = endPoint;
  // endPoint = temp;

  // ListNode* temp_prev = startPoint->prev;
  // startPoint->prev = endPoint->prev;
  // endPoint->prev = temp_prev;

  // std::cout << "startPoint: " << startPoint << std::endl;
  // std::cout << "endPoint: " << endPoint << std::endl;
  // std::cout << "startPoint->next: " << startPoint->next << std::endl;
  // std::cout << "endPoint->next: " << endPoint->next << std::endl;

  // ListNode* temp_next = startPoint->next;
  // startPoint->next = nullptr;
  // endPoint->next = nullptr;


  //startPoint and endPoint are now their opposite names


  // if (temp_prev != nullptr) {
  //   temp_prev -> next = startPoint;
  // }
  // if (temp_next != nullptr) {
  //   temp_next -> prev = startPoint;
  // }

  // if (temp_prev2 != nullptr) {
  //   temp_prev2 -> next = endPoint;
  // }
  // if (temp_next2 != nullptr) {
  //   temp_next2 -> prev = endPoint;
  // }


  std::cout  << "points: " << startPoint << " " << endPoint;
  std::cout  << " data: ";
  if (startPoint != nullptr) {
    std::cout  << startPoint->data << " ";
  } else {
    std::cout  << "nan" << " ";
  }
  if (endPoint != nullptr) {
    std::cout  << endPoint->data << " ";
  } else {
    std::cout  << "nan" << " ";
  }
  std::cout  << std::endl;

  std::cout  << "before: " << startPoint->prev << " " << endPoint->prev;
  std::cout  << " data: ";
  if (startPoint->prev != nullptr) {
    std::cout  << startPoint->prev->data << " ";
  } else {
    std::cout  << "nan" << " ";
  }
  if (endPoint->prev != nullptr) {
    std::cout  << endPoint->prev->data << " ";
  } else {
    std::cout  << "nan" << " ";
  }
  std::cout  << std::endl;
  
  std::cout  << "after: " << startPoint->next << " " << endPoint->next;
  std::cout  << " data: ";
  if (startPoint->next != nullptr) {
    std::cout  << startPoint->next->data << " ";
  } else {
    std::cout  << "nan" << " ";
  }
  if (endPoint->next != nullptr) {
    std::cout  << endPoint->next->data << " ";
  } else {
    std::cout  << "nan" << " ";
  }
  std::cout  << std::endl;


  // startPoint->prev = nullptr;
  // startPoint->prev = endPoint;
  // endPoint->next = startPoint;
  // startPoint->next = temp_next;
  // endPoint->next = nullptr;
  // std::cout << "< ";
  // for (ListNode* current = startPoint; current != nullptr; current = current->next) {
  //   std::cout << current->data << " ";
  // }
  // std::cout << ">" << std::endl;

  // std::cout << "< ";
  // for (ListNode* current = endPoint; current != nullptr; current = current->prev) {
  //   std::cout << current->data << " ";
  // }
  // std::cout << ">" << std::endl;

  // std::cout << temp_next->data << std::endl;
  ListNode* curr = startPoint; // temp_next
  if (curr == head_) {
          // std::cout  << "head_: ";
        }
        if (curr == tail_) {
            // std::cout  << "tail_: ";
        }

        if (curr == NULL) {
            // std::cout  << "NULL ";
        } else {
            // std::cout  << "curr_->prev: " << curr->prev << " curr: " << curr << " curr->data: " << curr->data << " curr->next: " << curr->next;
        }
        // std::cout  << "\n";

  // std::cout << temp_prev->data << std::endl;
  curr = endPoint; // temp_prev2
  if (curr == head_) {
          // std::cout  << "head_: ";
        }
        if (curr == tail_) {
            // std::cout  << "tail_: ";
        }

        if (curr == NULL) {
            // std::cout  << "NULL ";
        } else {
            // std::cout  << "curr_->prev: " << curr->prev << " curr: " << curr << " curr->data: " << curr->data << " curr->next: " << curr->next;
        }
        // std::cout  << "\n";

  std::cout  << "exit Swap" << std::endl;
}
