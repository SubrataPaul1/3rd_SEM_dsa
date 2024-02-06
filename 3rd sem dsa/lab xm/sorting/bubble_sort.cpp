#include <bits/stdc++.h>
using namespace std;
void bubblesort(int arr[], int size)
{
    bool swaP;
    for (int i = 0; i < size; i++)
    {
        swaP = false;
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swaP = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (!swaP)
            break;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {5, 4, 2, 1, 0};
    bubblesort(arr, 5);
}