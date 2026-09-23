#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) { 
        int n = nums.size();
        
        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        
        long long target = totalSum - x;
        
        if (target < 0) {
            return -1; 
        }
        if (target == 0) {
            return n;
        }
        
        int left = 0;
        long long currentSum = 0;
        int maxLen = -1;
        
        for (int right = 0; right < n; right++) {
            currentSum += nums[right];
            
            while (left <= right && currentSum > target) {
                currentSum -= nums[left];
                left++;
            }
            
            if (currentSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        if (maxLen == -1) {
            return -1; 
        }
        
        return n - maxLen;
    }
};