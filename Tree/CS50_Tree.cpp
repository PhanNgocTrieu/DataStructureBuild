#include <iostream>

using namespace std;
//binary search tree!
typedef struct TREE
{
    int number;
    struct TREE *left;
    struct TREE *right;
}
TREE;

TREE *GetTree(int number)
{
    TREE *newtree = new TREE;
    newtree -> number = number;
    newtree -> left = newtree -> right = NULL;
    return newtree;
}


TREE* Adding_Tree(struct TREE *&root, int number)   //number = value;
{
    TREE *tree = new TREE();
    tree -> number = number;
    tree -> left = NULL;
    tree -> right = NULL;
    if (root == NULL)
    {    
        root = GetTree(number);
       
    }
    else
    {
        if (number <= root -> number)
        {
            root -> left = Adding_Tree(root->left,number);
        }
        else if (number > root -> number)
        {
            root -> right = tree;
        }
        else
        {
            root -> right = Adding_Tree(root->right,number);
        }
    }
    return root;
}   

 

bool search(TREE *root, int number)
{
    if (root == NULL)
    {
        return false;
    }
    else
    {
        if (root -> number == number)
        {
            return true;
        }
        else if (number <= root -> number)
        {
            return search(root -> left, number);
        }
        else
        {
            return search(root -> right, number);
        }  
    }
}

void PrintInOrder(TREE *root)
{
    if (root == NULL)
        return;
    TREE *run = root;
    PrintInOrder(run -> left);
    cout << run -> number << " ";
    PrintInOrder(run -> right);
}  

int main()
{
    TREE *root = NULL;

    Adding_Tree(root,4);
    Adding_Tree(root,5);
    Adding_Tree(root,6);
    Adding_Tree(root,7);
    Adding_Tree(root,8);
    Adding_Tree(root,3);
    Adding_Tree(root,2);

    PrintInOrder(root);
    return 0;
}