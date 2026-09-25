#include<iostream>
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

void printInrange(Node* root,int start,int end){
    if(root==NULL){
        return;
    }
    if(root->data>=start && root->data<=end){
        
        printInrange(root->left,start,end);
        cout<<root->data<<" ";
        printInrange(root->right,start,end);
    }
    if(root->data<start){
        printInrange(root->right,start,end);
    }
    if(root->data>end){
        printInrange(root->left,start,end);
    }
}

int main(){
    int arr[9] = {8,5,3,1,4,6,10,11,14};

    Node * root = BuildBST(arr,9);
    inorder(root);
    cout<<endl;
    printInrange(root,5,12);
    cout<<endl;
    return 0;
}