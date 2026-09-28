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

Node* buildfromsorted(int arr[],int start,int end){
    if(start > end){
        return NULL;
    }
    int mid = start + (end-start)/2;
    Node* curr =  new Node(arr[mid]);
    curr->left = buildfromsorted(arr,start,mid-1);
    curr->right = buildfromsorted(arr,mid+1,end);
    return curr; 
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
    int arr[7] = {3,4,5,6,7,8,9};
    Node * root = buildfromsorted(arr,0,6);
    preorder(root);
    return 0;
}