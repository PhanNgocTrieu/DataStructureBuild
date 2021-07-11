#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
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


void Print(Node *n)
{
    if (n == NULL)
    {
        return;
    }
    else
    {
        Node *run_n = n;
        for (run_n; run_n != NULL; run_n = run_n -> next)
        {
            cout << run_n -> data << " ";
        }
        cout << endl;
    }    
}

void remove_dupl(Node *&n)
{
    if (n == NULL)
        return;
    
    
    Node *run = n;
    Node *temp;
    for (run; run -> next != NULL; run = run->next)
    {
        if (run -> data == run -> next -> data)
        {
            temp = run -> next;
            run -> next = run -> next -> next;
            delete temp;
            remove_dupl(run);
        }
        remove_dupl(n -> next);        
    }
}

int main()
{
    Node *n = NULL;
    Push(n,1);
    Push(n,1);
    Push(n,1);
    Push(n,2);
    Push(n,3);
    Push(n,4);
    Push(n,4);
    Push(n,5);
    Push(n,5);
    Push(n,61);    
    cout << "Befor remove: " << endl;
	Print(n);
    remove_dupl(n);
	cout << "After remove: "<< endl;
	Print(n);
    return 0;
}