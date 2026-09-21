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

void kthlevel(Node* root,int k , int currlevel){ //O{n}
    if(root==NULL){
        return;
    }

    if(currlevel == k){
        cout<<root->data<<" ";
        return;
    }

    kthlevel(root->left,k,currlevel+1);
    kthlevel(root->right,k,currlevel+1);

}


int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node * root = Build(nodes);
    kthlevel(root,3,1);
    return 0;
}