#include "../BinTree/BinTree.cpp"
using namespace std;

class BST : public BinTree
{
public:
  treePointer root;
  BST(treePointer ptr) : BinTree(ptr)
  {
    root = ptr;
  }
  treePointer insert(treePointer ptr, int data);
  treePointer search(treePointer ptr, int data);
  void remove(int data);
};

treePointer BST::insert(treePointer ptr, int value)
{
  if (ptr->data < value)
  {
    if (ptr->rightChild)
      return insert(ptr->rightChild, value);

    treePointer rightChild = new Node(value, ptr);
    ptr->rightChild = rightChild;
    return rightChild;
  }

  if (ptr->data > value)
  {
    if (ptr->leftChild)
      return insert(ptr->leftChild, value);

    treePointer leftChild = new Node(value, ptr);
    ptr->leftChild = leftChild;
    return leftChild;
  }
  return NULL;
};

treePointer BST::search(treePointer ptr, int value)
{
  if (ptr->data == value)
    return ptr;
  if (ptr->data < value)
    return search(ptr->rightChild, value);
  if (ptr->data > value)
    return search(ptr->leftChild, value);

  return NULL;
};

void BST::remove(int value)
{
  treePointer ptr = search(root, value);

  if (ptr->leftChild)
  {
    cout << "has left" << endl;
    ptr = ptr->leftChild;
  }
  else if (ptr->rightChild)
  {
    cout << "has right" << endl;
    ptr = ptr->rightChild;
  }
  else
  {
    delete ptr;
    if (ptr->parent->leftChild->data == value)
      ptr->parent->leftChild = NULL;
    if (ptr->parent->rightChild->data == value)
      ptr->parent->rightChild = NULL;
  }
}

int main(void)
{
  treePointer root = new Node(5, NULL);
  BST *bst = new BST(root);

  bst->insert(root, 2);
  bst->insert(root, 6);
  bst->remove(6);
  bst->inorderTraverse(root);

  int arr[4];
  cout << sizeof(arr) << endl;
  cout << sizeof(int) << endl;
  cout << sizeof(arr) / sizeof(int) << endl;
  cout << "     a" << endl; //5
  cout << "    / \\" << endl;
  cout << "   a   a" << endl;
  cout << sizeof(bst) << endl;

  // cout << "a: " << a << endl;
  // cout << ptr << endl;
}