#include "./OverflowChainingHashMap.cpp"
#include <iostream>
using namespace std;

int main(void)
{
    HashMap *hashMap = new HashMap(100);
    hashMap->insert(3);
    cout << "buckets 의 주소값: " << hashMap->buckets[0] << endl;
    cout << "buckets 의 첫 데이터의 주소값: " << hashMap->buckets[0] << endl;
    cout << "buckets 의 두번째 데이터의 주소값: " << hashMap->buckets[1] << endl;
    if (hashMap->buckets[1]->value)
    {
        cout << "1번 버킷의 데이터가 존재합니다" << endl;
    }
}