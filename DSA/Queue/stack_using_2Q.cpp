#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> s1;
    queue<int> s2;

public:
    void push(int val){   //O{n+n} = O{n}
        while(!s1.empty()){  //O{n}
            s2.push(s1.front());
            s1.pop();
        }

        s1.push(val);

        while(!s2.empty()){   //O{n}
            s1.push(s2.front());
            s2.pop();
            
        }
    }

    void pop(){
        s1.pop();
    }

    int front(){
        return s1.front();
    }
    bool empty(){
        s1.empty();
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    
    while(!s.empty()){
        cout<<s.front()<<endl;
        s.pop();
    }
    return 0;
}