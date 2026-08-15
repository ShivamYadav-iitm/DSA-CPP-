#include<iostream>
#include<queue>
using namespace std;

void Interleaved(queue <int> &Q){
    queue<int> Q2;
    int n = Q.size();
    for(int i=0 ; i<n/2;i++){
        Q2.push(Q.front());
        Q.pop();
    }
    while(!Q2.empty()){
        Q.push(Q2.front());
        Q2.pop();
        Q.push(Q.front());
        Q.pop();
    }

    
}

int main(){
    queue<int> org;
    for(int i= 1 ; i<=10;i++){
        org.push(i);
    }
    Interleaved(org);
    for(int i= 1 ; i<=10;i++){
        cout<<org.front()<<" ";
        org.pop();
    }
    return 0;
    
}