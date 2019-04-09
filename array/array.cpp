#include <iostream>
#include <ctime>
#include "../utils/Helper.cpp"
using namespace std;

int main(void)
{
    Helper *helper = new Helper();
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    helper->startMeasure();
    for (int i = 7; i < 8; i++)
    {
        arr1[i] = arr1[i + 1];
    }
    helper->endMeasure("shift by 1");

    helper->startMeasure();
    for (int i = 0; i < 8; i++)
    {
        arr2[i] = arr2[i + 1];
    }
    helper->endMeasure("shift by 2");
}