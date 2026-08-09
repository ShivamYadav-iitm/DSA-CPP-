#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        if (n == 0) return 0;
        
        
        vector<vector<int>> memo(n, vector<int>(n + 1, 0));
        
        vector<int> suffix_sum(n, 0);
        suffix_sum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix_sum[i] = suffix_sum[i + 1] + piles[i];
        }
        
        return dfs(piles, memo, suffix_sum, 0, 1);
    }
    
private:
    int dfs(const vector<int>& piles, vector<vector<int>>& memo, const vector<int>& suffix_sum, int i, int M) {
        int n = piles.size();
        
        if (i >= n) return 0;
        
        if (i + 2 * M >= n) return suffix_sum[i];
        
        if (memo[i][M] != 0) return memo[i][M];
        
        int max_stones = 0;
        

        for (int x = 1; x <= 2 * M; ++x) {
            int current_stones = suffix_sum[i] - dfs(piles, memo, suffix_sum, i + x, max(M, x));
            max_stones = max(max_stones, current_stones);
        }
        
        return memo[i][M] = max_stones;
    }
};