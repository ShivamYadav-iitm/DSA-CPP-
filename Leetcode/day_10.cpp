#include <vector>

class Solution {
public:
    bool winnerSquareGame(int n) {
        // dp[i] will be true if the current player wins with i stones remaining
        std::vector<bool> dp(n + 1, false);
        
        for (int i = 1; i <= n; ++i) {
            // Try all possible square numbers k*k that can be removed
            for (int k = 1; k * k <= i; ++k) {
                // If removing k*k stones leaves the opponent with a losing state, 
                // then the current state i is a winning state.
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break; // We found a winning move, no need to check further
                }
            }
        }
        
        return dp[n];
    }
};