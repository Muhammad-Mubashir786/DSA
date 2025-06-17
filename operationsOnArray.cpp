#include <iostream>

using namespace std;

void traversal(int arr[], int size) {
    cout << "Elements of array are: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertion(int arr[], int &size, int position, int element, int capacity) {
    if (size >= capacity) {
        cout << "Cannot add element, array is full" << endl;
        return;
    }
    
    if (position < 0 || position > size) {
        cout << "Invalid position" << endl;
        return;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    size++;

    traversal(arr, size);
}

void deletion(int arr[], int &size, int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid position" << endl;
        return;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;

    traversal(arr, size);
}

void searching(int arr[], int size, int key) {
    bool present = false;

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            present = true;
            cout << "Element found at index " << i << endl;
            break;
        }
    }

    if (!present) {
        cout << "Element not in the array" << endl;
    }
}

int main() {
    int choice;
    int size = 10;  // Fixed initial size
    int position = 4, element = 3, capacity = 15, key = 1;
    int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Enter operation:\n1) Insertion\n2) Deletion\n3) Searching\n4) Traversal\n";
    cin >> choice;

    switch (choice) {
        case 1:
            insertion(arr, size, position, element, capacity);
            break;
        case 2:
            deletion(arr, size, position);
            break;
        case 3:
            searching(arr, size, key);
            break;
        case 4:
            traversal(arr, size);
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
