#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int es = 0;
        int score;
        int n  = nums.size();
        vector<int> suffixmin(n);

        suffixmin[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffixmin[i] = min(nums[i],suffixmin[i+1]);
        }

        int currmax = INT_MIN;
        for(int i=0;i<n;i++){
            currmax = max(currmax , nums[i]);

            if(currmax - suffixmin[i] <= k){
                return i;
            }
        }
        return -1;


    }
};