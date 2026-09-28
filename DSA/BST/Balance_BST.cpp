#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node * left;
    Node * right;

    Node(int data){
        this->data = data;
        left = right =  NULL;
    }

};

vector<Node*>ans;
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    ans.push_back(root);
    inorder(root->right);
    
}

Node* buildfromsorted(int start,int end){
    if(start > end){
        return NULL;
    }
    int mid = start + (end-start)/2;
    Node* curr =  ans[mid];
    curr->left = buildfromsorted(start,mid-1);
    curr->right = buildfromsorted(mid+1,end);
    return curr; 
}

Node* balanceBST(Node* root){
    inorder(root);
    return buildfromsorted(0,ans.size()-1);
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}


int main(){
    Node* root =  new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);
    root = balanceBST(root);
    preorder(root);
    return 0;
}