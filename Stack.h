/*
Author: Negedu Paul
EECS - Lab 4
last modified: 04/04/2019
*/
#ifndef STACK_H
#define STACK_H
#include "StackInterface.h"
#include "Node.h"
#include <stdexcept>
#include <string>
using namespace std;

template <typename T>
class Stack : public StackInterface<T>
{
  private:
    Node<T>* m_top;
  public:
    Stack();
    
    Stack(const Stack& orig);
	
    Node* recursiveCopy(Node* temp, Stack& copy);
	
    /** Virtual destructor allows concrete implementations to clean up
    heap memory when the Stack is discarded. */
    ~Stack();

    /** Sees whether this stack is empty.
    @return True if the stack is empty, or false if not. */
    bool isEmpty() const;

    /** Adds a new entry to the top of this stack.
    @post If the operation was successful, newEntry is at the top of the stack.
    @param newEntry The object to be added as a new entry.
    @throw PrecondViolatedExcep if no memory available for the new item */
    void push(const T &newEntry);

    /** Removes the top of this stack.
	  @pre The stack is not empty.
    @post If the operation was successful, the top of the stack has been removed.
    @throw PrecondViolatedExcep if the stack is empty when called */
    void pop();

    /** Returns the top of this stack.
    @pre The stack is not empty.
    @post The top of the stack has been returned, and the stack is unchanged.
    @return The top of the stack.
    @throw PrecondViolatedExcep if the stack is empty when called */
    T peek() const;
};
#include "Stack.hpp"
#endif
