#include <iostream>
using namespace std;
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
        Node(int val)
        {
            data = val;
            next = nullptr;
            prev = nullptr;
        }
    };
    void printForward(Node *head)
    {
        Node *temp = head;
        cout << "Forward: ";
        while (temp != nullptr)
        {
            cout << temp->data << "<->";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
    void printBackward(Node *tail)
    {
        Node *temp = tail;
        cout << "Backward: ";
        while (temp != nullptr)
        {
            cout << temp->data << "<->";
            temp = temp->prev;
        }
        cout << "Null" << endl;
    }
    int main()
    {
        Node *head = new Node(1);
        Node *second = new Node(2);
        head->next = second;
        second->prev = head;
        Node *third = new Node(3);
        second->next = third;
        third->prev = second;
        printForward(head);
        printBackward(third);
        return 0;
    }
