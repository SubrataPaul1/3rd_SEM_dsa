#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[j] >= pivot && j >= low + 1)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[low]);
    return j;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
void merge(int arr[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int k = 0;
    int temp[low + high];
    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
            temp[k++] = arr[left++];
        else
            temp[k++] = arr[right++];
    }
    while (left <= mid)
        temp[k++] = arr[left++];

    while (right <= high)
        temp[k++] = arr[right++];

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void mergesort(int arr[], int low, int high)
{

    if (low == high)
        return;
    int mid = (low + high) / 2;

    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void bubble(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j + 1], arr[j]);
        }
    }
}
void selection(int arr[], int size)
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
void insertion(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[] = {1, 0, 9, 6, 3, 2};
    insertion(arr, 6);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    return 0;
}