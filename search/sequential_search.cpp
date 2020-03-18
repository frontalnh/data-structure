#include <iostream>
#include "SearchHelper.h"
using namespace std;

int SearchHelper::sequentialSearch(Element elements[], string key)
{
    cout << "------------------------" << endl;
    cout << "start sequential search!" << endl;
    cout << "------------------------" << endl;

    int i;
    int count = sizeof(*elements) / sizeof(elements[0]);
    cout << "address of the elements: " << elements << endl;
    cout << "count is: " << count << endl;
    for (i = 0; i < count; i++)
    {
        if (elements[i].key == key)
        {
            return i;
        };
    };

    cout << "time complexity is: O(n)" << endl;

    return 0;
}

int main(void)
{
    SearchHelper searchHelper;
    Element element1 = {"123"};
    Element element2 = {"namhoon"};
    Element elements[] = {element1, element2};
    int result = searchHelper.sequentialSearch(elements, "namhoon");
    cout << result;
}
