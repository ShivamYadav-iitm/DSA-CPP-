#include<iostream>
using namespace std;

class Node{
    public:
        int Data;
        Node * next;
        Node(int val){
            Data = val;
            next = NULL;
        }
};

class List{
    public:
        Node*head;
        Node*tail;
        List(){
            head = NULL;
            tail = NULL;
        }

        void push_front(int val){
            Node * newnode = new Node(val);
            if(head==NULL){
                head = tail = newnode;
            }
            else{
                newnode -> next = head;
                head = newnode;
            }
        }

        void push_back(int val){
            Node * newnode = new Node(val);
            if(head==NULL){
                head = tail = newnode;
            }
            else{
                tail -> next = newnode;
                tail = newnode;
            }
        }

        void printlist(){
            Node *temp = head;
            while(temp!=NULL){
                cout<<temp->Data<<"->";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }

        void insert(int val,int pos){
            Node * newnode = new Node(val);
            Node * temp = head;
            for(int i=0;i<pos-1;i++){
                if(temp == NULL){
                    cout<<"INVALID INDEX"<<endl;
                    return;
                }
                temp = temp->next;
            }

            //now temp points to pos-1 node
            newnode->next = temp->next;
            temp->next = newnode;

        }

        void pop_front(){
            Node * temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }

        void pop_back(){
            Node * temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            //now temp is pointing to prev of tail
            temp->next = NULL;
            delete tail;
            tail=temp; 
        }
};

Node * splitmid(Node*head){
    Node * slow = head;
    Node * fast = head;
    Node * prev = NULL;
    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow -> next;
        fast = fast->next->next;
    }
    if(prev != NULL){
        prev->next = NULL;
    }
    return slow;
}

Node * reverse(Node * head){
    Node * curr = head;
    Node * prev = NULL;
    

    while(curr!=NULL){
        Node * next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;

}

Node * altermerge(Node * lefthead,Node * righthead){
    Node * left = lefthead;
    Node * right = righthead;
    Node * tail = NULL;

    while(left != NULL && right != NULL){
        Node * nextleft = left-> next;
        Node * nextright = right -> next;

        left->next=right;
        right->next=nextleft;
        tail = right;

        left = nextleft;
        right = nextright;

    }
    if(right != NULL){
        tail->next = right;
        
    }
   return lefthead;
}

Node * zigzag(Node * head){
    Node * righthead = splitmid(head);
    Node * rightheadRev = reverse(righthead);
    Node *newhead = altermerge(head,rightheadRev);
    return newhead;
}





int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.printlist();
    ll.head = zigzag(ll.head);
    ll.printlist();
    return 0;
}