#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int val){
        data = val;
        left = right = nullptr;
        height = 1;
    }
};
class AVL {
    public:
        int getHeight(Node* node){
            return node ? node->height : 0;
        }
        int getBalance(Node* node){
            return node ? getHeight(node->left) - getHeight(node->right) : 0;
        }
        Node* rightRotate(Node* y){
            Node* x = y->left;
            Node* T2 = x->right;
            // Perform rotation
            x->right = y;
            y->left = T2;
            // Update heights
            y->height = 1 + max(getHeight(y->left),getHeight(y->right));
            x->height = 1 + max(getHeight(x->left),getHeight(x->right));
            return x;
        }
        Node* leftRotate(Node* x){
            Node* y = x->right;
            Node* T2 = y->left;
            //Rotate
            y->left = x;
            x->right = T2;
            //Update height
            x->height = 1 + max(getHeight(x->left),getHeight(x->right));
            y->height = 1 + max(getHeight(y->left),getHeight(y->right));\
            return y;
        }
};
int main(){
    
    return 0;
}