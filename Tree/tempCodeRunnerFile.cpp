#include <iostream>
#include <queue>

using namespace std;


struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *new_Node(int data)
{
    Node *tr = new Node;
    tr -> data = data;
    tr -> left = NULL;
    tr -> right = NULL;

    return tr;
}

void InOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        InOrderTraversal(root -> left);
        cout << root -> data << " ";
        InOrderTraversal(root -> right);
        
    }
    
}

void PreOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        
        cout << root -> data << " ";
        PreOrderTraversal(root -> left);
        PreOrderTraversal(root -> right);
    }  
}

void PostOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        PostOrderTraversal(root -> left);
        PostOrderTraversal(root -> right);
        cout << root -> data << " ";
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

void Release(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *n = q.front();
     
        q.pop();
        
        
        if (n != NULL)
        {
            //cout << n -> data << " ";
            if (n -> left != NULL)
            {
                q.push(n->left);
                //nextlevel = nextlevel + 1;
            }

            if (n -> left != NULL)
            {
                q.push(n->right);
                //nextlevel = nextlevel + 1;
            }
            delete n;
        }
    };

    root = NULL;
}


int main() 
{
    Node * root = new_Node(1);
    root -> left = new_Node(2);
    root -> right = new_Node(3);
    root -> left -> left = new_Node(4);
    root -> right -> left = new_Node(5);
    root -> right -> right = new_Node(6);
    
    
    InOrderTraversal(root);
    cout << endl;
    PreOrderTraversal(root);
    cout << endl;
    PostOrderTraversal(root);
    cout << endl;
    LevelOrderTraversal(root);
    Release(root);

    return 0;
}