#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *GetNode(int data)
{
    Node *n = new Node();
    n -> data = data;
    n -> left = n -> right = NULL;

    return n;
}

void Insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = GetNode(data);
    }
    else
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (!temp -> left)
            {
                temp -> left = GetNode(data);
                break;
            }
            else
            {
                q.push(temp->left);
            }

            if (!temp->right)
            {
                temp -> right = GetNode(data);
                break;
            }
            else
            {
                q.push(temp -> right);
            }    
        }
    }
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    int currentlevel = 0;
    int nextlevel = 0;
    q.push(root);
    currentlevel += 1;
    while (!q.empty())
    {
        Node *n = q.front();
        q.pop();
        currentlevel--;

        if (n != NULL)
        {
            cout << n -> data << " ";
            if (n -> left != NULL)
            {
                q.push(n->left);
                nextlevel = nextlevel + 1;
            }

            if (n -> left != NULL)
            {
                q.push(n->right);
                nextlevel = nextlevel + 1;
            }
        }
        

        if (currentlevel == 0)
        {
            cout << "\n";
            currentlevel = nextlevel;
            nextlevel = 0;
        } 
    };
}
int main()
{
    Node *root = NULL;
    root = GetNode(10);
    root -> left = GetNode(11);
    root -> left -> left = GetNode(7);
    root -> right = GetNode(9);
    root -> right -> left = GetNode(15);
    root -> right -> right = GetNode(18);
    Insert(root,12);
    LevelOrderTraversal(root);
    
    return 0;
}