#include <vector>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
       
        vector<int> bitCount(30, 0);
        for (int num : nums) {
            for (int b = 0; b < 30; b++) {
                if ((num >> b) & 1) {
                    bitCount[b]++;
                }
            }
        }
        
        long long totalSum = 0;
        long long MOD = 1e9 + 7;
        
        for (int i = 0; i < k; i++) {
            long long currentNum = 0;
            
            for (int b = 0; b < 30; b++) {
                if (bitCount[b] > 0) {
                    currentNum |= (1LL << b);
                    bitCount[b]--; 
                }
            }
            
            long long square = (currentNum * currentNum) % MOD;
            totalSum = (totalSum + square) % MOD;
        }
        
        return totalSum;
    }
};