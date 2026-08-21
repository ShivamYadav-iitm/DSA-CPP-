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

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int left_h = height(root->left);
    int right_h = height(root->right);

    int curr_h = max(right_h,left_h) +1;
    return curr_h;
}

int diam1(Node* root){  //O{n^2}
    if(root == NULL){
        return 0;
    }
    int currdiam = height(root->left) + height(root->right) + 1; //O{n}
    int leftdiam = diam1(root->left);
    int rightdiam = diam1(root->right);

    return max(currdiam , max(leftdiam , rightdiam));

}

pair<int , int> diam2(Node* root){ // (diam,height)
    if(root ==NULL){
        return make_pair(0,0);
    }
    //(diam,height)
    pair<int, int> Leftinfo = diam2(root->left);
    pair<int,int> rightinfo = diam2(root->right);
    
    int currDiam = Leftinfo.second + rightinfo.second + 1;
    int finaldiam = max(currDiam , max(Leftinfo.first , rightinfo.first));
    int finalheight = max(Leftinfo.second , rightinfo.second) + 1;

    return make_pair(finaldiam ,finalheight);
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node * root = Build(nodes);
    cout<<"Diameter of tree is: "<<diam2(root).first<< endl;
    cout<<"Root of the tree is "<<root->data<<"\n";
    return 0;
}