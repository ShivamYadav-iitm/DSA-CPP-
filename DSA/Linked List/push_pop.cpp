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
        
        //for deleting the node from the memory
        ~Node(){
            cout<<"~Node"<<Data<<endl;
            if(next != NULL){
                delete next;
                next = NULL;
            }
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


        //for deleting the linked list from the memory
        ~List(){
            cout<<"~List"<<endl;
            if(head != NULL){
                delete head;
            }
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

int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printlist();
    ll.push_back(4);
    ll.push_back(5);
    ll.insert(100,2);
    ll.printlist();
    ll.pop_front();
    ll.printlist();
    ll.pop_back();
    ll.printlist();


}