#include <iostream>
#include "TreeNode.h"
#include "Faculty.h"
#include "Student.h"

using namespace std;

template <class T>
class BST
{
  public:
    BST();
    ~BST();
    int size = 0; //size of the tree
    //virtual ~BST() -when working with template classes

    void insert(TreeNode<T> *node); //inserts a new node
    bool searchNode(int value); //searches for a given value in the tree
    bool deleteNode(int k); //deletes a specific node

    bool isEmpty(); //checks if the BST is empty
    TreeNode<T>* getMin(); //gets the smallest value in the BST
    TreeNode<T>* getMax(); //gets the biggest value in the BST

    TreeNode<T>* getSuccessor(TreeNode<T> *d); //gets the sucessor to the inputted value
    void printTree(TreeNode<T> *node); //prints the values in the tree
    TreeNode<T>* returnData(int val); //returns the data at a given node

    TreeNode<T> *root; //the root of the BST
};

template <class T>
BST<T>::BST()
{
  root = NULL;
}

template <class T>
BST<T>::~BST()
{
  //delete root;???
}

//prints the results of the tree
template <class T>
void BST<T>::printTree(TreeNode<T> *node)
{
  if(node == NULL)
  {
    return;
  }
  printTree(node->left);
  cout << node->key << endl;
  printTree(node->right);
}

//gets the max value in the tree
template <class T>
TreeNode<T>* BST<T>::getMax()
{
  TreeNode<T> *curr = root; //start at the root
  if(root == NULL)
  {
    return NULL; //tree is empty
  }
  while(curr->right != NULL)
  {
    curr = curr->right;
  }
  return curr; //if tree consisted of a number type curr->key or curr->value
}

//gets the min value in the tree
template <class T>
TreeNode<T>* BST<T>::getMin()
{
  TreeNode<T> *curr = root; //start at the root
  if(root == NULL)
  {
    return NULL; //tree is empty
  }
  while(curr->left != NULL)
  {
    curr = curr->left;
  }
  return curr; //if tree consisted of a number type curr->key or curr->value
}

//checks if the tree is empty
template <class T>
bool BST<T>::isEmpty()
{
  return(root == NULL);
}

//inserts a value into the tree
template <class T>
void BST<T>::insert(TreeNode<T> *node)
{

  if(root == NULL)
  {
    //we have an empty tree
    root = node;
  }
  else
  {
    //tree is not empty, need to find the location
    TreeNode<T> *curr = root;
    TreeNode<T> *parent; //empty Node
    while(true)
    {
      //find the insertion point
      parent = curr;
      if(node->key < curr->key)
      {
        //go left
        curr = curr->left;
        if(curr == NULL)
        {
          parent->left = node;
          break;
        }
      }
      else
      {
          //go right
        curr = curr->right;
        if(curr == NULL)
        {
            //we found the nodes home
          parent->right = node;
          break;
        }
      }
    }
  }
  size++;
}

//searches for a specific value in the tree
template <class T>
bool BST<T>::searchNode(int value)
{
  if(isEmpty())
  {
    return false;
  }
  else
  {
    //tree is not empty
    TreeNode<T> *current = root;
    while(current->key != value)
    {
      if(value < current->key)
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }
      if(current == NULL)
      {
        return false;
      }
    }
    return true;
  }
}

//deletes a specific node from the tree
template <class T>
bool BST<T>::deleteNode(int k)
{
  if(isEmpty())
  {
    return false;
  }
  else if(!searchNode(k))
  {
    return false;
  }
  //tree is not empty and the value exists so let's look for the value
  TreeNode<T> *current = root;
  TreeNode<T> *parent = root;
  bool isLeft = true;
  //usual code to find TreeNode
  //we will also update pointers
  while(current->key != k)
  {
    parent = current;
    if(k < current->key)
    {
      isLeft = true;
      current = current->left;
    }
    else
    {
      isLeft = false;
      current = current->right;
    }
    if(current == NULL)
    {
      return false;
    }
  }
    //if we made here, then we've found the node now let's proceed to deleteNode
    //no children, leaf TreeNode
    if(current->left == NULL && current->right == NULL)
    {
      if(current == root)
      {
        root = NULL;
      }
      else if(isLeft)
      {
        parent->left = NULL;
      }
      else
      {
        parent->right = NULL;
      }
    }
    //one child and the child is left
    else if(current->right == NULL)
    {
      //does not have right children
      if(current == root)
      {
        root = current->left;
      }
      else if(isLeft)
      {
        parent->left = current->left;
      }
      else
      {
        parent->right = current->left;
      }
    }
    //one child and the child is right
    else if(current->left == NULL)
    {
      //does not have left children
      if(current == root)
      {
        root = current->right;
      }
      else if(isLeft)
      {
        parent->left = current->right;
      }
      else
      {
        parent->right = current->right;
      }
    }
    else
    {
      //the node has 2 children
      TreeNode<T> *successor = getSuccessor(current);
      if(current == root)
      {
        root = successor;
      }
      else if(isLeft)
      {
        parent->left = successor;
      }
      else
      {
        parent->right = successor;
      }
      successor->left = current->left;
      return true;
    }
  size--;
}

//gets the successor to a specific node in the tree
template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d)
{
  //d is the node to be deleted
  TreeNode<T> *sp = d;
  TreeNode<T> *successor = d;
  TreeNode<T> *current = d->right;
  while(current != NULL)
  {
    sp = successor;
    successor = current;
    current = current->left;
  }
  if(successor != d->right)
  {
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

//returns the value at a given node
template <class T>
TreeNode<T>* BST<T>::returnData(int val)
{
  if(searchNode(val))
  {
    TreeNode<T> *curr = root;
    while(curr->key != val)
    {
      if(val < curr->key)
      {
        curr = curr->left;
      }
      else
      {
        curr = curr->right;
      }
    }
    return curr;
  }
  else
  {
    cout << "this node does not exist" << endl;
  }
}
