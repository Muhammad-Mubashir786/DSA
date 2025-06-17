#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

// Utility to display array
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Bubble Sort
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// Selection Sort
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

// Insertion Sort
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

// Merge Sort
void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1, n2 = high - mid;
    int *left = new int[n1], *right = new int[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    delete[] left;
    delete[] right;
}
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
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

int main()
{
    int original[] = {5, 0, 21, 18, 56, 70, 64, 51, 88, 99, 7, 2, 33, 12, 27, 91, 3, 8, 41, 81, 100, 6, 29, 20, 66};
    int size = sizeof(original) / sizeof(original[0]);

    int temp[size];

    // Bubble Sort
    copy(original, original + size, temp);
    auto start = high_resolution_clock::now();
    bubbleSort(temp, size);
    auto end = high_resolution_clock::now();
    cout << "Bubble Sort Time: " << duration_cast<microseconds>(end - start).count() << " µs\n";

    // Selection Sort
    copy(original, original + size, temp);
    start = high_resolution_clock::now();
    selectionSort(temp, size);
    end = high_resolution_clock::now();
    cout << "Selection Sort Time: " << duration_cast<microseconds>(end - start).count() << " µs\n";

    // Insertion Sort
    copy(original, original + size, temp);
    start = high_resolution_clock::now();
    insertionSort(temp, size);
    end = high_resolution_clock::now();
    cout << "Insertion Sort Time: " << duration_cast<microseconds>(end - start).count() << " µs\n";

    // Merge Sort
    copy(original, original + size, temp);
    start = high_resolution_clock::now();
    mergeSort(temp, 0, size - 1);
    end = high_resolution_clock::now();
    cout << "Merge Sort Time: " << duration_cast<microseconds>(end - start).count() << " µs\n";

    // Quick Sort
    copy(original, original + size, temp);
    start = high_resolution_clock::now();
    quickSort(temp, 0, size - 1);
    end = high_resolution_clock::now();
    cout << "Quick Sort Time: " << duration_cast<microseconds>(end - start).count() << " µs\n";

    return 0;
}
