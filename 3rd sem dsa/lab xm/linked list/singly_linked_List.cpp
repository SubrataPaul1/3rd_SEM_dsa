#include <bits/stdc++.h>
using namespace std;
struct Qnode
{
    int data;
    Qnode *nxt;
    Qnode(int key)
    {
        data = key;
        nxt = NULL;
    }
};
struct singelLinkedList
{
    Qnode *head;
    singelLinkedList()
    {
        head = NULL;
    }

    void add(int data)
    {
        Qnode *newNode = new Qnode(data);
        if (head == NULL)
        {
            head = newNode;
            newNode->nxt = NULL;
            cout << newNode->data;
        }
        else
        {
            Qnode *temp = head;
            while (temp->nxt != NULL)
            {
                temp = temp->nxt;
            }
            temp->nxt = newNode;
            newNode->nxt = NULL;
        }
        cout << "item added" << newNode->data << endl;
        return;
    }
    int from_Delete_last()
    {
        Qnode *temp = head;
        while (temp->nxt->nxt != NULL)
        {
            temp = temp->nxt;
        }
        int item = temp->nxt->data;
        temp->nxt = NULL;
        return item;
    }
    void display()
    {
        Qnode *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->nxt;
        }
    }
};
int main()
{
    singelLinkedList sll;
    int choice, item;
    while (1)
    {
        printf("\n1.add\n");
        printf("2.delete\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the item to be add : ");
            scanf("%d", &item);
            sll.add(item);
            break;
        case 2:
            item = sll.from_Delete_last();
            printf("\nPopped item is : %d\n", item);
            break;
        case 3:
            sll.display();
            break;
        case 4:
            exit(1);
        default:
            printf("\nWrong choice\n");
        } /*End of switch*/
    }     /*End of while*/

    return 0;
}