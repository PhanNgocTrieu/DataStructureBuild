#include <iostream>
#include <map>

/*
map can use for store pair of values, first is key values and other one is data values
*/
int main(void)
{
    std::map<float, float> table;
    table.insert(std::pair<int,int>(1,40));
    table.insert(std::pair<int,int>(2,10));
    table.insert(std::pair<int,int>(3,20));
    table.insert(std::pair<int,int>(4,210));
    table.insert(std::pair<int,int>(12,230));

    for (std::map<float,float>::iterator i = table.begin(); i != table.end(); i++)
    {
        std::cout << i -> first << " --> " << i -> second << std::endl;
    }

    std::cout << "Using remove key 2: " << table.erase(15) << std::endl;
    std::cout << "Using max_size(): " << table.max_size() << std::endl;
    

}