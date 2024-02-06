#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int rear, front;
    int size;
    int *arr;

public:
    Queue(int capacity)
    {
        arr = new int[capacity];
        size = capacity;
        front = rear = -1;
    }
    void enQueue(int data);
    int deQueue();
    void displayQueue();
};
void Queue::enQueue(int data)
{ //! overflow conditon
    if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front))
    {
        cout << "\nqueue is full";
        return;
    } //! inserting first element
    else if (front == -1)
    {
        front = rear = 0;
        arr[rear] = data;
    } //! if front is blank & rear is reach up to last postion
    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = data;
    } //! if everything okay then enqueue as it's
    else
    {
        rear++;
        arr[rear] = data;
    }
}
int Queue::deQueue()
{ //! underflow condition
    if (front == -1)
    {
        cout << "queue is empty";
        return INT_MIN;
    }
    int item = arr[front];
    arr[front] = -1;
    //! i dont't know why but it should be
    if (front == rear)
    {
        front = -1;
        rear = -1;
    } //! chehck if front reach to last element
    else if (front == size - 1)
        front = 0;
    else //! if not then front++
        front++;

    return item;
}
void Queue::displayQueue()
{
    if (front == -1)
    {
        cout << "queue is Empty";
        return;
    }
    cout << "\nelemnet in the cirular Queue : ";
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        for (int i = front; i < size; i++)
            cout << arr[i] << " ";
        for (int i = 0; i <= rear; i++)
            cout << arr[i] << " ";
    }
}
int main()
{
    Queue q(5);

    // Inserting elements in Circular Queue
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);

    // Display elements present in Circular Queue
    q.displayQueue();

    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.deQueue());
    printf("\nDeleted value = %d", q.deQueue());

    q.displayQueue();

    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);

    q.displayQueue();

    q.enQueue(20);
    return 0;
}
