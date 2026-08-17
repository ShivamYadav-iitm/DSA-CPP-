#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}
int MaxLenChain(vector<pair<int,int>> p1){
    int n = p1.size();
    sort(p1.begin(),p1.end(),compare);
    int count = 1;
    int curr_end = p1[0].second;
    for(int i=0;i<n;i++){
        if(p1[i].first>=curr_end){
            count++;
            curr_end = p1[i].second;
        }
    }
    return count;
}
int main(){
    int n =5;
    vector<pair<int,int>> p1(n,make_pair(0,0));
    p1[0] = make_pair(5,24);
    p1[1] = make_pair(39,60);
    p1[2] = make_pair(5,28);
    p1[3] = make_pair(27,40);
    p1[4] = make_pair(50,90);

    cout<<MaxLenChain(p1);

}
