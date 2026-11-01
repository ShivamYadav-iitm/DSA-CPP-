#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minimum = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            minimum = min(minimum, nums[i]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += nums[i] - minimum;
        }

        return ans;
    }
};