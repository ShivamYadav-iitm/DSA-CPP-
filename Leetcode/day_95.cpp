#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxm = INT_MIN;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            maxm = max(nums[i],maxm);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]<maxm){
                int lo = maxm - nums[i];
                for(int j=0;j<lo;j++){
                    nums[i]++;
                    count++;
                }
            }
        }
        return count;
    }
};
