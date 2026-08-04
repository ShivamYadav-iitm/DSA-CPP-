#include<iostream>
#include<vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        std::unordered_set<int> present(nums.begin(), nums.end());
        
        int min_val = *std::min_element(nums.begin(), nums.end());
        int max_val = *std::max_element(nums.begin(), nums.end());
        
        std::vector<int> res;
        for (int val = min_val + 1; val < max_val; ++val) {
            if (present.find(val) == present.end()) {
                res.push_back(val);
            }
        }
        
        return res;
    }
};