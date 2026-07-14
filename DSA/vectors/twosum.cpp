#include<iostream>
#include <vector>
using namespace std;

vector<int> twosum(vector<int> arr,int target){
    int start = 0;
    int end = arr.size()-1;
    int Currsum = 0;
    vector<int> ans;
    while(start<end){
        Currsum = arr[start] + arr[end];
        if(Currsum == target){
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
        else if(Currsum > target){
            end --;
        }
        else{
            start ++;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {2,7,11,15};
    int target = 9;
    vector<int> ans = twosum(arr,target);
    cout<<ans[0]<<","<<ans[1];
    return 0;
}