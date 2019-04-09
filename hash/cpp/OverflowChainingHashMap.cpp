#include "HashMap.h"

Data::Data(int v)
{
    value = v;
};

HashMap::HashMap(int initialSize)
{
    size = initialSize;
    for (int i = 0; i < size; i++)
    {
        buckets[i] = new Data(-1);
    }
};

void HashMap::insert(int value)
{
    int address = value % size;
    Data *data = new Data(value);

    if (buckets[address]->value != -1)
    {
        buckets[address] = data;
    }
};
