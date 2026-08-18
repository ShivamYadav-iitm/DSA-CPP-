#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        
        // Count the overall frequency of each element in the array
        for (int num : nums) {
            count[num]++;
        }
        
        // Case 1: Subarrays of size 1
        // Case 1: Subarrays of size 1
        if (k == 1) {
            int max_val = -1;
            for (auto const& pair : count) {
                if (pair.second == 1) {
                    max_val = max(max_val, pair.first);
                }
            }
            return max_val;
        }
        
        // Case 2: Subarray spans the entire array
        if (k == n) {
            int max_val = -1;
            for (int num : nums) {
                max_val = max(max_val, num);
            }
            return max_val;
        }
        
        // Case 3: 1 < k < n
        int max_val = -1;
        
        // Only the first and last elements can possibly appear in exactly one subarray
        if (count[nums[0]] == 1) {
            max_val = max(max_val, nums[0]);
        }
        if (count[nums[n - 1]] == 1) {
            max_val = max(max_val, nums[n - 1]);
        }
        
        return max_val;
    }
};