#include <vector>
#include <cstdint>
#include<iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const uint64_t MOD1 = 1000000007ULL;
        const uint64_t MOD2 = 1000000009ULL;
        const uint64_t BASE1 = 911382323ULL;
        const uint64_t BASE2 = 972663749ULL;
        const uint64_t OFFSET = 1000000005ULL;
        auto hasUnique = [&](int len) -> bool {
            uint64_t h1 = 0, h2 = 0;
            uint64_t p1 = 1, p2 = 1;
            for (int i = 0; i < len; ++i) {
                uint64_t val = static_cast<uint64_t>(nums[i]) + OFFSET;
                h1 = (h1 * BASE1 + val) % MOD1;
                h2 = (h2 * BASE2 + val) % MOD2;
                if (i > 0) {
                    p1 = (p1 * BASE1) % MOD1;
                    p2 = (p2 * BASE2) % MOD2;
                }
            }

            vector<uint64_t> hashes;
            hashes.reserve(n - len + 1);
            hashes.push_back((h1 << 32) | h2);

            for (int i = len; i < n; ++i) {
                uint64_t outVal = static_cast<uint64_t>(nums[i - len]) + OFFSET;
                uint64_t inVal = static_cast<uint64_t>(nums[i]) + OFFSET;

                h1 = (h1 + MOD1 - (outVal * p1) % MOD1) % MOD1;
                h1 = (h1 * BASE1 + inVal) % MOD1;

                h2 = (h2 + MOD2 - (outVal * p2) % MOD2) % MOD2;
                h2 = (h2 * BASE2 + inVal) % MOD2;

                hashes.push_back((h1 << 32) | h2);
            }

            sort(hashes.begin(), hashes.end());
            int m = hashes.size();
            for (int i = 0; i < m; ++i) {
                bool sameLeft = (i > 0 && hashes[i] == hashes[i - 1]);
                bool sameRight = (i + 1 < m && hashes[i] == hashes[i + 1]);
                if (!sameLeft && !sameRight) {
                    return true;
                }
            }
            return false;
        };

        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};