#include <bits/stdc++.h>
using namespace std;
//! two structure
//! (1) Qnode for linked list
//! (2) for queue
struct QNode
{
    int data;
    QNode *nxt;
    QNode(int key)
    {
        data = key;
        nxt = NULL;
    }
};
struct Queue
{
    QNode *front, *rear;
    Queue()
    {
        front = rear = NULL;
    }
    void enqueue(int key)
    {
        QNode *temp = new QNode(key);
        if (front == NULL)
            front = rear = temp;
        else
        {
            rear->nxt = temp;
            rear = temp;
        }
    }
    int dequeue()
    {
        if (front == NULL)
            return 0;

        QNode *temp = front;
        front = temp->nxt;
        // delete (temp);
        if (front == NULL)
            rear = NULL;
        return temp->data;
    }
    void print()
    {
        QNode *temp = front;
        while (temp != NULL)
        {
            cout << temp->data;
            temp = temp->nxt;
        }
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
            item = q.dequeue();
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