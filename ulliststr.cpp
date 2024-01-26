#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#define ARRSIZE 10

using namespace std;
#include <iostream> 

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();

}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::push_back(const std::string& val) {
  // if empty
  // cout << "pushing back val " << val << endl;
  if (size_==0) {
    //new item
    //put val into item->val[0]
    head_ = new Item;
    head_->val[0] = val;
    //set first, last indices
    head_->first = 0;
    head_->last = 1;
    tail_ = head_; // tail is head
  }
  else {
    // cout << "size_ is " << size_ << endl;
    // check if there's space in the tail item
    if (tail_->last==ARRSIZE) { // full
      // cout << "arr is full; creating new item ..." << endl;
      Item* temp = new Item;
      // create temp node with word at index 0      
      //temp->val = new std::string[ARRSIZE];
      temp->val[0] = val;
      temp->last = 1;
      // have tail_ next point to temp
      tail_->next = temp;
      // connect temp to tail
      temp->prev = tail_;
      // set tail_ to temp
      tail_ = temp;
    }
    else {
      // cout << "arr not full. adding to tail item ..." << endl;
      tail_->val[tail_->last] = val;
      tail_->last = tail_->last+1;
    }
  }
  // increase size
  size_++;
}


/**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
void ULListStr::push_front(const std::string& val) {
  //check if empty
  // cout << "pushing front " << val << endl;
  if (head_==nullptr) {
    // cout << "size is 0. creating new item ..." << endl;
    // create new item
    head_ = new Item;
    // put it at the back of the array
    head_->val[ARRSIZE-1] = val;
    //set first, last indices and tail
    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;
    tail_= head_;
  }
  else { // there's an item
    // cout << "ullist not empty. " << endl;
    // check if head has space
    if (head_->first==0) { // full
      // cout << "arr is full. creating new item ..." << endl;
      // make a new item
      Item* temp = new Item;
      //temp->val = new std::string[ARRSIZE];
      // cout << "putting "<< val << " in position " << ARRSIZE-1 << " of new head_->val arr..." << endl;
      temp->val[ARRSIZE-1] = val;
      temp->first = ARRSIZE-1;
      temp->last = ARRSIZE;
      temp->next = head_;
      head_->prev = temp;
      head_ = temp;
    }
    else { // put at front of array
      // cout << "there's space in head_. putting " << val << " in position " << head_->first-1 << " in head_->val arr..." << endl;
      head_->val[head_->first-1] = val;
      head_->first = head_->first-1; //set new first
    }
  }
  size_++;
}

/**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_back() {
  if (tail_==nullptr)
    return;
  //decrement last
  //delete the string?
  tail_->last = tail_->last-1;
  //if it was the only thing in the item, delete the item
  if (tail_->last==tail_->first) {
    //check if that was head too
    //checked; ok
    if (tail_==head_) { //if yes then set both tail and head to null
      // delete [] tail_->val; // delete array
      delete tail_; // delete item
      head_ = nullptr;
      tail_ = nullptr;
    }
    //if not, ie tail->prev exists
    else { 
      Item* temp = tail_->prev; // this will be the new tail
      // delete [] tail_->val; // delete array
      delete tail_; // delete item
      tail_ = temp; //set tail pointer to tail prev
      tail_->next = nullptr;
    }
  }
  //decrement size 
  size_--;
}

/**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_front() {
  // if ullist empty
  if ((size_==0) || (tail_==nullptr) || (head_==nullptr))
    return;
  // delete thing at head_->first
  //delete head_->val[head_->first]; // deletes string
  //increment first
  head_->first = head_->first+1;
  //if it was the only thing in the item, delete the item
  if (head_->first==head_->last) {
    //check if that was tail too
    if (tail_==head_) { //if yes then set both tail and head to null
      // delete [] head_->val; // delete array
      delete head_; // delete item
      head_ = nullptr;
      tail_ = nullptr;
    }
    //if not, ie head->next exists
    else {
      Item* temp = head_->next; // this will be the new head
      // delete [] head_->val; // delete array
      delete head_; // delete item
      head_ = temp; //set head pointer to head prev
      head_->prev = nullptr;
    }
  }
  //decrement size 
  size_--;
}

/**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::back() const {
  return this->tail_->val[tail_->last-1];
}

/**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::front() const {
  return this->head_->val[head_->first];
}

  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
std::string* ULListStr::getValAtLoc(size_t loc) const {
  // cout << "called getValAtLoc " << loc << endl;
  if (loc > size_) { // not valid loc
    // cout << "INVALID: loc > size" << endl;
    return NULL;
  }
  // check if it's in head
  if (loc<(head_->last)-(head_->first)) {
    // cout << "loc is in head item" << endl;
    return &head_->val[head_->first+loc];
  }
  //if not
  // subtract head_'s size, see how much further to go (how many Items down)
  // cout << "head_->last: " << head_->last << endl;
  // cout << "head_->first: " << head_->first << endl;
  // cout << "last-first = " << (head_->last)-(head_->first) << endl;
  int itemnum = int(loc-((head_->last)-(head_->first)))/10;
  // cout << "loc is in " << itemnum << "th item" << endl;
  Item* curr = head_->next;
  for (int i=0; i<itemnum; i++) {
    curr = curr->next; // hop to the itemnum-th item
  }
  // cout << "int(loc-1-((head_->last)-(head_->first)))/10: " << int(loc-1-((head_->last)-(head_->first)))/10 << endl;
  // cout << "curr->val[int(loc-1-((head_->last)-(head_->first)))/10]: " << curr->val[int(loc-1-((head_->last)-(head_->first)))/10];
  return &(curr->val[(loc-((head_->last)-(head_->first)))%10]);
}