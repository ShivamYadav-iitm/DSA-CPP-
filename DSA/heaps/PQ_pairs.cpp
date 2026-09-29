#include<iostream>
#include<queue>
#include<string>
using namespace std;


struct ComparePair {
    bool operator ()(pair<string,int>&p1 ,pair<string,int>&p2 ){  //for min heap use ">"
    return p1.second<p2.second;
    }
};

int main(){
    // priority_queue<pair<string,int>>pq; //by dafault max heap depending upon first.
    priority_queue<pair<string,int>,vector<pair<string,int>>,ComparePair>pq; 

    pq.push(make_pair("aman",500));
    pq.push(make_pair("bhumika",400));
    pq.push(make_pair("chetan",750));

    while(!pq.empty()){
        cout<<pq.top().first<<","<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}