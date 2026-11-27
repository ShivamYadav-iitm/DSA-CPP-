#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        const int INF = 1e9;
        vector<vector<int>> divisors(n + 1);
        for (int len = 2; len <= n; ++len) {
            for (int d = 1; d < len; ++d) {
                if (len % d == 0) {
                    divisors[len].push_back(d);
                }
            }
        }
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                for (int d : divisors[len]) {
                    int changes = 0;
                    for (int rem = 0; rem < d; ++rem) {
                        int left = i + rem;
                        int right = j - (d - 1 - rem);
                        while (left < right) {
                            if (s[left] != s[right]) {
                                changes++;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int prev = 0; prev <= i - 2; ++prev) {
                    if (dp[prev][j - 1] != INF) {
                        dp[i][j] = min(dp[i][j], dp[prev][j - 1] + cost[prev][i - 1]);
                    }
                }
            }
        }
        
        return dp[n][k];
    }
};