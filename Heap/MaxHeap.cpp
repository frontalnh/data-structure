#include <iostream>
#include <math.h>
#include "./Heap.cpp"
using namespace std;

class MaxHeap : public Heap
{
  private:
    int insert(int index, int value);
    void remove(int index, int value);

  public:
    MaxHeap();
    int push(int value);
    int pop();
};

MaxHeap::MaxHeap() : Heap() {}

int MaxHeap::insert(int index, int value)
{
    if (index == 0)
    {
        element elem = {value};
        heap[index] = elem;
        return index;
    }

    int parentIndex = floor((index - 1) / 2);

    if (heap[parentIndex].data < value)
    {
        heap[index] = heap[parentIndex];
        return insert(parentIndex, value);
    }
    if (heap[parentIndex].data > value)
    {
        element elem = {value};
        heap[index] = elem;
        return index;
    }
    return index;
}

int MaxHeap::push(int value)
{
    max++;
    return insert(max - 1, value);
}

int MaxHeap::pop()
{
    max--;
    element poped = heap[0];

    remove(0, poped.data);

    return poped.data;
}

void MaxHeap::remove(int index, int value)
{
    if (heap[index].data <= value)
        heap[index] = element();

    element leftChild = heap[index * 2 + 1];
    element rightChild = heap[index * 2 + 2];

    if ((leftChild.data != 0) || (rightChild.data != 0))
    {
        if (leftChild.data > rightChild.data)
        {
            heap[index] = leftChild;
            remove(index * 2 + 1, value);
        }
        else
        {
            heap[index] = rightChild;
            remove(index * 2 + 2, value);
        }
    }
}

int main(void)
{
    MaxHeap *heap = new MaxHeap();
    for (int i = 11; i < 30; i++)
    {
        heap->push(i);
    }
    // heap->pop();
    heap->display();
}