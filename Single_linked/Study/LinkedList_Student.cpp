#include <iostream>
using namespace std;

struct Student
{
	int id;
	Student * next;
};

void Add(Student *&L, int ID)
{
	if (L == NULL)
	{
		Student *l = new Student;
		l -> id = ID;
		L = l;
	}
	else
	{
		Student *ll = new Student;
		ll -> id = ID;
		
		Student * p = L;
		// move p to end of L
		
		while (p != NULL && p -> next != NULL)
		{
			p = p -> next;
		}
		
		p -> next = ll;
	}
}

void DeleteHead(Student *&L)
{
	if (L == NULL)
	{
		return;
	}
	else
	{
		Student *pre_p;
		pre_p = L;
		L = L -> next;
		delete pre_p;
	}
}

void Delete(Student *&L, int ID)
{
	if (L == NULL)
	{
		return;
	}
	else
	{
		if (L->id == ID)
		{
			DeleteHead(L);
		}
		else
		{
			Student *pre_p;
			Student *k;
			for (k = L; k != NULL && k->id != ID; k = k->next)
			{
				pre_p = k;
			}
			
			cout << pre_p->id << endl;
			cout << k->id << endl;
			
			pre_p -> next = k -> next;
			delete k;
			
		}
	}
}

int Count(Student *L)
{
	int n = 0;
	
	if (L == NULL)
	{
		return 0;
	}
	else
	{
		Student *ptr;
		ptr =  L;
		while (ptr != NULL)
		{
			n++;
			ptr = ptr -> next;
		}
		return n;
	}
}

void Print(Student *L)
{	
	if (L == NULL)
	{
		return;
	}
	
	for (Student *k = L; k !=NULL ; k = k -> next)
	{
		cout << k -> id << " ";
	}
	cout << endl;
}

int main() {
	Student * L = NULL;
	Add(L, 1);
	Add(L, 2);
	Add(L, 3);
	Add(L, 4);
	Add(L, 5);
	
	Print(L);
	Delete(L, 3);
	Print(L);
	cout << Count(L);
	
	return 0;
}