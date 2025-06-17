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

    // POP
    for (int i = 0; i < size; i++)
    {
        values[i] = mystack.top();
        mystack.pop();
    }

    // Display
    cout<<"Arithematic "
    return 0;
}