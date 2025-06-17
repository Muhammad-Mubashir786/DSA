#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int values[] = {10, 20, 30, 40, 50};
    int size = sizeof(values) / sizeof(values[0]);

    stack<int> mystack;

    for (int i = 0; i < size; i++)
    {
        mystack.push(values[i]);
        cout << "Pushed " << values[i] << " into the stack" << endl;
    }

    cout << "\nStack content (LIFO order): " << endl;
    while (!mystack.empty())
    {
        cout << "Top element: " << mystack.top() << endl;
        mystack.pop();
    }

    return 0;
}