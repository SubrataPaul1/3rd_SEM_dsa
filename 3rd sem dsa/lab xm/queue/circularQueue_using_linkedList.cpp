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
struct Queue
{
    Qnode *front, *rear;
    Queue()
    {
        front = rear = NULL;
    }
    void enqueue(int data)
    {
        Qnode *temp = new Qnode(data);
        if (front == NULL && rear == NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->nxt = temp;
            temp->nxt = front;
            rear = temp;
        }
    }
    int dequeu()
    {
        if (rear == NULL && front == NULL)
        {
            cout << "empty queue";
            return -1;
        }
        else
        {

            int value = front->data;
            front = front->nxt;
            rear->nxt = front;
            return value;
        }
    }
    void print()
    {
        Qnode *temp;
        temp = front;
        while (temp->nxt != front)
        {
            cout << temp->data << " ";
            temp = temp->nxt;
        }
        cout << temp->data << " ";
    }
};
int main()
{
    int choice, item;
    Queue q;
    while (1)
    {
        printf("\n1.enQueue\n");
        printf("2.dequeu\n");
        printf("3.Display all Stack elements\n");
        printf("4.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the item to be add : ");
            scanf("%d", &item);
            q.enqueue(item);
            break;
        case 2:
            item = q.dequeu();
            printf("\nPopped item is : %d\n", item);
            break;
        case 3:
            q.print();
            break;
        case 4:
            exit(1);
        default:
            printf("\nWrong choice\n");
        } /*End of switch*/
    }     /*End of while*/

    return 0;
}