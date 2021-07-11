#include <iostream>

using namespace std;


void InsertAtBack(int queue[], int element, int &rear, int array_size)
{
    if (rear == array_size)
    {
        cout << "Overflow\n";
    }
    else
    {
        queue[rear] == element;
        rear++;
    }
}

void DeleteFromBack(int queue[], int &rear, int front){
    if(front == rear)
        printf("Underflow\n");
    else{
        rear = rear - 1;
        queue[rear] = 0;
    }
}

void InsertAtFront(int queue[], int element,int &rear,int &front,int array_Size)
{
    if (rear == array_Size)
    {
        cout << "Underflow\n";
    }
    else
    {
        for (int i = rear; i > front; i--)
        {
            queue[i] = queue[i-1];
        }
        queue[front] = element;
        rear = rear + 1;
        
    }
    
    
}

void DeleteAtFront(int queue[], int &front, int &rear){
    if(front == rear)
        printf("Underflow\n");
    else{
        queue[front] = 0;
        front = front + 1;
    }
}

int GetFront(int queue[], int front){
    return queue[front];
}

int GetRear(int queue[], int rear){
    return queue[rear-1];
}


int main() {


    return 0;
}