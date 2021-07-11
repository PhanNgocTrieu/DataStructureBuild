#include <iostream>
using namespace std;


//Defination variables:
int top = -1;
const int MAX_SIZE = 100;


//-----------Defination function----
bool isEmpty(int capacity);
bool isFull(int capacity);
void Push(int stack[], int value, int capacity);
void Pop();
int Peek(int stack[]);
int Size();



// Capicity: bien luu kich thuoc (suc chua)

//kiem tra rong
bool isEmpty(){
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

//Checking for being full?
bool isFull(int capacity)
{
    if(top >= capacity - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Adding/push elements on stack
void Push(int stack[], int value, int capacity)
{
    if (isFull(capacity) == true)
    {
        cout << "\nStack is full. Overflow condition!";
    }
    else
    {
        ++top;
        stack[top] == value;
    }
    
}

//Pop/deleting elements from peak of stack:

void Pop() {

    if (isEmpty() == true) 
    {
        cout << "\nStack is empty. Underflow condition!";
    }
    else
    {
          --top;  
    }
}

//taking element from peak of stack:
//Peek or TOP:

int Peek(int stack[]) {
    return stack[top];   
}

int Size() {
    return top + 1;
}

int main() {
    const int capacity = 3 ; 
    int top = -1;
    int stack[capacity];
    
    // pushing element 5 in the stack .
    Push(stack, 5, capacity); 
    
    cout << "\nCurrent size of stack is " << Size();
    
    Push(stack, 10, capacity);
    Push(stack, 24, capacity);
    cout << "\nCurrent size of stack is " << Size();
 
    // As the stack is full, further pushing will show an overflow condition.
    //Push(stack, 12, capacity); 
    
    //Accessing the top element
    cout << "\nThe current top element in stack is " << Peek(stack);
    
    //Removing all the elements from the stack
    for(int i = 0 ; i < 3;i++)
    {  
        Pop();
    }
    cout << "\nCurrent size of stack is " << Size();
    
    //As the stack is empty , further popping will show an underflow condition.
    Pop();  


    //return 0;
}