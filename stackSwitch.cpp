#include <iostream>
#include <stack>
using namespace std;

int Stack[20], size = 20, level = -1;
void push(int val)
{
    if (level >= size - 1)
    {
        cout << "Stack is already filled" << endl;
    }
    else
    {
        level++;
        Stack[level] = val;
    }
}
void pop()
{
    if (level <= -1)
    {
        cout << "Stack already empty" << endl;
    }
    else
    {
        cout << "The popped element is " << Stack[level] << endl;
        level--;
    }
}

void display()
{
    if (level >= 0)
    {
        cout << "Stack elements are : ";
        for (int i = level; i >= 0; i--)
        {
            cout << Stack[i] << " ";
            cout << endl;
        }
    }
    else
    {
        cout << "Stack is empty";
    }
}
int main()
{
    int ch, val;
    cout << "1) Push in Stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display Stack" << endl;
    cout << "4) Exit" << endl;
    do
    {
        cout << "\nEnter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter value to be pushed: " << endl;
            cin >> val;
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exit " << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (ch != 4);

    return 0;
}