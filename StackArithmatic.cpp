#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int values[] = {10, 20, 30, 40, 50};
    int size = sizeof(values) / sizeof(values[0]);

    stack<int> mystack;

    // Push 
    for (int i = 0; i < size; i++)
    {
        mystack.push(values[i]);
    }

    // Pop 
    for (int i = 0; i < size; i++)
    {
        values[i] = mystack.top();
        mystack.pop();
    }

    // Arithmetic 
    int sum = 0;
    int product = 1;

    for (int i = 0; i < size; i++)
    {
        sum += values[i];     
        product *= values[i]; 
    }

   
    cout << "Arithmetic Operations: " << endl;
    cout << "Sum of elements: " << sum << endl;
    cout << "Product of elements: " << product << endl;

    return 0;
}
