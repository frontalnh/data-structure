#include "SortHelper.h"
#include <iostream>
using namespace std;

void SortHelper::insert(Element elements[], Element element, int index)
{
    for (int i = index; i > 0; i--)
    {

        if (elements[i - 1].value > element.value)
        {
            elements[i] = elements[i - 1];
        }
        else
        {
            elements[i] = element;
            return;
        }
    }

    elements[0] = element;
}

void SortHelper::insertionSort(Element elements[], int count)
{
    for (int i = 0; i < count; i++)
    {
        insert(elements, elements[i], i);
    }
}

int main(void)
{
    SortHelper sortHelper;
    Element element1 = {"1", 1};
    Element element2 = {"2", 2};
    Element element3 = {"3", 3};
    Element element4 = {"4", 4};

    Element elements2[4] = {element4, element2, element3, element1};
    sortHelper.insertionSort(elements2, 4);

    cout << "insertion sorting has been completed. elements: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << elements2[i].value << endl;
    }
    return 0;
}