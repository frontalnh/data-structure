#include <iostream>
#include <math.h>
#define MAX_HEAP_SIZE 100
#define WORD_SIZE 2
using namespace std;

struct element
{
  int data;
};

class Heap
{
private:
  void printLine(int line);
  void printLineInitSpaces(int line);
  int getSize();
  void printSpace(int length);
  int initialSpace(int height);
  void printValue(int value);
  void printLineSpace(int height);

protected:
  int max;
  int getHeight();
  int getLineHeight();
  int wordSpace(int height);

public:
  element heap[MAX_HEAP_SIZE];
  Heap();
  void display();
};

Heap::Heap()
{
  max = 0;
  cout << "size of heap: " << sizeof(heap) << endl;
  getSize();
};

int Heap::getSize()
{
  return sizeof(heap) / 8; // divide by size of address which is 8
}

void Heap::display()
{

  for (int line = 1; line <= getHeight(); line++)
  {
    printLine(line);
  }
};

// 라인 출력은 1 부터 한다.
void Heap::printLine(int height)
{
  cout << endl;
  printSpace(initialSpace(height));

  int itemCount = pow(2, height - 1);
  int totalItemAbove = pow(2, height - 1) - 1;

  for (int i = 0; i < itemCount; i++)
  {
    if (i != 0)
      printSpace(wordSpace(height));
    int index = totalItemAbove + i;
    printValue(heap[index].data);
  }
}

void Heap::printValue(int value)
{
  if (value == 0)
  {
    cout << "";
    return;
  }
  if (value < 10)
  {
    cout << value << "_";
    return;
  }
  else
  {
    cout << value;
  }
}

// 한 라인을 프린트하기 전에 위의 공백을 프린트 해준다.
void Heap::printLineSpace(int height)
{
  if (height == 1)
    return;
}

void Heap::printSpace(int length)
{
  for (int i = 0; i < length; i++)
    cout << " ";
}

int Heap::initialSpace(int height)
{
  if (height == getHeight())
    return 0;
  return initialSpace(height + 1) + WORD_SIZE + (wordSpace(height + 1) - WORD_SIZE) / 2;
}

int Heap::wordSpace(int height)
{
  if (height > getHeight())
    return 1;
  if (height == getHeight())
    return WORD_SIZE + 2;

  return 2 * wordSpace(height + 1) + WORD_SIZE;
}

// 현재 히프의 높이를 반환한다.
int Heap::getHeight()
{
  return ceil(log(max + 1) / log(2));
}
