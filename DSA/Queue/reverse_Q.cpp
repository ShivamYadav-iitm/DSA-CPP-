#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int> &Q){
    stack<int> s;
    while(!Q.empty()){
        s.push(Q.front());
        Q.pop();
    }

    while(!s.empty()){
        Q.push(s.top());
        s.pop();
    }
}

int main(){
    queue<int> org;
    for(int i=1 ; i<=5;i++){
        org.push(i);
    }
    reverse(org);
    for(int i=0 ; i<5;i++){
        cout<<org.front()<<" ";
        org.pop();

    }
    return 0;
}
