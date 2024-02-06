#include <bits/stdc++.h>
using namespace std;
int BinarySearch(int arr[], int size, int data)
{
    int low = 0;
    int high = size - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == data)
            return mid;
        if (arr[mid] < data)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "enter the key for binary search";
    int key;
    cin >> key;
    int ans = BinarySearch(arr, size, key);
    if (ans == -1)
        cout << "element is not present";
    else
        cout << "element is present at positon " << ans << " & the element is:-" << arr[ans];
    return 0;
}