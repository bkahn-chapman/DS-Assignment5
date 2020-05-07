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

TreeNode::~TreeNode()
{
  cout << "The node has been deleted." << endl;
}
//do implementation of destructor on own
