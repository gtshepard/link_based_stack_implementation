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
#include <iostream>
#include "LinkedStack.h"
#define ERR_MSG std::cerr << "ERORR ->>> File:" << __FILE__ << ", Line--" << __LINE__ << ", "<< __TIMESTAMP__<< std::endl;
//@desc increase readability on out put of terminal 
//      by displaying a line segment when called.
//@post line sent to standard output (terminal)
void Format(){
  std::cout << "-----------------------------------" << std::endl;
}
//@desc     checks the equality of two stacks
//@pre      only call if stacks are not needed from here on. 
//          stacks will be destoryed upon completetion of method
//@param    LinkedStack<T> stack_one,  LinkedStack<T> stack_two 
//          two stacks that will be compared for equality 
//@return   true if equal, else false
//@post     stacks erased upon completetion of method.
template<class T>
bool IsEqual(LinkedStack<T>& stack_one, LinkedStack<T>& stack_two){ 

  bool error_flag = false; //equality error
  if(stack_one.get_size() == 0 && stack_one.get_size() == 0) //both stacks are empty
    return true;
    
  if(stack_one.get_size() == 0 || stack_one.get_size() == 0) // avoids a call to peek on an emtpy stack() 
    return false;                                            //see LinkedStack.h Peek() precondition
                                         
  while(stack_one.IsEmpty()&&(stack_one.get_size() != stack_two.get_size())){

    if(stack_one.Peek() == stack_two.Peek()){ //Compare each data entry
      stack_one.Pop();  //adjust for next comparison 
      stack_two.Pop();  //adjust for next comparison 
    } else {
      error_flag = true; //entries are not the same 
      break;//leave loop
    }
  }//end while
   
   stack_one.Erase(); //destory stack 
   stack_two.Erase(); //destory stack
   return error_flag;
}//end IsEqual
void TestStack(){

  Format(); //format terminal for test result readability 
  std::cout << "Linked Stack Test" << std::endl;
  Format(); //format terminal for test result readability 
  
  LinkedStack<int> stack_a; //test default constructor 
  stack_a.Push(1);  //test Push() method
  stack_a.Push(5);  //test Push() method
  stack_a.Push(99); //test Push() method
  stack_a.Push(3);  //test Push() method
  
  if(stack_a.get_size() != 4){
    ERR_MSG;  //display error message
    std::cerr << "Push() Test Failed" << std::endl; //display result to standard output (Terminal)
  } else {
    std::cout << "Push() Test Successful" << std::endl; //display result to standard output (Terminal)
  }
  Format(); //format terminal for test result readability 
  
  
  if(stack_a.IsEmpty() != false){ //test IsEmpty() 
    ERR_MSG; //display error message
    std::cerr << "IsEmpty() Test Failed" << std::endl; //display result to standard output (Terminal)
  } else {
    std::cout << "IsEmpty() Test Successful" << std::endl; //display result to standard output (Terminal)
  } 
  Format(); //format terminal for test result readability 
 
  while(!stack_a.IsEmpty()){stack_a.Pop();} //test Pop() method
  
  if(stack_a.get_size()!=0){
    ERR_MSG; //display error message
    std::cerr << "Pop() Test Failed" << std::endl; //display result to standard output (Terminal)
  } else {
    std::cout << "Pop() Test Successful" << std::endl; //display result to standard output (Terminal)
  } 
  Format(); //format terminal for test result readability 
  
  stack_a.Push(1);  //fill stack
  stack_a.Push(5);  //fill stack
  stack_a.Push(99); //fill stack
  stack_a.Push(3);  //fill stack

  LinkedStack<int> stack_b(stack_a);  //test copy constructor
  if(IsEqual(stack_a, stack_b)){ 
   ERR_MSG; //display error message
   std::cerr << "Copy Constructor Test Failed" << std::endl; //display result to standard output (Terminal)
  }else{
   std::cout << "Copy Constructor Test Successful"<< std::endl; //display result to standard output (Terminal)
  }
  Format(); //format terminal for test result readability 
  stack_b.Push(36);  //fill stack
  stack_a.Push(2);  //fill stack
  stack_a.Push(87); //fill stack
  stack_a.Push(456);  //fill stack
  
  LinkedStack<int> stack_c = stack_b; //test assignment operator
  
  if(IsEqual(stack_b, stack_c)){
    ERR_MSG;  //display error message
    std::cerr << "Assigment Operator Test Failed" << std::endl; //display result to standard output (Terminal)
  }else{
    std::cout << "Assignment Operator Test Successful"<< std::endl; //display result to standard output (Terminal)
  }
  Format(); //format terminal for test result readability 
}//end TestStack
int main(){
  TestStack();//test stack operations
  return 0;
}//end main
