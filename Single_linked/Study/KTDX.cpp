#include <iostream>
using namespace std;



struct Node {
	int value;
	Node *next;
};

void Add_back(Node *&L,int value)
{
	Node *l = new Node;
	l -> value = value;
	l -> next = NULL;
	
	if (L == NULL)
	{	
		L = l;
	}
	else
	{
		Node *ptr;
		ptr = L;
		while (ptr -> next != NULL)
		{
			ptr = ptr -> next;
		}
		
		ptr -> next = l;
	}
}

void Print(Node *L)
{
	Node *k;
	for (k = L; k != NULL; k = k->next)
	{
		cout << k -> value;
	}
	cout << endl;
}


int Count(Node *L)
{
	int n = 1;
	if (L == NULL)
	{
		return 0;
	}
	else
	{
		Node *pre = L;
		while (pre -> next != NULL)
		{
			n++;
			pre = pre -> next;
		}
		return n;
	}
}

int GetNode(Node *L, int kth)
{
	Node *pre = L;
	if (kth > Count(L))
	{
		return 0;
	}
	else
	{
		
		for (int i = 1; i < kth; i++)
		{
			pre = pre -> next;
		}
		return pre->value;
	}
}

bool CheckDX(Node *L){

    int left = 1;
    int right = Count(L);

    while (left < right)
    {
        
        if (GetNode(L,left) != GetNode(L,right))
        {
            return false;
        }
        left++;
        right--;
    }

    return true;
}




int main() {
	// your code goes here
	Node * L = NULL;
	Add_back(L,1);
	Add_back(L,2);
	Add_back(L,3);
	Add_back(L,2);
	Add_back(L,1);
	
	cout << CheckDX(L) << endl;

	Print(L);
	return 0;
}