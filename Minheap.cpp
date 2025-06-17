#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
private:
    vector<int> heap;

    void heapifyUp(int index)
    {
        // get index of parent node
        int parent = (index - 1) / 2;

        // not at root and current node is greater than parent
        while (index > 0 && heap[index] < heap[parent])
        {
            // swap current node with parent
            // this will ensure that the max heap property is maintained
            swap(heap[index], heap[parent]);

            // move index up
            index = parent;
            parent = (index - 1) / 2;
        }
    }

public:
    void insert(int value)
    {
        // add value to the end of the heap
        heap.push_back(value);

        // heapify up to maintain max heap property
        heapifyUp(heap.size() - 1);
    }

    void printHeap()
    {
        cout << "Max Heap: ";
        // for (int i = 0; i < heap.size(); i++)
        // {
        //     cout << heap[i] << " ";
        // }
        for (int val : heap)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};
int main()
{
    MaxHeap h;

    // insert value into heap
    h.insert(10);
    h.printHeap();

    h.insert(20);
    h.printHeap();

    h.insert(5);
    h.printHeap();

    h.insert(30);
    h.printHeap();

    h.insert(15);
    h.printHeap();

    return 0;
}