#include<vector>
#include<iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int es = 0;
        int score;
        while(es<nums.size()){
            int maxx = INT_MIN;
            int minn = INT_MAX;
            for(int i = 0;i<=es;i++){
                maxx = max(nums[i],maxx);
            }
            for(int i = es;i<nums.size();i++){
                minn = min(nums[i],minn);
            }

            score = maxx - minn;
            if(score <= k){
                return es;
            }
            es++;
            
        }
        return -1;
    }
};