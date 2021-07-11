#include <iostream>
#include <queue>
using namespace std;

struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
};

Tree *Push(int value)
{
    Tree *root = new Tree;
    root -> data = value;
    root -> left = root -> right = NULL;

    return root;
}
Tree* insert(Tree* root, int data) 
{ 
    /* If the tree is empty, return a new root */
    if (root == NULL) return Push(data); 
  
    /* Otherwise, recur down the tree */
    if (data < root->data) 
        root->left = insert(root->left, data); 
    else
        root->right = insert(root->right, data); 
  
    /* return the (unchanged) root pointer */
    return root; 
} 

Tree *Search(Tree *root, int value)
{
    if (root != NULL && root -> data == value)
    {
        return root;
    }

    if (root -> left != NULL && value <= root -> data)
    {
        return Search(root->left,value);
    }
    else
    {
        return Search(root->right,value);
    }
}

struct Tree * minValueNode(struct Tree* root) 
{ 
    struct Tree* current = root; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

Tree *deleteTree_keepBalance(Tree *&root, int value)
{
   if (root == NULL)
   {
       return root;
   }
   
   if (value < root -> data)
   {
       root -> left = deleteTree_keepBalance(root -> left, value);
   }
   else if (value > root -> data)
   {
       root -> right = deleteTree_keepBalance(root -> right, value);
   }
   else
   {
       if (root -> left == NULL)
       {
           Tree *tr = root -> right;
           delete root;
           return tr;
       }
       else if (root -> right == NULL)
       {
           Tree *tr = root -> right;
           delete root;
           return tr;
       }
        
       Tree *tr = minValueNode(root -> right);
       
       root -> data = tr -> data;

       root -> right = deleteTree_keepBalance(root -> right, tr -> data);
    }
    return root;
}


void PrintPreOrder(Tree *root)
{
    if (root != NULL)
    {
        cout << root -> data << " ";
        PrintPreOrder(root -> left);
        PrintPreOrder(root -> right);
    }
}

void LevelOrderTraversal(Tree *root)
{
    queue<Tree *> q;
    int currentlevel = 0;
    int nextlevel = 0;
    q.push(root);
    currentlevel += 1;
    while (!q.empty())
    {
        Tree *n = q.front();
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

            if (n -> right != NULL)
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
    Tree *root = NULL;
    root = Push(50);
    root -> left = Push(30);
    root -> right = Push(70);
    root -> left -> left = Push(20);
    root -> left -> right = Push(40);
    root -> right -> left = Push(60);
    root -> right -> right = Push(80);

    //Search(root, 20);
    if (Search(root,80))
    {
        cout << "Found " << endl;
    }
    
    //PrintPreOrder(root);
    cout << "\nROOT 1:" << endl;
    LevelOrderTraversal(root);

    deleteTree_keepBalance(root,50);
    PrintPreOrder(root);
    cout << "\nROOT 1:" << endl;
    LevelOrderTraversal(root);
    return 0;
}