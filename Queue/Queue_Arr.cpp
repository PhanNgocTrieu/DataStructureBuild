#include <iostream>
using namespace std;

//Definated function:

void Enqueue(int queue[],int value,int& rear, int arraySize){
    if (rear == arraySize)   //Queue is full
    {
        cout << "Overflow";
    }
    else
    {
        queue[rear] = value;
        rear++;
    }
}

void Dequeue(int queue[], int& front, int rear) { // xoa khoi dau hang cho
    if (front == rear) //Queue is empty
    {
        cout << "Underflow\n";
    }
    else    
    {
        queue[front] = 0;
        front++;
    }   
}


int Front(int queue[], int front) {
    return queue[front];
}

int Size(int front, int rear) {
    return (rear-front);
}

bool IsEmpty(int front, int rear)
{
    if (front == rear)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

int main () {
    int queue[10];
    int rear = 0;
    int front = 0;

    Enqueue(queue,2,rear,10);
    Enqueue(queue,3,rear,10);
    Enqueue(queue,4,rear,10);
    Enqueue(queue,20,rear,10);

    

    cout << "After Enqueue: ";
    for (int i = 0; i < rear; i++)
    {
        cout << queue[i] << " -> ";
    }

    Dequeue(queue,front,rear);
    Dequeue(queue,front,rear);
    Dequeue(queue,front,rear);
    cout << "\nAfter Dequeue: ";
    for (int j = 0; j < rear; j++)
    {
        cout << queue[j] << " -> ";
    }
    

    
        
    


    return 0;
}