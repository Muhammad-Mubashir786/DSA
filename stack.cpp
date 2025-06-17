#include <iostream>
#include <stack> // linear data structure
using namespace std;

int main()
{
    stack<int> mystack;

    mystack.push(5);
    mystack.push(10);
    mystack.push(15);

    if (!mystack.empty())
    {
        cout << "top element of the stack: " << mystack.top() << endl;
    }
    else
    {
        cout << "Stack is empty." << endl;
    }
    cout << "Size of stack after peek: " << mystack.size() << endl;

    mystack.pop();
    
    cout << "Size of stack after peek: " << mystack.size() << endl;

    return 0;
}