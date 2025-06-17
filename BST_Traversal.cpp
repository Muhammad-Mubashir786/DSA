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

class BST{
    public:
    void inorder(Node* root){
        if(root){
            inorder(root->left);
            cout<< root->data << " ";
            inorder(root->right);
        }
    }
    void postorder(Node* root){
        if(root){
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
    }
    void preorder(Node* root){
        if(root){
            cout<<root->data<<" ";
            postorder(root->left);
            postorder(root->right);
        }
    }
};
int main(){
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    BST tree;
    cout<<"Inorder: ";
    tree.inorder(root);
    cout<<"\nPreorder: ";
    tree.preorder(root);
    cout<<"\nPostorder: ";
    tree.postorder(root);
    return 0;

}













// Node* insert(Node* root, int value){
//     if(root == NULL){
//         return new Node(value);
//     }
//     if(value < root->data){
//         root->left = insert(root->left,value);
//     }else if(value > root->data){
//         root->right = insert(root->right,value);
//     }
//     return root;
// }
// bool search(Node* root, int value){
//     if(root == NULL){
//         return false;
//     }
//     if(root->data == value){
//         return true;
//     }
//     if(value < root->data){
//         return search(root->left, value);
//     }
//     if(value > root->data){
//         return search(root->right, value);  
//     }
// }

// Node* findMin(Node* root){
//     while(root->left != NULL){
//         root = root->left;
//     }
//     return root;
// }
// Node* deleteNode(Node* root, int value){
//     if(root == NULL){
//         return root;
//     }
//     if(value < root->data){
//         root->left = deleteNode(root->left, value);
//     }
//     if(value > root->data){
//         root->right = deleteNode(root->right, value);
//     }else{
//         //No child
//         if(root->left == NULL && root->right == NULL){
//             delete root;
//             return NULL;
//         }else if(root->left == NULL){ //One child
//             Node* temp = root->right;
//             delete root;
//             return temp;
//         }else if(root->right == NULL){ //One child 
//             Node* temp = root->left;
//             delete root;
//             return temp;
//         }
//         //Two children
//         Node* temp = findMin(root->right);
//         root->data = temp->data;
//         root->right = deleteNode(root->right, temp->data);

//     }
//     return root;
// }
//  void inorder(Node* root){
//     if(root != NULL){
//         inorder(root->left);
//         cout<< root->data << " ";
//         inorder(root->right);
//     }
//  }
// int main(){
//     Node* root = NULL;
//     root = insert(root, 50);
//     insert(root, 30);
//     insert(root, 70);
//     insert(root, 60);
//     insert(root, 40);
//     insert(root, 20);
//     insert(root, 10);
//     cout<< "Inorder traversal of the Binary Search Tree is: ";
//     inorder(root);

//     int searchValue;
//     cout<<"\nEnter a value to search in the BST: ";
//     cin>>searchValue;
//     if(search(root, searchValue)){
//         cout<<searchValue<<" is present in the BST."<<endl;
//     }else{
//         cout<<searchValue<<" is not present in the BST."<<endl;
//     }

//     int deleteValue;
//     cout<<"\nEnter a value to delete from the BST: ";
//     cin>>deleteValue;
//     root = deleteNode(root, deleteValue);
//     cout<<"Inorder traversal after deletion: ";
//     inorder(root);
//     return 0;
// }