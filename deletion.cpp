#include <iostream>
using namespace std;
void deletion(int arr[], int &size, int position)
{
    if (position < 0 || position >= size)
    {
        cout << "Invalid position. Cannot delete." << endl;
        return;
    }

    for (int i = position; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6};
    int size = 6, position = 2;

    deletion(arr, size, position);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
