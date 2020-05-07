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

class BST
{
  public:
    BST();
    ~BST();
    //virtual ~BST() -when working with template classes

    void insert(int value); //which in this example is also our key
    bool searchNode(int value); //which in this example is also our key
    bool deleteNode(int k);

    bool isEmpty();
    TreeNode* getMin();
    TreeNode* getMax();

    TreeNode* getSuccessor(TreeNode *d);
    void printTree(Tree Node *node);

  private:
    TreeNode *root;
};

BST::BST()
{
  root = NULL;
}

BST::~BST()
{
  //do it on my own
}

void BST::printTree(TreeNode *node)
{
  if(node == NULL)
  {
    return;
  }
  printTree(node->left);
  cout << node->key << endl;
  printTree(node->right);
}

TreeNode* BST::getMax()
{
  TreeNode *curr = root; //start at the root
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

TreeNode* BST::getMin()
{
  TreeNode *curr = root; //start at the root
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

bool BST::isEmpty()
{
  return(root == NULL);
}

void BST::insert(int value)
{
  TreeNode *node = new TreeNode(value); //value is also the key
  if(root == NULL)
  {
    //we have an empty tree
    root = node;
  }
  else
  {
    //tree is not empty, need to find the location
    TreeNode *curr = root;
    TreeNode *parent; //empty Node
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

bool BST::searchNode(int value)
{
  if(isEmpty())
  {
    return false;
  }
  else
  {
    //tree is not empty
    TreeNode *current = root;
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

bool BST::deleteNode(int k)
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
  TreeNode *current = root;
  TreeNode *parent = root;
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
      TreeNode *successor = getSuccessor(current);
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

TreeNode* BST::getSuccessor(TreeNode *d)
{
  //d is the node to be deleted
  TreeNode *sp = d;
  TreeNode *successor = d;
  TreeNode *current = d->right;
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
