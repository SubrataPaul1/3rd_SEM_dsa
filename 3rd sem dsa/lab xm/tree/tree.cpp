#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};
node *getNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
node *levelOrder(node *root, int data)
{
    if (root == NULL)
    {
        root = getNode(data);
        return root;
    }

    if (data <= root->data) //! connect root->left  with new root node
        root->left = levelOrder(root->left, data);
    else
        root->right = levelOrder(root->right, data);
    return root;
}
node *constructBst(int arr[], int size)
{
    if (size == 0)
        return NULL;
    node *root = NULL;
    for (int i = 0; i < size; i++)
    {
        root = levelOrder(root, arr[i]);
    }
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    int arr[] = {0, 9, 8, 1, 3, 2};
    node *root = constructBst(arr, 6);
    cout << "inorder traversal ";
    inorder(root);
    return 0;
}