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

        int search(int key){ //TC = O{n}
            int pos =0;
            Node * temp =head;
            while(temp != NULL){
                if(temp->Data == key){
                    return pos;
                }
                else{
                    temp = temp -> next;
                    pos = pos+1;
                }
            }
            return -1;
        }

        int helper(Node * temp,int key){
            if(temp == NULL){
                return -1;
            }
            if(temp->Data == key){
                return 0;
            }
            else{
                int idx = helper(temp->next,key);
                if(idx==-1){
                    return -1;
                }
                else{
                    return idx+1;
                }
            }
        }

        int searchrec(int key){
            return helper(head,key);
        }

        void reverse(){
            Node * curr = head;
            Node * prev = NULL;

            while(curr!=NULL){
                Node * next = curr->next;
                curr->next = prev;
                //updation for next iteration
                prev = curr;
                curr =  next;
            }
            prev = head;
        }

        int getSize(){
            int size = 0;
            Node* temp = head;
            while(temp != NULL){
                temp = temp->next;
                size++;
            }
            return size;
        }

        void removeNthFromEnd(int n) {
        
        int size = getSize();

        Node * prev = head;
        for(int i=1;i<(size-n);i++){
            prev=prev->next;
        }
        //now prev is prev of nth from last
        prev->next = prev->next->next;
    }
        
};

int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);
    ll.insert(100,2);
    ll.printlist();
    ll.removeNthFromEnd(2);
    ll.printlist();
    return 0;
}