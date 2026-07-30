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

Node * merge(Node *left,Node* right){
    List ans;
    Node * i = left;
    Node * j = right;
    while(i!=NULL && j!=NULL){
        if(i->Data <= j->Data){
            ans.push_back(i->Data);
            i = i->next;
        }
        else{
            ans.push_back(j->Data);
            j = j->next;
        }
    }

    while(i!=NULL){
        ans.push_back(i->Data);
        i = i->next;
    }

    while(j!=NULL){
        ans.push_back(j->Data);
        j = j->next;
    }

    return ans.head;
}

Node* mergesort(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node * righthead = splitmid(head);
    Node *left = mergesort(head); //left half
    Node * right = mergesort(righthead); //right half
    return merge(left,right);
}

int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.printlist();
    ll.head = mergesort(ll.head);
    ll.printlist();

    return 0;
}