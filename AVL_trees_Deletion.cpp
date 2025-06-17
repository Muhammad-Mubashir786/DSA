#include <iostream>
using namespace std;
// Node structure for AVL tree
struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};
// Utility func to get height of the tree
int height(Node *node)
{
    return node ? node->height : 0;
}
// Utility func to get max of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}
// Create node
Node *createNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}
// Right rotate subtree rooted with y
Node *rightRotate(Node *y)
{                        //                                      Tree
    Node *x = y->left;   //                                       y -> parent
    Node *T2 = x->right; //                                    </
                         //                                       x -> child
                         //                                      </
                         //                                     T2 -> leaf
    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update height
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // return new root
    return x;
}
// Left rotate subtree rooted with x
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update height
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // return new root
    return y;
}

// Get balance factor o node
int getBalance(Node *node)
{
    if (!node)
        return 0;
    return height(node->left) - height(node->right);
}

// Find node with maximum key val in subtree rooted at node
Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current->left != nullptr)
    {
        current = current->left;
    }
}
Node *deleteNode(Node *root, int key)
{

    // step 1 standard BST deletion
    if (root == nullptr)
    {
        return root;
    }

    // if key to delete is small than root key, goto left subtree
    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    // if key to delete is greater than root key, goto right subtree
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // key == root->key, deleted node

        // Node with 1 or no child
        if ((root->left == nullptr) || (root->right == nullptr))
        {
            Node *temp = root->left ? root->left : root->right;
            // No child
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else               // 1 child
                *root = *temp; // copy content
            delete temp;
        }
        else
        {
            // Node  with 2 children
            // get inorder successor (smallest right subtree)
            Node *temp = minValueNode(root->right);

            // copy successor key to current node
            // delete inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }
    // if tree had 1 node
    if (root == nullptr)
    {
        return root;
    }
    // step 2 update height
    root->height = 1 + max(height(root->left), height(root->right));

    // step 3 get balance factor
    int balance = getBalance(root);

    // step 4 balance tree
    //  left left case
    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }
    // left RIGHT case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right RIGHT case
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }
    // Right left case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
// helper function to print inorder traversal of the tree
void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
int main()
{
    Node *root = nullptr;
    // Example insertion (manually build AVL orr use insert code)
    root = createNode(9);
    root->left = createNode(5);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(6);

    // Set height manually (or compute properly)
    root->height = 3;
    root->left->height = 2;
    root->right->height = 1;
    root->left->left->height = 1;
    root->left->right->height = 1;

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 10);

    cout << "Inorder traversal after deletion of 10: ";
    inorder(root);
    cout << endl;
    return 0;
}