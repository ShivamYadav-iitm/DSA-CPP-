#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> bonus(n, 0);
        long long min_price = LLONG_MAX;
        int total_bonus_cap = 0;

        for (int i = 0; i < n; ++i) {
            min_price = min(min_price, (long long)items[i][1]);
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    bonus[i]++;
                }
            }
            total_bonus_cap += bonus[i];
        }

        
        int max_dp_items = 2 * total_bonus_cap + n;
        const long long INF = 1e18;
        vector<long long> dp(max_dp_items + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            long long price = items[i][1];
            int b = bonus[i];
            
           
            int rem = b;
            for (int k = 1; rem > 0; k <<= 1) {
                int take = min(k, rem);
                rem -= take;
                int gain = 2 * take;
                long long cost = take * price;
                for (int c = max_dp_items; c >= gain; --c) {
                    if (dp[c - gain] != INF) {
                        dp[c] = min(dp[c], dp[c - gain] + cost);
                    }
                }
            }
        }

        long long ans = 0;
        for (int c = 0; c <= max_dp_items; ++c) {
            if (dp[c] <= budget) {
                long long remaining_budget = budget - dp[c];
                long long extra_items = remaining_budget / min_price;
                ans = max(ans, (long long)c + extra_items);
            }
        }

        return (int)ans;
    }
};