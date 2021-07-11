#include <iostream>
using namespace std;

struct Stack {
    int data;
    Stack *next;
};

void Push(Stack *&L,int value) {
    Stack *p = new Stack;
    p -> data = value;
    p -> next = NULL;
    if (L == NULL)
    {
        L = p;
    }
    else
    {
        Stack *i = L;
        while (i != NULL && i ->next != NULL)
        {
            i = i ->next;
        }
        i -> next = p;    
    }
}

void Print(Stack *L)
{
    if (L == NULL)
    {
        return;
    }
    else
    {
        Stack *p = L;
        for (Stack *k = p; k != NULL; k = k -> next)
        {
            cout << k -> data << " ";
        }
        cout << endl;
    }    
}

int Pop(Stack *&L) {
    Stack *st = L;
    if (st == NULL)
    {
        return -1;
    }
    else
    {
        Stack *ptr = L;
        Stack *pre_L;
        while (ptr != NULL && ptr->next != NULL)
        {
            pre_L = ptr;
            ptr = ptr -> next;
        }
        pre_L -> next = ptr -> next;
        int k = ptr -> data;
        delete(ptr);
        return k;
    }
}

int Top(Stack *L) {
    Stack *st = L;
    if (st == NULL)
    {
        return -1;
    }
    else
    {
        Stack *ptr = L;
        while (ptr != NULL && ptr->next != NULL)
        {
            ptr = ptr -> next;
        }
        
        return ptr->data;
    }
}

int main(){
    Stack *L = NULL;
    Push(L,3);
    Push(L,4);
    Push(L,5);
    Push(L,6);
    Push(L,12);
    Push(L,55);

    Print(L);

    cout << "Top: " << Top(L) << endl;
    Print(L);
    cout << "Pop: " << Pop(L) << endl;
    Print(L);

    return 0;
}
