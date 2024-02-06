#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class Stack
{
    int top;

public:
    int a[MAX];
    Stack()
    {
        top = -1;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    void display();
};
bool Stack::push(int data)
{
    if (top >= MAX - 1)
    {
        cout << "Stack is full";
        return false;
    }
    else
    {
        a[++top] = data;
        cout << data << " element is pushed";
        return true;
    }
}
int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack underflow";
        return -1;
    }
    else
    {
        return a[top--];
    }
}
int Stack::peek()
{
    return a[top];
}
bool Stack::isEmpty()
{
    if (top > 0)
        return true;
    else
        return false;
}
void Stack::display()
{
    for (int i = top; i >= 0; i--)
        printf("%d ", a[i]);
    return;
}
int main()
{
    int choice, item;
    class Stack s;
    while (1)
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Display the top element\n");
        printf("4.Display all Stack elements\n");
        printf("5.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the item to be pushed : ");
            scanf("%d", &item);
            s.push(item);
            break;
        case 2:
            item = s.pop();
            printf("\nPopped item is : %d\n", item);
            break;
        case 3:
            printf("\nItem at the top is : %d\n", s.peek());
            break;
        case 4:
            s.display();
            break;
        case 5:
            exit(1);
        default:
            printf("\nWrong choice\n");
        } /*End of switch*/
    }     /*End of while*/

    return 0;
}