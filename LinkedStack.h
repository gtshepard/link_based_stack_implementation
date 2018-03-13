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
//  Modifications : On March 12th improved tester file, by adding additional macros. 
//                  minor bug fix to tester file. 
//-----------------------------------------------------------------
#ifndef LINKED_STACK_H_
#define LINKED_STACK_H_
template<class T>
class LinkedStack {
  public:
    //@desc default constructor intializes 
    //      default values for private members
    //@post stack has initial values, rids class of
    //      garbage values 
    LinkedStack();
    
    //@desc copy constructor, copies stack placed 
    //      into constructor to 'this' stack
    //@pre  do noy copy empty stack, undefined behavior
    //@post stack contians same data as argument
    //      passed into constructor 
    LinkedStack(const LinkedStack<T>& stack);
    
    //@desc   overloads assingment operator to handle 
    //         link based stacks
    //        copies stack taken in as a parameter, 
    //        that this then copied to 'this' Object 
    //@pre    copies a stack rhs to 'this' stack,  where rhs, 
    //        is not empty
    //@param  const LinkedStack<T>& stack, a stack to copy
    //@return LinkedStack<T>& returns a reference to stacl, 
    //        in particular 'this' stack with the new copied data 
    //@post   stack has complete copy of data from parameter 
    LinkedStack<T>& operator=(const LinkedStack<T>& rhs);
   
    //@desc desctructor for class. destroys no longer needed memory
    //@post automatically called by class. destroys data with in
    //      the instance of the clas upon completion of a call
    ~LinkedStack();

    //---------------------------
    // non-mutable public methods
    //---------------------------

    //@desc     checks to see if stack has contents 
    //@mutuable non-mutable, method cannot mutate the stack
    //@return   false no contents, else true
    bool IsEmpty() const;
  
    //@desc     provides the top data entry of the stack to the user
    //@pre      stack must have a data entry (not empty) for method to return data, 
    //          otherwise a call to this method is extraneous(useless)
    //          Further when calling Peek() be sure stack is not empty.
    //          calling Peek() on an empty stack and immediately storing
    //          the value in a variable will produce undefined behavior.
    //@mutuable method is non-mutuable, cannot mutate the stack
    //@return   T data, data entry at top of stack, if no entry 
    //          method terminates safely program continues to run."
    T Peek() const;
  
    //@desc getter method for size_
    //@mutable method is non-mutable, cannot mutate stack
    //@return size_t, number for data entries in stack
    int get_size() const;
  
    //---------------------------
    // mutable public methods
    //---------------------------

    //@desc     stores a data entry on top of the stack 
    //@param    const T& data, data of generic type to be put into the stack
    //@mutable  method is mutable, can mutate the stack
    //@post     stack now contains an additional data entry, size of stack increased.
    void Push(const T& data);

    //@desc     removes a data entry from the top of the stack
    //@pre      stack must have a data entry (not empty) to 
    //          remove a data entry. otherwise a call to this 
    //          method is extraneous (useless).
    //@mutable  method is mutable, can mutate the stack
    //@post     stack now contains one less additional data entry, 
    //          size of stack decreased. if no data entry exists 
    //          upon call method terminates safely.
    //          program continues to run.
    void Pop();
    
    //@desc     removes all data entries from stack
    //@pre      stack must have data entries (no empty) for data to removed, 
    //          otherwise a call to this method is extraneous (useless).
    //@mutable  method is mutable, can mutate stack
    //@post     stack contains no   stack must have data entries (no empty) for data to removed, 
    //          otherwise a call to this method is extraneous (useless).data entries, if no data entries exist
    //          upon call to method, the method terminates safely and 
    //          and program continues to run
    void Erase();
  private:
    struct Node {
      Node():next(nullptr){};
      Node(const T& d):data(d){}
      Node(const T& d, Node* n):data(d),next(n){}
    
      T data;//data entry 
      Node* next;//null if end of list
    };//end Node
  
    LinkedStack::Node* top_;  //node at top of stack 
    int size_; //number of data entries in stack
    
    //---------------------------
    // mutable private methods
    //---------------------------

    //@desc     copies stack provided as argument into 'this' stack
    //@pre      'this' stack MUST be empty before calling copy. Otherwise will 
    //          violate integrity of stack, will not be not be copy of an argument 
    //          stack recommend use, call Erase() prior to calling Copy().
    //@param    const LinkedStack<T>& rhs, a stack to copy passed 
    //          in by constant reference.
    //@mutable method is mutable, can mutate stack
    //@post     upon successful completion stack is a complete replica of 
    //          stack passed in as argument. if called on non-empty stack, 
    //          function will fail to yield a proper replica.
    void Copy(const LinkedStack<T>& rhs);
};  
#include "LinkedStack.cpp"
#endif
