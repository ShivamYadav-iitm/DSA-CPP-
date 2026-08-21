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

int count(Node* root){
    if(root == NULL){
        return 0;
    }
    int left_c = count(root->left);
    int right_c = count(root->right);

    int curr_c = left_c + right_c +1;
    return curr_c;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node * root = Build(nodes);
    cout<<"toal nodes in tree is: " <<count(root)<< endl;
    cout<<"Root of the tree is "<<root->data<<"\n";
    return 0;
}