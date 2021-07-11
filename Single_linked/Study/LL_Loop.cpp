#include <iostream>
using namespace std;


struct Node {
	int data;
	Node *next;
};


void Add_back(Node *&L, int value)
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
        Node *k = L;
        while (k != NULL && k ->next != NULL)
        {
            k = k->next;
        }
        k->next = n;        
    }
}


void ADD_LOOP(Node *&L, int pos)
{
    if (L == NULL)
    {
        return;
    }
    else
    {


        Node *pos_loop = L;
        int t = 0;

        
        
        while (t < pos - 1) // pos of loop
        {
            pos_loop = pos_loop -> next;
            t++;
        }
        
        Node *run = L;
        while (run != NULL && run -> next != NULL)
        {
            run = run -> next;
        }

        run -> next = pos_loop -> next;
        
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
        Node *k = L;
        for (Node *run = L; run != NULL; run = run->next)
        {
            cout << run -> data << "->";
        }
        
        cout << endl;
        
    }
    
}

int Check_Loop(Node *L)
{
    Node *Slowstep = L;
    Node *Faststep = L;

    if (L == NULL)
    {
        return 0;
    }
    else
    {
        
        while (Faststep && Faststep && Faststep -> next)
        {
            Slowstep = Slowstep -> next;
            Faststep = Faststep -> next -> next;

            if (Slowstep == Faststep)
            {
                return 1;
            }
            
        }
        return 0;
    }
}

int main() {
	// your code goes here
	Node *L = NULL;
    Node *L_Loop = NULL;
	
    Add_back(L,5);
	Add_back(L,5);
    Add_back(L,5);
	Add_back(L,5);

//Loop:
    Add_back(L_Loop,5);
	Add_back(L_Loop,5);
    Add_back(L_Loop,5);
	Add_back(L_Loop,5);


    cout << "This is linked L: " << endl;
    Print(L);
    //Print(L_Loop);

    cout << "Could not print Loop_linked because of Time limit exceeded!" << endl;
    ADD_LOOP(L_Loop,3);
    //Print(L);

    cout << "Checking L_linked!" << endl;
    if (Check_Loop(L) == true)
    {
        cout << "Loop Found" << endl;
    }
    else
    {
        cout << "No Loop" << endl;
    }


    cout << "checking L_Loop Linked!" << endl;
    if (Check_Loop(L_Loop) == true)
    {
        cout << "This is loop linked!" << endl;
    }
    else
    {
        cout << "This is not loop linked!" << endl;
    }
    return 0;
}