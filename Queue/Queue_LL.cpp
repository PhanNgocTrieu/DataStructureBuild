#include <iostream>
using namespace std;

struct Queue {
    int data;
    Queue *next;
};

void Enqueue(Queue *&q, int value)
{
	if(q == NULL)
	{
		Queue *q1 = new Queue;
		q1 -> data = value;
        q1 -> next = NULL;
        
		q = q1;
	}
	else
	{
		Queue *q2 = new Queue;
		q2 -> data = value;
		q2 -> next = NULL;
		
		
		Queue *run = q;
		while(run != NULL && run->next != NULL)
		{
			run = run -> next;
		
		}	
		run -> next = q2;
	}
}

int Dequeue(Queue *&q) {
    if (q == NULL)
    {
        
        return 0;
    }
    else
    {
        int data = q -> data;
        Queue *p = q;
        q = q -> next;
        delete(p);  // delete p;
        return data;
    }  
}


void Print(Queue *q)
{
    if (q == NULL)
    {
        return;
    }
    else
    {
        Queue *p;
        for (p = q; p != NULL; p = p -> next)
        {
            cout << p -> data << " ";
        }
        cout << endl;
    }    
}
int main() {
    
    Queue *q = NULL;
    Enqueue(q,3);
    Enqueue(q,4);
    Enqueue(q,5);
    Enqueue(q,6);
    Print(q);

    Dequeue(q);
    Print(q);

    return 0;
}