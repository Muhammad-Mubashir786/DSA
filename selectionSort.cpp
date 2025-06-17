#include <iostream>
#include <chrono> // Required for high-resolution clock
using namespace std;
using namespace std::chrono;
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i; // smallest idex
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            // int temp = arr[i];
            // arr[i] = arr[minIndex];
            // arr[minIndex] = temp;
            swap(arr[i], arr[minIndex]);
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
    auto start = high_resolution_clock::now();
    int arr[] = {5, 0, 21, 18, 56, 70, 64, 51, 88, 99, 7, 2, 33};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    display(arr, size);
    selectionSort(arr, size);
    cout << "\nSorted array: ";
    display(arr, size);
    auto end = high_resolution_clock::now();

    // Calculate duration
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "\nExecution time: " << duration.count() << " milliseconds" << endl;

    return 0;
}