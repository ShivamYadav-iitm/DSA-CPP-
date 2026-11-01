#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();

        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int target = nums[i] - 1;

            if (i != target) {
                int l = min(i, target);
                int r = max(i, target);

                diff[l]++;
                diff[r + 1]--;
            }
        }

        int required = 0;
        int active = 0;

        for (int i = 0; i < n; i++) {
            active += diff[i];

            if (active > 0 && locked[i] == 1) {
                required++;
            }
        }

        if (required > k) {
            return -1;
        }

        vector<int> bit(n + 1, 0);

        auto update = [&](int i) {
            while (i <= n) {
                bit[i]++;
                i += i & -i;
            }
        };

        auto query = [&](int i) {
            int sum = 0;

            while (i > 0) {
                sum += bit[i];
                i -= i & -i;
            }

            return sum;
        };

        long long swaps = 0;

        for (int i = n - 1; i >= 0; i--) {
            swaps += query(nums[i] - 1);
            update(nums[i]);
        }

        return required + swaps;
    }
};