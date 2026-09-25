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

Node * getInorderSuccessor(Node * root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* Delete(Node* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(val>root->data){
        root->right = Delete(root->right,val);
    }
    else if(val<root->data){
        root->left = Delete(root->left,val);
    }else{
        //case 1 : when no child of node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //case 2: has 1 child
        if(root->left == NULL || root->right == NULL){
            return root->left == NULL ? root->right : root->left;
        }

        //case 3: has 2 children
        Node * IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = Delete(root->right,IS->data);
        return root;

    }
}

int main(){
    int arr[6] = {5,1,3,4,2,7};

    Node * root = BuildBST(arr,6);
    inorder(root);
    cout<<endl;
    Delete(root,3);
    inorder(root);
    cout<<endl;
    return 0;
}