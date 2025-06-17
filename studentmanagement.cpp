#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct student {
    int rollNo;
    string name;
    string phoneNo;
};

void inputStudent(student *s) {
    cout << "Enter roll number: ";
    cin >> s->rollNo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  

    cout << "Enter name: ";
    getline(cin, s->name);

    cout << "Enter phone number: ";
    getline(cin, s->phoneNo);
}

void display(const student *s) {
    cout << "\nStudent Details:\n";
    cout << "Roll No: " << s->rollNo << endl;
    cout << "Name: " << s->name << endl;
    cout << "Phone No: " << s->phoneNo << endl;
}


void searchStudentByRoll(const vector<student> &students, int roll) {
    bool found = false;
    for (const auto &s : students) {
        if (s.rollNo == roll) {
            display(&s);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student with roll No: " << roll << " not found.\n";
    }
}

int main() {
    vector<student> students;
    int choice;

    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                student newStudent;
                inputStudent(&newStudent);
                students.push_back(newStudent);
                break;
            }
            case 2:
                if (students.empty()) {
                    cout << "No students available.\n";
                } else {
                    for (const auto &s : students) {
                        display(&s);
                    }
                }
                break;
            case 3: {
                int roll;
                cout << "Enter roll number to search: ";
                cin >> roll;
                searchStudentByRoll(students, roll);
                break;
            }
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
