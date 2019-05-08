/*
Author: Negedu Paul
EECS - Lab4
last modified: 04/04/2019
*/
#include"Stack.h"
using namespace std;

template <typename T>
Stack<T>::Stack() //constructor
{
    m_top=nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
  while (!isEmpty())
  {
    pop();
  }
  m_top=nullptr;
  
}

template <typename T>
bool Stack<T>::isEmpty() const
{        return (m_top == nullptr);    }

template <typename T>
void Stack<T>::push(const T &newEntry) 
{
    Node<T>* brandNew = new Node<T>(newEntry);
    if (brandNew==nullptr)
    {
      throw(PrecondViolatedExcep("Ran out of memory! Can't push onto stack"));
    }
    brandNew->setNext(m_top);
    m_top=brandNew;
    brandNew=nullptr;
}

template <typename T>
void Stack<T>::pop() 
{
if (isEmpty())
{   throw(PrecondViolatedExcep("Nothing to pop")    );}
else
{
    Node<T>* temp = m_top;
    m_top=m_top->getNext();
    delete temp;
    temp=nullptr;
}
}

template <typename T>
T Stack<T>::peek() const 
{
  if (isEmpty())
  {
    throw(PrecondViolatedExcep("Nothing to peek at"));
  }
  else
  {
    return (m_top->getEntry());
  }
  
}
