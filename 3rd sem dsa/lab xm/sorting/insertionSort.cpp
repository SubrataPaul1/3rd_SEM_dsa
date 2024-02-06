#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int size)
{
    int key;
    int j;
    for (int i = 1; i < size; i++)
    {
        j = i - 1;
        key = arr[i];
        while (j >= 0 && arr[j] > key) // chechking key element precedssor if greater than moves + 1 position
        {                              //!& if it fails then arr[j+1]= key
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    insertionSort(arr, 5);
    return 0;
}