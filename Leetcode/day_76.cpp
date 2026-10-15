#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        
        for (int start = 0; start < n; start++) {
            unordered_set<int> distinctElements;
            for (int end = start; end < n; end++) {
                distinctElements.insert(nums[end]);
                
                int count = distinctElements.size();
                
                totalSum += count * count;
            }
        }
        
        return totalSum;
    }
};