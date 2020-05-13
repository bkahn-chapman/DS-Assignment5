#include <iostream>
#include <string>
#include "ListNode.h"

using namespace std;

template <class T>
class DoublyLinkedList

{
  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertFront(T data); //adds data to front of list, dont need for this assignment, can remove
    void insertBack(T data); //adds data to the end of the list
    T removeFront(); //removes front value
    T removeBack(); //dont need for this assignment, can remove
    int search(T val); //can return value or position of node depending on implementation
    void removeAtPos(int pos); //removes value at given position, not necessary for assignment
    //could implement an insert at position, similar to removeAtPos, also not necessary

    unsigned int getSize(); //gets the size of the list
    T getFront(); //gets the front of the list
    bool isEmpty(); //checks if the list is empty
    void printList(); //prints the list

    ListNode<T> *front; //front of the list
    unsigned int size; //size of the list
    ListNode<T> *back; //back of the list
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  size = 0;
  front = NULL;
  back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  if(!isEmpty())
  {
    ListNode<T> *curr = front;
    ListNode<T> *temp;
    while(curr != 0) //deletes all nodes remaining in the list before deletion
    {
      temp = curr;
      curr = curr->next;
      delete temp;
    }
  }
}

//gets the size of the list
template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
  return size;
}

//checks if the list is empty
template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
  return (size == 0);
}

//prints the entire list
template <class T>
void DoublyLinkedList<T>::printList()
{
  ListNode<T> *curr = front;
  while(curr != NULL)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

//inserts something at the front of the list
template <class T>
void DoublyLinkedList<T>::insertFront(T dataInput)
{
  ListNode<T> *node = new ListNode<T>(dataInput);
  //Check if empty
  if(isEmpty())
  {
    back = node;
  }
  else
  {
    //not empty
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

//inserts something at the back of the list
template <class T>
void DoublyLinkedList<T>::insertBack(T dataInput)
{
  ListNode<T> *node = new ListNode<T>(dataInput);
  //Check if empty
  if(isEmpty())
  {
    front = node;
  }
  else
  {
    //not empty
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

//removes the value at the front of the list
template <class T>
T DoublyLinkedList<T>::removeFront()
{
  ListNode<T> *tempPointer = front;
  //not sure if we need this cuz i cant really figure out what it does
  if(front->next == NULL)
  {
    back = NULL;
  }
  else
  {
    front->next->prev = NULL;
  }
  front = front->next;
  tempPointer->next = NULL;
  T tempData = tempPointer->data;
  delete tempPointer;
  size--;
  return tempData;
}

//searches the list for a specific value
template <class T>
int DoublyLinkedList<T>::search(T val)
{
  cout << "searching" << endl;
  int position = -1; //negative positions will output a ValueNotFound
  ListNode<T> *curr = front;
  while(curr != NULL)
  {
    //iterate and attempt to find value
    position++;
    if(curr->data == val)
    {
      break;
    }
    else
    {
      curr = curr->next;
    }
  }
  if(curr == NULL)
    position = -1; //we did not find the value
  return position;
}

//gets the value at the front of the list
template <class T>
T DoublyLinkedList<T>::getFront()
{
  return front->data;
}

//removes the value at the back of the list
template <class T>
T DoublyLinkedList<T>::removeBack()
{
  T tempData = back->data;
  ListNode<T> *backTemp = back;
  back = back->prev;
  backTemp->prev = NULL;
  delete backTemp;
  size--;
  return tempData;
}

//removes the value at a specific position in the list
template <class T>
void DoublyLinkedList<T>::removeAtPos(int pos)
{
  cout << "remove at pos" << endl;
  if(front == NULL)
  {
    return;
  }
  ListNode<T> *temp = front;
  if (pos == 0)
  {
    front = temp->next;
    if(front)
    {
      front->prev = NULL;
    }
    delete temp;
    return;
  }
  for (int i = 0; i < pos && temp != NULL; i++)
  {
    temp = temp->next;
  }
  if(temp == NULL)
  {
    return;
  }
  temp->next->prev = temp->prev;
  delete temp;
}
