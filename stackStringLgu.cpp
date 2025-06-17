#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "Stack";
    stack<char> s;

    for (char c : str)
    {
        s.push(c);
    }
    string reversed = "";
    while (!s.empty())
    {
        reversed += s.top();
        s.pop();
    }

    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reversed << endl;

    return 0;
}