#include <iostream>

struct Node
{
    int data;
    Node *next;
};

Node *GetNode(int data)
{
    Node *n = new Node;
    n -> data = data;
    n -> next = NULL;
    return n;
}


void Delete_oddNum(Node *&n)
{
    if (n == NULL)
    {
        return;
    }
    Node *nn = n;
    Node *prev = n;
    if (nn -> data % 2 != 0)
    {

    }
    
    do
    {
        if (nn -> data % 2 != 0)
        {
            Node *temp = nn;
            nn = 
            nn -> next = temp;
            delete temp;
            nn = nn -> next;
        }
        
        
    } while (nn -> next != n);
    n = nn;
}


void Print(Node *n)
{
    if (n == NULL)
    {
        return;
    }
    Node *nn = n;
    do
    {
        std::cout << nn -> data << " ";
        nn -> next;
    } while (nn -> next != n);
    std::cout << std::endl;
}

int main()
{
    Node *n = GetNode(572);
    n -> next = GetNode(112);
    n -> next -> next = GetNode(21);
    n -> next -> next -> next = GetNode(5);
    n -> next -> next -> next -> next= GetNode(1);
    n -> next -> next -> next -> next -> next= GetNode(6);
    n -> next -> next -> next -> next -> next -> next = n;

    Print(n);

    return 0;
}