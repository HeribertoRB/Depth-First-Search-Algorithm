//INSTRUCTION
//Look for **. (do control-S)
//Update the comments using the HOW TO COMMENT file, 
//  complete exception handling and 
//  finish ClearIt to make this complete - Yoshii (CS311)
// When done, compile stack.cpp to make sure there are no syntax errors.
  
//=========================================================
//HW#: HW1P1 stack
//Your name: Heriberto Bernal
//Complier:  g compiler
//File type: stack implementation file
//=========================================================

using namespace std;  
#include <iostream>
#include "stack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{ top = -1;  } // indicate an empty stack 
  
//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
{} // nothing to do 
  
//PURPOSE:  checks top and returns true if empty, false otherwise.
// In the comment, make sure you define "empty" in terms of top.
//If the top is equal to -1 then the stack is empty
bool stack::isEmpty()
{ if (top == -1) return true; else return false; }
    
//PURPOSE: checks top and returns true if full, false otherwise.
// In the comment, make sure you define "full" in terms of top.
//If the top is equal to MAX(max. capacity of the stack) then the stack is full
bool stack::isFull()
  { if (top == MAX-1 ) return true; else return false; }
  
//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
 void stack::push(el_t elem)
{ if (isFull()) throw Overflow{}; 
   else { top++; el[top] = elem; }
}
 
 //PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
 //  Otherwise, removes an element from el and gives it back.
 //PARAMETER: provide a holder (elem) for the element popped (pass by ref)
 void stack::pop(el_t& elem)
{ if (isEmpty()) throw Underflow{}; 
  else { //int(elem) - 48;
     elem = el[top]; top--;}
}
 
// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
 void stack::topElem(el_t& elem)
{ if (isEmpty()) {throw Underflow{}; }
   else { elem = el[top]; } 
}
 
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
 void stack::displayAll()
 {  if (isEmpty()) cout << "[ empty ]" << endl;
   else for (int i=top; i>=0; i--)
     { cout << el[i] << endl; }
   cout << "--------------" << endl;
 }
 
 
//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
 void stack::clearIt()
{ if(isEmpty()) {throw Underflow{}; }
  else{
    el_t eleme; //pop element will go in this variable
    for(int i=top; i>=0; i--) //this for loop will pop all elements in the stack
      {pop(eleme);} 
      }
 }
 

