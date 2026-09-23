#include<iostream>
#include<map>
#include<vector>
#include <queue>

using namespace std;

class Node{ 
public:
    int data;
    Node * left;
    Node * right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;

Node * Build(vector<int> nodes){  //O{n}
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    Node*currNode = new Node(nodes[idx]);
    currNode->left = Build(nodes);
    currNode->right = Build(nodes);

    return currNode;
}

Node* LCA(Node* root,int n1 ,int n2){ //O{n} O{1}
    if(root==NULL){
        return NULL;
    }

    if(root->data == n1 ||root->data == n2){
        return root;
    }

    Node* left = LCA(root->left,n1,n2);
    Node* right = LCA(root->right,n1,n2);

    if(left != NULL && right != NULL){
        return root;
    }

    return left == NULL ? right:left;
}

int kthAncestor(Node*  root,int node ,int k){
    if(root==NULL){
        return -1;
    }
    if(root->data==node){
        return 0;
    }

    int leftdist = kthAncestor(root->left,node,k);
    int rightdist = kthAncestor(root->right,node,k);

    if(leftdist==-1&&rightdist==-1){
        return -1;
    }

    int valid = leftdist == -1 ? rightdist : leftdist;

    if(valid+1 == k){
        cout<<root->data<<endl;
    }
    return valid+1;

}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node * root = Build(nodes);
    kthAncestor(root,5,2);
    return 0;
}