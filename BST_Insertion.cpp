#include<iostream>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int value){
    //empty tree, create new node
    if(root == NULL){
        return new Node(value);
    }
    //Value less, insert in left node
    if(value < root->data){
        root->left = insert(root->left,value);
    }
    //Value right, insert in right node
    else if(value > root->data){
        root->right = insert(root->right,value);
    }
    //Duplicate values not inserted in subtree
    return root;
}

 void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        cout<< root->data << " ";
        inorder(root->right);
    }
 }

int main(){
    Node* root = NULL;
    int n, value;

    cout<<"Enter number of elements to insert in BST: ";
    cin>>n;
    
    cout<<"Enter "<<n<<" values:\n";
    cin>>value;

    for(int i = 0; i<n; i++){
        cin>>value;
        root = insert(root, value);
    }

    cout<<"Inorder traversal of BST (sorted order): ";
    inorder(root);
    cout<<endl;
    return 0;
}