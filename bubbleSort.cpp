#include <iostream>
using namespace std;
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // int temp = arr[j];
                // arr[j] = arr[j + 1];
                // arr[j + 1] = temp;
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            cout<<"\nAlready sorted";
            return;
        }
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
    // int arr[] = {3, 8, 5, 2, 1};
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Before sorting: ";
    display(arr, size);
    bubbleSort(arr, size);
    cout << "\nAfter bubble sorting: ";
    display(arr, size);
    return 0;
}