#include<iostream>
#include<queue>  
using namespace std;

int main(){
    priority_queue<int> pq;  

    pq.push(3); //O(logN)
    pq.push(10);
    pq.push(5);
    pq.push(9);
    pq.push(7);

    priority_queue<int,vector<int> , greater<int>> pd; // for asc order

    pd.push(3);
    pd.push(10);
    pd.push(5);
    pd.push(9);
    pd.push(7);


    while(!pq.empty()){
        cout<<"top: "<<pq.top()<<endl; // by  def max at highest i.e. desc order
        pq.pop();
    }
    cout<<"----------------------------------------------------------------------"<<endl;
     while(!pd.empty()){
        cout<<"top: "<<pd.top()<<endl; // for asc order
        pd.pop();
    }
    return 0;
}