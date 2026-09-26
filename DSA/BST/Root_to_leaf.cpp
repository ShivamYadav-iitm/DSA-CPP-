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

void printpath(vector<int>&path){
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}

void pathHelper(Node*root,vector<int> &path){
    if(root==NULL){ //base case
        return;
    }

    path.push_back(root->data);
    if(root->left==NULL && root->right == NULL){ //leaf node
        printpath(path);
        path.pop_back();
        return;
    }
    pathHelper(root->left,path);
    pathHelper(root->right,path);
    path.pop_back();
}

void rootToLeaf(Node* root){
    vector<int> path;
    pathHelper(root,path);
}

int main(){
    int arr[9] = {8,5,3,1,4,6,10,11,14};
    Node * root = BuildBST(arr,9);
    rootToLeaf(root);
    cout<<endl;
    return 0;
}