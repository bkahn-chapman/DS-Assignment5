#include <iostream>

using namespace std;

template <class T>
class ListNode
{
  public:
    T data;
    ListNode<T> *next;
    ListNode<T> *prev;

    ListNode(); //default
    ListNode(T data); //overload
    ~ListNode(); //destructor
};

template <class T>
ListNode<T>::ListNode()
{
  data = 0;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T dataInput)
{
  data = dataInput;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode()
{
  if(next != NULL)
  {
    next = NULL;
    prev = NULL;
    delete next;
    delete prev;
  }
}
