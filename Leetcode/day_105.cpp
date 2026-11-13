#include<vector>
#include<iostream>
#include<climits>

using namespace std;
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        vector<int> nge(n, -1), st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] <= nums[i])
                st.pop_back();

            if (!st.empty())
                nge[i] = st.back();

            st.push_back(i);
        }

        vector<vector<int>> up(LOG, vector<int>(n, -1));
        vector<vector<long long>> sum(LOG, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            up[0][i] = nge[i];

            int end = (nge[i] == -1 ? n : nge[i]);

            sum[0][i] = 1LL * (end - i - 1) * nums[i]
                        - (pref[end] - pref[i + 1]);
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int mid = up[j - 1][i];

                if (mid != -1 && up[j - 1][mid] != -1) {
                    up[j][i] = up[j - 1][mid];
                    sum[j][i] = sum[j - 1][i] + sum[j - 1][mid];
                }
            }
        }

        auto getCost = [&](int l, int r) -> long long {
            long long cost = 0;
            int cur = l;

            for (int j = LOG - 1; j >= 0; j--) {
                int nxt = up[j][cur];

                if (nxt != -1 && nxt <= r) {
                    cost += sum[j][cur];
                    cur = nxt;
                }
            }

            cost += 1LL * (r - cur) * nums[cur]
                    - (pref[r + 1] - pref[cur + 1]);

            return cost;
        };

        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int low = 0, high = r;

            while (low < high) {
                int mid = low + (high - low) / 2;

                if (getCost(mid, r) <= k)
                    high = mid;
                else
                    low = mid + 1;
            }

            ans += r - low + 1;
        }

        return ans;
    }
};
