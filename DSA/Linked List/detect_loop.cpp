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
        Node*head;
        Node*tail;
    public:
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

        bool isloop(){
            Node * slow = head;
            Node * fast = head;
            while(fast != NULL && fast -> next != NULL){
                slow =  slow -> next;
                fast = fast -> next -> next;
                if(slow==fast){
                    cout<<"cycle exist"<<endl;
                    return true;
                }
            }
            cout<<"cycle doesn't exist"<<endl;
            return false;
        }

        void makeloop(){
            tail ->next = head;
        }
};

int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.isloop();
    return 0;
}