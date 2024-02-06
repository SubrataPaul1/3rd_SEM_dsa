#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int size)
{
    int min;
    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
            swap(arr[i], arr[min]);
    }
}
int main()
{
    int arr[] = {5, 0, 3, 2, 1};
    selectionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}
