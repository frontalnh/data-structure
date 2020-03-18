#include <istream>
using namespace std;

struct Element
{
public:
  string key;
};

class SearchHelper
{
public:
  int sequentialSearch(Element elements[], string key);
};