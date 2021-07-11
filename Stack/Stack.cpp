#include <iostream>
#include <iostream>

using namespace std;

int current_size = -1;
const int MAX_SIZE = 100;
int stack[MAX_SIZE];

bool isEmpty(){ //Kiem tra stack rong hay k?
    return (current_size == -1);
}

bool isFull() {
    return (current_size == MAX_SIZE);
}

void push(int data){ //them du lieu vao stack

    //kiem tra stack da day hay chua roi moi push data vao
    if (!isFull()) 
    {
        current_size++; //tang kich co len 1 de truyen vao stack;
        stack[current_size] = data; //truyen du lieu vao stack;
    }
    else
    {
        cout << "Stack full" << endl;
    }
       
}

int top() { // peek(): lay phan tu top nhung k xoa
    if (!isEmpty())
    {
        int data = stack[current_size];
        return data;
    }
    else
    {
        cout << "Stack is Empty!" << endl;
    }
    
}

int pop() { // lay phan tu top va xoa khoi stack
     if (!isEmpty())
    {
        int data = stack[current_size];
        current_size--;
        return data;
    }
    else
    {
        cout << "Stack is Empty!" << endl;
    }
}


int main() {

    push(100);
    push(-255);
    push(-25);

    cout << "TOP: " << top() << endl;
    pop();
    cout << "TOP: " << top() << endl;

    while (!isEmpty())
    {
        int data = pop();
        cout << data << " <-- ";
    }
    
    cout << endl;
    

    return 0;
}

