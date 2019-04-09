#include <istream>
using namespace std;

struct Element
{
public:
  string key;
  int value;
};

class SortHelper
{
public:
  void insertionSort(Element elements[], int count);
  void insert(Element elements[], Element element, int index);
};