#include <iostream>
using namespace std;
typedef struct Node *treePointer;

// 특정 노드는 leftNode, rightNode, parentNode 의 pointer 정보를 가지며,
// 존재하지 않는경우 각각 NULL 포인터를 가진다.
class Node
{
  public:
    int data;
    treePointer leftChild;
    treePointer rightChild;
    treePointer parent;
    Node(int value, treePointer parentPtr);
};

Node::Node(int value, treePointer parentPtr)
{
    data = value;
    leftChild = NULL;
    rightChild = NULL;
    parent = parentPtr;
}

class BinTree
{
  public:
    Node *root;
    BinTree(Node *ptr)
    {
        root = ptr;
    };
    void preorderTraverse(Node *ptr);
    void postorderTraverse(Node *ptr);
    void inorderTraverse(Node *ptr);
};

void BinTree::preorderTraverse(Node *ptr)
{
    if (ptr)
    {
        cout << "Searching data. data: " << ptr->data << endl;
        preorderTraverse(ptr->leftChild);
        preorderTraverse(ptr->rightChild);
    }
}
void BinTree::postorderTraverse(Node *ptr)
{
    if (ptr)
    {
        postorderTraverse(ptr->leftChild);
        postorderTraverse(ptr->rightChild);
        cout << "Searching data. data: " << ptr->data << endl;
    }
}
void BinTree::inorderTraverse(Node *ptr)
{
    if (ptr)
    {
        inorderTraverse(ptr->leftChild);
        cout << "Searching data. address: " << ptr << " value: " << ptr->data << endl;
        inorderTraverse(ptr->rightChild);
    }
}

// int main(void)
// {
//     Node *node1 = new Node(1);
//     Node *leftChild = new Node(2);
//     Node *rightChild = new Node(3);

//     node1->leftChild = leftChild;
//     node1->rightChild = rightChild;
//     BinTree *binTree = new BinTree(node1);

//     cout << "preorderTraverse" << endl;
//     binTree->preorderTraverse(binTree->root);
//     cout << "inorderTraverse" << endl;
//     binTree->inorderTraverse(binTree->root);
//     cout << "postorderTraverse" << endl;
//     binTree->postorderTraverse(binTree->root);
// }