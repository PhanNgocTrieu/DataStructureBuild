#include <iostream>
#include <vector>

#define size 100
using namespace std;

int Hashing(int key)
{
    return key % 10;
}
int main()
{
    //vector<int> A(10);
    vector<int> num_list = {1,5,3,4,7,8,6,9};
    vector<int> list(10);
    
    
    for (int i = 0; i < 8; i++)
    {
        int hash;
        hash = Hashing(num_list[i]);
        list[hash] = num_list[i];
    }
    cout << "-----------------" << endl;
    for (int j = 0; j < 10; j++)
        cout << list[j] << endl;
    cout << endl;
    return 0;
}