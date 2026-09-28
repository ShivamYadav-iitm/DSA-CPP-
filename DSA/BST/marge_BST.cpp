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

Node* buildfromsorted(vector<int>arr,int start,int end){
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

void getInorder(Node* root,vector<int> &nodes){
    if(root==NULL){
        return;
    }
    getInorder(root->left,nodes);
    nodes.push_back(root->data);
    getInorder(root->right,nodes);
}



Node* mergeBSTs(Node* root1,Node* root2){
    vector<int> node1;
    vector<int> node2;
    vector<int>merged;

    getInorder(root1,node1);
    getInorder(root2,node2);

    int i = 0 , j = 0;
    while(i <node1.size() && j<node2.size() ){
        if(node1[i]<node2[j]){
            merged.push_back(node1[i++]);
        }else{
            merged.push_back(node2[j++]);
        }
    }
    while(i<node1.size()){
        merged.push_back(node1[i++]);
    } 

    while(j<node2.size()){
        merged.push_back(node2[j++]);
    }

    return buildfromsorted(merged,0,merged.size()-1);
}


int main(){
    Node* root1 =  new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 =  new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node* root = mergeBSTs(root1,root2); 
    
    preorder(root);
    return 0;
}