#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class BST
{
public:
    Node *insert(Node *root, int val)
    {
        if (!root)
            return new Node(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }
    bool search(Node *root, int key)
    {
        if (!root)
            return false;
        if (root->data == key)
            return true;
        if (key < root->data)
            return search(root->left, key);
        else
            return search(root->right, key);
    }
};
int main()
{
    BST tree;
    Node *root = nullptr;
    root = tree.insert(root, 50);
    tree.insert(root, 30);
    tree.insert(root, 70);
    int key;
    cout << "Enter a value to find in tree: ";
    cin >> key;
    if (tree.search(root, key))
        cout << key << " is found BST: " << endl;
    else
        cout << key << " is not found BST: " << endl;

    return 0;
}