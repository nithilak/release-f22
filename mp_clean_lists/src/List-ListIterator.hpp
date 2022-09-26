
class ListIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
  private:
    // @TODO: graded in MP3.1
    ListNode* position_;
    ListNode* head_;
    ListNode* tail_;
    bool atEnd = false;

  public:
    ListIterator() : position_(NULL), head_(NULL), tail_(NULL), atEnd(false) { }
    ListIterator(ListNode* x) : position_(x), head_(x), tail_(x), atEnd(false) {
        while (head_ != nullptr && head_->prev != nullptr) {
            head_ = head_->prev;
        }
        while (tail_ != nullptr && tail_->next!= nullptr) {
            tail_ = tail_->next;
        }
    }
    ListIterator(ListNode* head, ListNode* tail) : position_(NULL), head_(head), tail_(tail), atEnd(true) {
    }
    ListIterator(const List& list) : position_(list.head_), head_(list.head_), tail_(list.tail_), atEnd(false) { }


    // Pre-Increment, ++iter
    ListIterator& operator++() {
        // @TODO: graded in MP3.1
        // // // // // // // //std::cout << "enter operator++" << std::endl;
        if (position_ == tail_) {
            atEnd = true;
        } else {
            atEnd = false;
        }
        if (position_ != nullptr) {
            position_ = position_ -> next;
        }
        return *this;
    }
    
    // Post-Increment, iter++
    ListIterator operator++(int count) {
        //std::cout << "operator++ post" << std::endl;
        // @TODO: graded in MP3.1
        if (position_ == tail_) {
            atEnd = true;
        } else {
            atEnd = false;
        }
        ListNode* temp = position_;
        //could do this recursively instead, if that is okay
        //or if this is not okay, based on preferences
        
        // if (position_ != nullptr) {
            for (int i = 0; i == 0 || i < count; i++) {
                //std::cout << "i: " << i << std::endl;
                if (position_ == nullptr) {
                    //std::cout << "returning: " << position_ << std::endl;
                    return ListIterator(NULL);
                }
                if (position_->next == nullptr) {
                    position_ = position_ -> next;
                    //std::cout << "returning: " << position_ << std::endl;
                    return ListIterator(temp);
                }
                //std::cout << "position_: " << position_->data << std::endl;
                position_ = position_ -> next;
                //std::cout << "next position_: " << position_->data << std::endl;
            }
            // position_ = temp;
            //std::cout << "now next position_: " << position_->data << std::endl;
        // }
        //std::cout << "temp position_: " << temp->data << std::endl;
        return ListIterator(temp);
    }

    // Pre-Decrement, --iter
    ListIterator& operator--() {
        // std::cout << "operator-- (pre-decrement)" << std::endl;
        // @TODO: graded in MP3.1
        // // // // // // // //std::cout << "enter operator--" << std::endl;
        if (atEnd) {
            // std::cout << "position_ == atEnd" << std::endl;
            atEnd = false;
            position_ = tail_;
            return *this;
        } else if (position_ != nullptr) {
            position_ = position_ -> prev;
        }
        return *this;
    }

    // Post-Decrement, iter--
    ListIterator operator--(int count) {
        // @TODO: graded in MP3.1
        // //copied from operator++(int count), made one change (next -> prev)
        // ListNode* temp = position_;
        // //could do this recursively instead, if that is okay
        // //or if this is not okay, based on preferences
        // // if (position_ != nullptr) {
        //     for (int i = 0; i == 0 || (i < count); i++) {
        //         if (position_ == NULL) {
        //             return ListIterator(NULL);
        //         }
        //         position_ = position_ -> prev; //changed next to prev here
        //     }
        //     // position_ = temp;
        // // }
        // return ListIterator(temp);
        // // return ListIterator();
        
        //copied from operator++ post
        //std::cout << "operator-- post" << std::endl;
        // @TODO: graded in MP3.1
        ListNode* temp = position_;
        //could do this recursively instead, if that is okay
        //or if this is not okay, based on preferences

        // std::cout << "operator-- (post-decrement)" << std::endl;
        // @TODO: graded in MP3.1
        // // // // // // // //std::cout << "enter operator--" << std::endl;
        //copied from the new operator-- pre increment
        if (atEnd) {
            // std::cout << "position_ == atEnd" << std::endl;
            atEnd = false;
            position_ = tail_;
            return temp;
        }
        
        // if (position_ != nullptr) {
            for (int i = 0; i == 0 || i < count; i++) {
                //std::cout << "i: " << i << std::endl;
                if (position_ == nullptr) {
                    return ListIterator(temp);
                }
                if (position_->prev == nullptr) {
                    position_ = position_ -> prev;
                    //std::cout << "returning: " << position_ << std::endl;
                    return ListIterator(temp);
                }
                //std::cout << "current position_: " << position_->data << std::endl;
                position_ = position_ -> prev;
                //std::cout << "prev position_: " << position_->data << std::endl;
            }
            // position_ = temp;
            //std::cout << "now prev position_: " << position_->data << std::endl;
        // }
        //std::cout << "temp position_: " << temp->data << std::endl;
        return ListIterator(temp);
    }

    bool operator!=(const ListIterator& rhs) {
        // @TODO: graded in MP3.1
        return !(*this == rhs); //took the idea from prev version of operator==, added the *
    }

    bool operator==(const ListIterator& rhs) {
        return (this->position_ == rhs.position_);
    }

    const T& operator*() const {
        return position_->data;
    }

    const T* operator->() const {
        return &(position_->data);
    }
};