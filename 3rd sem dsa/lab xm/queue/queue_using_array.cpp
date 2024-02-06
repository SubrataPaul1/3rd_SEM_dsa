#include <bits/stdc++.h>
using namespace std;
#define Max 100
class Queue
{
    int *queue;

public:
    int front, rear, capacity;
    Queue(int size)
    {
        front = rear = 0;
        capacity = size;
        queue = new int[capacity];
    }
    ~Queue()
    {
        delete[] queue;
    }
    bool enqueue(int element);
    int dequeue();
    bool isEmpty();
    void print();
};
bool Queue::enqueue(int element)
{
    if (capacity == rear)
    {
        cout << "overflow";
        return false;
    }
    queue[rear++] = element;
    return false;
}
int Queue::dequeue()
{
    if (front == rear)
    {
        cout << "underflow";
        return 0;
    }
    int item = queue[front];
    front++;
    return item;
}
bool Queue::isEmpty()
{
    return front != rear;
}
void Queue::print()
{
    for (int i = front; i < rear; i++)
    {
        cout << queue[i] << " ";
    }
}
int main()
{
    int choice, item;
    Queue q(Max);
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
