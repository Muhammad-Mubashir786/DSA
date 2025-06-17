#include <iostream>
using namespace std;
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {8, 5, 6, 4, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Before applying insertion sort: ";
    display(arr, size);
    insertionSort(arr, size) ;
    cout << "\nAfter applying insertion sort: ";
    display(arr, size);
    return 0;
}