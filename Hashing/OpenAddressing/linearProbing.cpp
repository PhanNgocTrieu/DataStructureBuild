#include <iostream>

#define HASHTABLESIZE 10

typedef struct
{
    int key[HASHTABLESIZE];
    int state[HASHTABLESIZE];
    int value[HASHTABLESIZE];
    /* -1=lazy delete, 0=empty, 1=occupied */
} hashtable;
/* The hash function */
int hash(int input)
{
    return input % HASHTABLESIZE;
}

void open_addressing_insert(int item, hashtable *ht)
{
    int hash_value;
    hash_value = hash(item);
    int i = hash_value;

    int _pad = 1;
    while (ht->state[i] == 1)
    {
        i = (hash(item) + _pad) % HASHTABLESIZE;
        _pad++;

        if (i == hash_value)
            break;
    }

    if (i < HASHTABLESIZE && ht->state[i] != 1)
    {
        ht->key[i] = i;
        ht->state[i] = 1;
        ht->value[i] = item;
    }
}

void printHash(hashtable *ht)
{
    for (int idex = 0; idex < HASHTABLESIZE; idex++)
    {
        std::cout << "Key: " << idex << " - state: " << ht->state[idex] << " -- value: " << ht->value[idex] << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    hashtable *ht = new hashtable;
    hashtable *ht2 = new hashtable;

    
    open_addressing_insert(3, ht2);
    open_addressing_insert(5, ht2);
    open_addressing_insert(22, ht2);
    open_addressing_insert(11, ht2);
    open_addressing_insert(6, ht2);
    open_addressing_insert(7, ht2);
    open_addressing_insert(8, ht2);
    open_addressing_insert(33, ht2);
    open_addressing_insert(20, ht2);
    open_addressing_insert(103, ht2);
    open_addressing_insert(102, ht2);
    printHash(ht2);

    /*
    Key: 0 - state: 1 -- value: 20
    Key: 1 - state: 1 -- value: 1998211208
    Key: 2 - state: 1 -- value: 22
    Key: 3 - state: 1 -- value: 3
    Key: 4 - state: 1 -- value: 11
    Key: 5 - state: 1 -- value: 5
    Key: 6 - state: 1 -- value: 6
    Key: 7 - state: 1 -- value: 7
    Key: 8 - state: 1 -- value: 8
    Key: 9 - state: 1 -- value: 33
    */
    // ************* ANOTHER ONE ******************


    open_addressing_insert(3, ht);
    open_addressing_insert(5, ht);
    open_addressing_insert(22, ht);
    open_addressing_insert(11, ht);
    open_addressing_insert(6, ht);
    open_addressing_insert(7, ht);
    open_addressing_insert(8, ht);
    open_addressing_insert(20, ht);
    printHash(ht);
    /*
    Key: 0 - state: 1 -- value: 20
    Key: 1 - state: 1 -- value: 11
    Key: 2 - state: 1 -- value: 22
    Key: 3 - state: 1 -- value: 3
    Key: 0 - state: 0 -- value: 0    // no value was put
    Key: 5 - state: 1 -- value: 5
    Key: 6 - state: 1 -- value: 6
    Key: 7 - state: 1 -- value: 7
    Key: 8 - state: 1 -- value: 8
    Key: 0 - state: 0 -- value: 0   // no value was put
    */
    return 0;
}