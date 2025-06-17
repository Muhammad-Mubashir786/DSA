#include <iostream>
using namespace std;

struct student
{
    int rollNo;
    string name;
    string phoneNo;
};

void display(const student *ptr)
{
    cout << "Name: " << ptr->name << endl;
    cout << "Roll Number: " << ptr->rollNo << endl;
    cout << "Phone Number: " << ptr->phoneNo << endl;
}

int main()
{
    student s;
    s.rollNo = 123;
    s.name = "Muhammad Mubashir";
    s.phoneNo = "12345";
    display(&s);
    return 0;
}
