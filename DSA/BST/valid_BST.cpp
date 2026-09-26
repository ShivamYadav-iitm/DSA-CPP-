#include<iostream>
#include<climits>
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

bool ValidBST(Node*root,Node* min,Node* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<min->data){
        return false;
    }
    if(max!= NULL && root->data>max->data){
        return false;
    }

    return ValidBST(root->left,min,root) 
        && ValidBST(root->right,root,max);
}

int main(){
    int arr[9] = {8,5,3,1,4,6,10,11,14};
    Node * root = BuildBST(arr,9);
    root->data = 15;
    cout<<ValidBST(root,NULL,NULL);
    return 0;
}