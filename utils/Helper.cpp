#include <ctime>
#include <iostream>
using namespace std;
class Helper
{
  private:
    clock_t startTime;
    clock_t endTime;
    clock_t measured;

  public:
    void startMeasure()
    {
        startTime = clock();
    }
    void endMeasure(char *label)
    {
        endTime = clock();
        measured = endTime - startTime;
        cout << label << ": " << double(measured) / CLOCKS_PER_SEC << endl;
    }
};