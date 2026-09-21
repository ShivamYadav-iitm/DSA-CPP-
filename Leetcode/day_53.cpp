#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0);
        
        vector<long long> dp(k, 0);
        
        for (int i = 0; i < n; i++) {
            int val = nums[i] % k;
            vector<long long> next_dp(k, 0);
            
            next_dp[val] = 1;
            
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int new_rem = (r * val) % k;
                    next_dp[new_rem] += dp[r];
                }
            }
            
            for (int r = 0; r < k; r++) {
                result[r] += next_dp[r];
            }
            
            dp = next_dp;
        }
        
        return result;
    }
};