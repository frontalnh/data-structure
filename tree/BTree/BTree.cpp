#include <iostream>
#include <cmath>

using namespace std;
class BNode;

struct BElement
{
    int data;
    BNode *ptr;
};

class BNode
{

  public:
    BNode(int size);
    // 클래스에서 동작 배열은 항상 마지막 프로퍼티로 와야 한다.
    // 그래야 메모리를 적합하게 할당하고 해제할 수 있다.
    BElement elements[];
};

BNode::BNode(int size)
{
    BElement elements[size];
}

class BTree
{
  public:
    BTree(int degree);
    void insert(int data);
    BNode *root;
    int degree; // 해당 B Tree 의 차수 즉, 각 노드의 최대 원소의 수이다.

  private:
    void insertToNode(BNode *ptr, BElement elem);
    BNode *BTree::findLeafForInsertion(BNode *ptr, int data);
    BElement *split(BNode *ptr);
};

BTree::BTree(int deg)
{
    degree = deg;
    root = nullptr;
}

void BTree::insert(int data)
{
    // 1. 삽입하고자 하는 원소가 들어갈 수 있는 리프노드를 탐색
    BNode *leafNode = findLeafForInsertion(root, data);
    // 2. 해당 리프노드가 full 인 경우 삽입 이후 ⌈m/2⌉ 번째 원소가 ⌈m/2⌉이후의 원소쌍을 가진 새로운 노드를 가르키도록 하고 부모 노드로 보낸다.

    // 3. 해당 리프노드의 ⌈m/2⌉ 번째와 그 이후의 원소들을 제거한다.
    // 4. ⌈m/2⌉번째 원소를 부모 노드의 원소리스트에 다시 insert 함수를 실행한다.
}

// 해당 노드에서 리프노드를 찾는다.
// 자식들을 타고 내려가 적합한 리프노드가 나올때까지 찾아서 해당 노드의 포인터를 반환한다.
BNode *BTree::findLeafForInsertion(BNode *ptr, int data)
{
    int count = sizeof(ptr->elements) / sizeof(BElement);

    for (int i = 0; i < count; i++)
    {
        if (data < ptr->elements[i].data)
        {
            BNode *nextPtr = ptr->elements[i].ptr;
            if (nextPtr)
            {
                return findLeafForInsertion(nextPtr, data);
            }
            else
            {
                return ptr;
            }
        }
    };
};

// 특정 노드를 쪼개어 부모가 될 원소의 포인터를 반환한다.
BElement *BTree::split(BNode *ptr)
{
    int index = ceil(degree / 2) - 1;
    BNode *newNode = new BNode(degree - 1);

    for (int i = 0; i < degree - 2 - index; i++)
    {
        newNode->elements[i] = ptr->elements[index + 1];
    }
    newNode->elements[1] = ptr->elements[1];
    BElement *newParentElem = new BElement();
    newParentElem->ptr = newNode;

    return newParentElem;
}

int main(void)
{
    BTree *tree = new BTree(3);
}