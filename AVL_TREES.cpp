#include <iostream>
using namespace std;
struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};

int height(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}
// balance factor
int getBalance(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}
// maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}
// right rotate subtree with y
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // perform rotation
    x->right = y;
    y->left = T2;

    // update height
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // return new root
    return x;
}

// left rotate subtree with rooted x
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // perform rotation
    y->left = x;
    x->right = T2;

    // update height
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // return new root
    return y;
}

Node *createNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->right = nullptr;
    node->left = nullptr;
    node->height = 1; // new node is at leaf node
    return node;
}

// recursive func to insert and balance key
Node *insert(Node *node, int key)
{
    // BST insertion
    if (node == nullptr)
    {
        return (createNode(key));
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else // equal key not allowed
        return node;

    // update height of ancestor
    node->height = 1 + max(height(node->left), height(node->right));

    // get balance factor
    int balance = getBalance(node);

    // LL case
    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    //RR case
    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    // LR case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RL case
    if (balance < -1 && key > node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
// inorder
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

    // insert values
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 40);
    root = insert(root, 50);

    cout << "Inorder traversal of AVL tree:\n";
    inorder(root);
    cout << endl;

    return 0;
}