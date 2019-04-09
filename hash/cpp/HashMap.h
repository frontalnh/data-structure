#include <istream>
using namespace std;

struct Data
{
public:
  Data(int value);
  int value;
  Data *ptr;
};

class HashMap
{
private:
  int size;
  void chain(int value);

public:
  HashMap(int size);
  void insert(int value);
  int findByKey(int key);
  Data *buckets[];
};