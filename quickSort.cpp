#include <iostream>
#include <chrono> // Required for high-resolution clock
using namespace std;
using namespace std::chrono;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            // int temp = arr[i];
            // arr[i] = arr[j];
            // arr[j] = temp;
            swap(arr[i], arr[j]);
        }
    }
    // int temp = arr[i + 1];
    // arr[i + 1] = arr[high];
    // arr[high] = temp;
    swap(arr[high], arr[i + 1]);
    return i + 1;
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
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    auto start = high_resolution_clock::now();

    // int arr[] = {4, 3, 7, 9, 11, 12};
    int arr[]={5, 0, 21, 18, 56, 70, 64, 51, 88, 99, 7, 2, 33};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size - 1);
    cout << "Sorted array: ";
    display(arr, size);
    auto end = high_resolution_clock::now();

    // Calculate duration
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "\nExecution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}