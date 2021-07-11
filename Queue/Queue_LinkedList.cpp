#include <iostream>


using namespace std;
struct NODE {
    int data;
    NODE *next;
};
typedef struct NODE *queue;

bool isEmpty(queue q) {
    return q == NULL;
}

NODE *createNODE(int data){
    NODE *p = new NODE();
    if (p == NULL)
    {
        return p;
    }
    p -> next = NULL;
    p -> data = data;
}
void enQueue(queue &q, int data) {
    NODE *p = createNODE(data);
    if (q == NULL)
    {
        q = p;
    }
    else
    {
        NODE *p_rear = q;
        while (p_rear != NULL && p_rear -> next != NULL) // tim node cuoi cung
        {
            p_rear = p_rear->next;
        }
        // p_rear chinh la phan tu cuoi cung cua queue
        p_rear -> next = p;
    }
}

int Peek(queue q) {
    if (!isEmpty(q))
    {
        return q->data;
    }
    else
    {
        return 0;
    } 
}

int deQueue(queue &q) { //xoa phan tu dau tien
    if (!isEmpty(q))
    {
        int data = q -> data;
        NODE *p = q;
        q = q -> next;
        delete(p);
        return data;
    }
    else
    {
        return 0;
    } 
}

int main(){

    queue q = NULL;
    enQueue(q,10);
    enQueue(q,100);
    enQueue(q,1000);
    enQueue(q,10000);
    enQueue(q,100000);
    enQueue(q,12);
    enQueue(q,102);

    cout << "Queue rong? " << isEmpty(q) << endl;

    cout << "Fist Element of QUEUE? " << Peek(q) << endl;

    while (!isEmpty(q))
    {
        int data = Peek(q);
        deQueue(q);
        cout << " " << data << " <- ";
    }

    cout << "\nQUEUE rong? " << isEmpty(q) << endl;
    
    

    return 0;
}
