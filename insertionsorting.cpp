#include <iostream>
#include <chrono> // Required for high-resolution clock
using namespace std;
using namespace std::chrono;
void insertionSorting(int arr[], int size)
{

    for (int i = 1; i < size; i++)
    {
        int current = arr[i];
        int previous = i - 1;
        while (previous >= 0 && arr[previous] > current)
        {
            arr[previous + 1] = arr[previous];
            previous--;
        }
        arr[previous + 1] = current;
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
    insertionSorting(arr, size);
    display(arr, size);
    auto end = high_resolution_clock::now();

    // Calculate duration
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "\nExecution time: " << duration.count() << " milliseconds" << endl;

    return 0;
}