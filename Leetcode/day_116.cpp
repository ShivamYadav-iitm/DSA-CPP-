#include<iostream>
#include <vector>
#include <climits>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 1; 
        maxlen = 0;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long gcdo = 0;
            long long lcmo = 1;

            for (int j = i; j < n; ++j) {
                if (prod > LLONG_MAX / nums[j]) break;
                prod *= nums[j];
                gcdo = (gcdo, (long long)nums[j]);
                lcmo = (lcmo, (long long)nums[j]);

                if (prod == lcmo * gcdo) {
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }
        return maxlen;
    }
};