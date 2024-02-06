#include <bits/stdc++.h>
using namespace std;
void bubble(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void insertion(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int min = arr[i];
        while (j >= 0 && arr[j] > min)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = min;
    }
}
void selection(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int key = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[key])
                key = j;
        }
        if (key != i)
            swap(arr[i], arr[key]);
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
        arr[i] = temp[i - low];
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
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int left = low;
    int right = high;
    while (left < right)
    {
        while (arr[left] <= pivot && left <= high - 1)
            left++;
        while (arr[right] >= pivot && right >= low + 1)
            right--;
        if (left < right)
            swap(arr[left], arr[right]);
    }
    swap(arr[right], arr[low]);
    return right;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void heapify(int arr[], int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 1;
    while (l < size && arr[l] > arr[largest])
        largest = l;
    while (r < size && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}
void heapsort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main()
{
    int arr[] = {9, 2, 0, 8, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    selection(arr, 5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
}
