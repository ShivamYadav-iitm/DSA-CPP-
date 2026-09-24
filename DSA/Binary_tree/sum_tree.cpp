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

void level2(Node* root){ //O{n} , O{n}
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node * curr = q.front();
        q.pop();
       

        if(curr == NULL){
            cout<<endl;
            if(q.empty()){
                break;
            }
            
            q.push(NULL);
        }else{

                cout<<curr->data<<",";

                if(curr->left != NULL){
                    q.push(curr->left);
                }

                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }
        
    }

}
int transform(Node* root){ //{N}
    if(root==NULL){
        return 0;
    }

    int leftold = transform(root->left);
    int rightold = transform(root->right);

    int currval = root->data;

    root->data = rightold+leftold;
    if(root->left != NULL){
        root->data += root->left->data;
    }
    
    if(root->right != NULL){
        root->data += root->right->data;
    }

    return currval;
}


int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node * root = Build(nodes);
    transform(root);
    level2(root);
    return 0;
}