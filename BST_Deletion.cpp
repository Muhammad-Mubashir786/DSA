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

    Node* findMin(Node* root){

    }
    
    Node *deletionNode(Node *root, int key)
    {
        if (!root)
            return nullptr;

        if (key < root->data)
        {
            root->left = deletionNode(root->left, key);
            else if (key > root->data)
            {
                root->right = deletionNode(root->right, key);

                // Node with one child or no child
                if (!root->left)
                {
                    Node *temp = root->right;
                    delete root;
                    return temp;
                }
                else if (!root->right)
                {
                    Node *temp = root->left;
                    delete root;
                    return temp;
                }
                // Node with two children
                Node *temp = findMin(root->right);
                root->data = temp->data;
                root->right = deletionNode(root->right, temp->data);
            }
            return root;
        }
        void inorder(Node * root)
        {
            if (root != NULL)
            {
                inorder(root->left);
                cout << root->data << " ";
                inorder(root->right);
            }
        }
    }

    int main()
    {
        BST tree;
        Node *root = nullptr;

        root = tree.insert(root, 50);
        tree.insert(root, 30);
        tree.insert(root, 70);
        tree.insert(root, 40);
        tree.insert(root, 60);

        cout << "Before Deletion (Inorder): ";
        tree.inorder(root);
        cout << "\nDeletion 30...\n";

        root = tree.deletionNode(Node, 30);

        cout << "After Deletion (Inorder): ";
        tree.inorder(root);
        return 0;
    }