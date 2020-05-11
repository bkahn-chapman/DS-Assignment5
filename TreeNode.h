#include <iostream>

class TreeNode
{
  TreeNode();
  TreeNode(T d, int key);
  //TreeNode(int k, <type> value)
  ~TreeNode();
  //when working with template classes
  virtual ~TreeNode();

  int key;
  T data;
  TreeNode<T> *left;
  TreeNode<T> *right;
};

//treenode implementation

template <class T>
TreeNode<T>::TreeNode(){
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T d,int k){
  data = d;
  key = k;
  left = NULL;
  right = NULL;
}
template <class T>
TreeNode<T>::~TreeNode()
{
  cout << "The node has been deleted." << endl;
  delete data;
  delete left;
  delete right;
}
//do implementation of destructor on own
