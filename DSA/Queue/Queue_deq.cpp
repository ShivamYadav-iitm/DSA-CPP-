#include<iostream>
#include<deque>
using namespace std;

class Queue{
    deque<int> deq;
public:
    void push(int val){
        deq.push_back(val);
    }
    void pop(){
        deq.pop_front();
    }

    int front(){
        return deq.front();
    }

    bool empty(){
        deq.empty();
    }
};

int main(){ 
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }

}