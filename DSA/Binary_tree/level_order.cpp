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


void level(Node* root){ //O{n} , O{n}
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node * curr = q.front();
        q.pop();
        cout<<curr->data<<endl;

        if(curr->left != NULL){
            q.push(curr->left);
        }

        if(curr->right != NULL){
            q.push(curr->right);
        }
        
    }

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


int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node * root = Build(nodes);
    // level(root); //level order traversal
    level2(root); //each level at new line 
    cout<<"Root of the tree is "<<root->data<<"\n";
    return 0;
}