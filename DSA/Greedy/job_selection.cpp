#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second>p2.second;
}

int maxJob(vector<pair<int,int>>jobs){
    int n = jobs.size();
    sort(jobs.begin(),jobs.end(),compare);
    int nums = 1;
    int profit = jobs[0].second;
    int safetime = 2;
    for(int i=0 ;i<n;i++){
        if(jobs[i].first>=safetime){
            profit += jobs[i].second;
            nums++;
            safetime++;
        }
    }
    cout<<"total number of jobs = "<<nums<<endl;
    cout<<"Max profit from jobs = "<<profit<<endl;
}

int main(){
    int n = 4;
    vector<pair<int,int>> jobs(n,make_pair(0,0));
    jobs[0] = make_pair(4,20);
    jobs[1] = make_pair(1,10);
    jobs[2] = make_pair(1,40);
    jobs[3] = make_pair(1,30);
    maxJob(jobs);
    return 0;
}