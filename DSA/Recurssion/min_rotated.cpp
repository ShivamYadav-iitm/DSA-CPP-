#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int si = 0;
        int ei = nums.size()-1;
        return search(nums,si,ei);
    }
private:
    int search(vector<int> &nums,int si,int ei){
        if(si==ei){ 
            return nums[si];
        }
        int mid = si + (ei-si)/2;
        if(nums[mid]>nums[ei]){
            si = mid+1;
            return search(nums,si,ei);
        }
        else{
            ei = mid;
            return search(nums,si,ei);
        }
    }
};