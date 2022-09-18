
class ListIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
  private:
    // @TODO: graded in MP3.1
    ListNode* position_;

  public:
    ListIterator() : position_(NULL) { }
    ListIterator(ListNode* x) : position_(x) { }


    // Pre-Increment, ++iter
    ListIterator& operator++() {
        // @TODO: graded in MP3.1
        position_ = position_ -> next;
        return *this;
    }
    
    // Post-Increment, iter++
    ListIterator operator++(int count) {
        // @TODO: graded in MP3.1
        ListNode* temp = position_;
        //could do this recursively instead, if that is okay
        //or if this is not okay, based on preferences
        for (int i = 0; i < count; i++) {
            temp = temp -> next;
        }
        position_ = temp;
        return ListIterator(position_);
    }

    // Pre-Decrement, --iter
    ListIterator& operator--() {
        // @TODO: graded in MP3.1
        position_ = position_ -> prev;
        return *this;
    }

    // Post-Decrement, iter--
    ListIterator operator--(int count) {
        // @TODO: graded in MP3.1
        //copied from operator++(int count), made one change (next -> prev)
        ListNode* temp = position_;
        //could do this recursively instead, if that is okay
        //or if this is not okay, based on preferences
        for (int i = 0; i < count; i++) {
            temp = temp -> prev; //changed next to prev here
        }
        position_ = temp;
        return ListIterator(position_);
        return ListIterator();
    }

    bool operator!=(const ListIterator& rhs) {
        // @TODO: graded in MP3.1
        return !(*this == rhs); //took the idea from prev version of operator==, added the *
    }

    bool operator==(const ListIterator& rhs) {
        return (this->position_ == rhs.position_);
    }

    const T& operator*() {
        return position_->data;
    }

    const T* operator->() {
        return &(position_->data);
    }
};
