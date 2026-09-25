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

Node * insert(Node * root,int val){
    if(root==NULL){
        root = new Node(val);
        return root;
    }

    if(val>root->data){
        root->right = insert(root->right,val);
    }else{
        root->left = insert(root->left,val);
    }

    return root;

}

Node * BuildBST(int arr[],int size){
    Node * root =  NULL;

    for(int i=0;i<size;i++){
        root = insert(root,arr[i]);
    }
    return root;
}

void inorder(Node*root){
    if(root == NULL){
        return; 
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    int arr[6] = {5,1,3,4,2,7};

    Node * root = BuildBST(arr,6);
    inorder(root);
    cout<<endl;
    return 0;
}