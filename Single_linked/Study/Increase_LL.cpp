#include <iostream>
using namespace std;

struct  Node {
    int data;
    Node *next;
};

void Push(Node *&L,int value)
{
    Node *n = new Node;
    n -> data = value;
    n -> next = NULL;

    if (L == NULL)
    {
        L = n;
    }
    else
    {
        Node *run = L;

        while (run != NULL && run -> next != NULL)
        {
            run = run -> next;
        }
        run -> next = n;   
    }    
}

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void Increase(Node *&L)
{
    Node *run_i = L;
 
    for (run_i; run_i != NULL; run_i = run_i -> next)
    {
        Node *run_j = run_i -> next;
        for (run_j; run_j != NULL; run_j = run_j -> next)
        {
            if (run_i -> data > run_j -> data)
            {
                Swap(run_i->data,run_j->data);
            }
        }
        
    }
    
}

void Print(Node *L)
{
    if (L == NULL)
    {
        return;
    }
    else
    {
        Node *run = L;
        for (run; run != NULL; run = run -> next)
        {
            cout << run -> data << " ";
        }
        cout << endl;
    }
}

int main() {
    Node *L = NULL;
    Push(L,3);
    Push(L,5);
    Push(L,7);
    Push(L,1);
    Push(L,3);
    Push(L,6);
    Push(L,12);
    Push(L,4);
    Push(L,9);
    Push(L,8);
    Push(L,44);
    Push(L,33);
    Push(L,21);
    Push(L,22);
    Push(L,55);
    Push(L,12);
    Push(L,100);
    Push(L,50);
    
    
    Print(L);

    Increase(L);
    Print(L);
    return 0;
}