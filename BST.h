class TreeNode
{
  TreeNode();
  TreeNode(int key);
  //TreeNode(int k, <type> value)
  ~TreeNode();
  //when working with template classes
  virtual ~TreeNode();

  int key;
  TreeNode *left;
  TreeNode *right;
};

//treenode implementation
TreeNode::TreeNode()
{
  left = NULL;
  right = NULL;
}

TreeNode::TreeNode(int key)
{
  key = k;
  left = NULL;
  right = NULL;
}

//do implementation of destructor on own
#include "TreeNode.h"
#include <iostream>

template <class T>
class BST
{
  public:
    BST();
    ~BST();
    //virtual ~BST() -when working with template classes

    void insert(TreeNode<T> *node); //which in this example is also our key
    bool searchNode(int value); //which in this example is also our key
    bool deleteNode(int k);

    bool isEmpty();
    TreeNode<T>* getMin();
    TreeNode<T>* getMax();

    TreeNode<T>* getSuccessor(TreeNode<T> *d);
    void printTree(TreeNode<T> *node);

    TreeNode<T> *root;
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

template <class T>
TreeNode<T>* BST::getMax()
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

template <class T>
bool BST<T>::isEmpty()
{
  return(root == NULL);
}

template <class T>
void BST<T>::insert(int value)
{
  TreeNode<T> *node = new TreeNode(value); //value is also the key
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
      .//find the insertion point
      parent = curr;
      if(value < curr->key)
      {
        //go left
        curr = curr->left;
        if(curr == NULL)
        {
          parent->left = node;
          break;
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
  }
}

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

template <class T>
bool BST<T>::deleteNode(int k)
{
  if(isEmpty())
  {
    return false;
  }
  else if(!search(k))
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
  }
}

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
