//------------------------------------------------------------------
//  Title :         test_linked_stack.cpp
//  Author :        Garrison Shepard
//  Created :       March 8th, 2018
//
//  Description :   This is an implementation of a Linked Stack data structure
//                  Tests are run against operations to verify correctness.
//
//  Purpose :       To provide a linked based stack implementation for general use 
//                  and study. Of Interest to those preparing for software engineering 
//                  interviews and studying Computer Science. Originally created for CS community 
//                  on college campus for interview preperation, now open for public use.
//
//  Usage :         ./test_linked_stack_implementation
//
//  Build with :    Make all (use make file included )
//
//  Modifications : no modifications since creation date.
//-----------------------------------------------------------------
#include "LinkedStack.h"
template<class T>
LinkedStack<T>::LinkedStack():top_(nullptr), size_(0){} //end default constructor

template<class T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& stack){
  top_= nullptr;//initialize stack 
  size_ = 0;//initialize stack 
  Erase();
  Copy(stack);//copy contents of arguement stack into 'this' stack
}//end Copy Constructor 

template<class T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& rhs){
  //assign contents of rhs stack to 'this' stack
  if(this != &rhs){ 

    Erase();  //clear contents of 'this' stack
    Copy(rhs);  //copy contents of rhs stack to 'this'
    top_ = rhs.top_; //adjust top to correct node
  }
  return *this;
}// end operator=

template<class T>
LinkedStack<T>::~LinkedStack(){
  Erase(); //clears contents of stack 
}//end destructor

//---------------------------
// non-mutable public methods
//---------------------------

template<class T>
bool LinkedStack<T>::IsEmpty() const {
  if(size_ != 0)//stack has no contents
    return false;
    
  return true;
}//end IsEmpty

template<class T>
T LinkedStack<T>::Peek() const {
  return top_->data; //value of next node in stack
}//end Peek

template<class T>
size_t LinkedStack<T>::get_size() const{return size_;}//end get_size

//---------------------------
// mutable public methods
//---------------------------  

template<class T>
void LinkedStack<T>::Push(const T& data){
    Node* append = new Node(data, top_);  //append to front
    top_ = append;  //new node at top (LIFO)
    size_++;  //Adjust size
}//end Push 

template<class T>
void LinkedStack<T>::Pop(){
  if(IsEmpty())
    return;

  Node* pop_node = top_;  //grab node to delete
  top_= top_->next; //front most node at top(LIFO)
  delete pop_node;  //delete data (release memory)
  size_--;  //adjust size
}//end Pop

template<class T>
void LinkedStack<T>::Erase(){
    while(!IsEmpty()) //stack has data 
     Pop(); //remove an entry from the stack
}//End Erase

//---------------------------
// mutable private methods
//---------------------------

template<class T>
void LinkedStack<T>::Copy(const LinkedStack<T>& stack){
    //no contents
    if(stack.IsEmpty())
      return;
      
    //neccesary initialization
    Node* traverse = stack.top_;
    Node* append, *end = nullptr;
    
    //copy each item from arguement stack into 'this' stack
    //maintains LIFO structure
    while(traverse != nullptr){
      append = new Node(traverse->data);  //create node, fill with data 
      size_++;// adust size 
     
      if(end == nullptr) //if first node
         top_ = append; //attach first node
      else  
        end->next=append; //attach all other nodes
     
      end = append;  //end points to latest node
      traverse = traverse->next; //Traverse list to copy
    }//end while
}//end Copy
