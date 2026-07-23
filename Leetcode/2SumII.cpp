#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> arr,int target){
    int start = 0;
    int end = arr.size()-1;
    int Currsum = 0;
    vector<int> ans;
    while(start<end){
        Currsum = arr[start] + arr[end];
        if(Currsum == target){
            ans.push_back(start+1);
            ans.push_back(end+1);
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
};