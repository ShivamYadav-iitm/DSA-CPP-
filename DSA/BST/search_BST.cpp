#include<iostream>
#include<vector>

using namespace std;

class Node{
public:
    int val;
    Node * left;
    Node * right;

    Node(int data){
        this->val = data;
        left = right =  NULL;
    }

};

Node * insert(Node * root,int val){
    if(root==NULL){
        root = new Node(val);
        return root;
    }

    if(val>root->val){
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


bool helper(Node* root,int val){
    if(root==NULL){
        return false;
    }
    if(root->val == val){
        return true;
    }
    else if(root->val>val){
        return helper(root->left,val);
    }else{
        return helper(root->right,val);
    }
}

bool searchBST(Node* root, int val) {
    return helper(root,val);
}


int main(){
    int arr[9] = {8,5,3,1,6,4,10,11,14};
    Node * root = BuildBST(arr,6);
    cout<<searchBST(root,4);
    cout<<endl;
    return 0;
}