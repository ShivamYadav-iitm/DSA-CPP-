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

int dist(Node* root,int n){
    if(root==NULL){
        return -1;
    }

    if(root->data==n){
        return 0;
    }

    int leftdist = dist(root->left,n);

    if(leftdist!= -1){
        return leftdist + 1;
    }
    int rightdist = dist(root->right , n);

    if(rightdist!= -1){
        return rightdist + 1;
    }
    return -1;
}

int mindist(Node* root,int n1,int n2){
    Node * lca = LCA(root,n1,n2);

    int dist1 = dist(lca,n1);
    int dist2 = dist(lca,n2);

    return dist1+dist2;

}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node * root = Build(nodes);
    cout<<mindist(root,4,6)<<endl;
    return 0;
}