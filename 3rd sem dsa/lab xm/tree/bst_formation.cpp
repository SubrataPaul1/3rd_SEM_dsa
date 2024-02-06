#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *getNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node *levelOrder(Node *root, int data)
{
    if (root == NULL)
    {
        root = getNode(data);
        return root;
    }
    if (data <= root->data)
    {
        root->left = levelOrder(root->left, data);
    }
    else
    {
        root->right = levelOrder(root->right, data);
    }
    return root;
}
Node *constructBst(int arr[], int size)
{
    if (size == 0)
        return 0;
    Node *root = NULL;
    for (int i = 0; i < size; i++)
    {
        root = levelOrder(root, arr[i]);
    }
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    inorder(root->left);
    inorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    inorder(root->right);

    cout << root->data << " ";
}
int main()
{
    int arr[] = {5, 6, 7, 91, 1, 0, 35, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node *root = constructBst(arr, size);
    cout << "inorder traversal ";
    preorder(root);
    return 0;
}

//! algorithm for bst formation
// todo contruct a tree structure & getNode func
// s1:- form main function call a *CONSTRUCT_BINARY_SEARCH_TREE FUNCTION
// S2:- from that function if given array element is null then return NULL node
// s3:- if not null then call a function in a for loop (*LEVEL_ORDER) by // ? root & arr[i]
// s4:- in levelorder initially construct a root node //? if not initilize
// s5:- if data > left.data then call the function(*levelorder(root.left,data)) if it isn't then call right children then return the root
// s6:- return the root
//? for chechk make a inorder traversal func