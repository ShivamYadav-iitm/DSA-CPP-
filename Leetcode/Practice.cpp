#include<iostream>
#include<queue>
#include<vector>
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


class Solution {
public:
    bool helper(Node * root){
        bool currleft = true;
        bool curright = true;
        if(root==NULL){
            return true;
        }
        if(root->left != NULL){
            currleft = root->left->data == root->data;
        }
        if(root->right != NULL){
            curright = root->right->data == root->data;
        }
        bool left =  helper(root->left);
        bool right = helper(root->right);

        bool curr = currleft && curright && left && right;
        return curr;

    }
    bool isUnivalTree(Node* root) {
        return helper(root);
    }
};