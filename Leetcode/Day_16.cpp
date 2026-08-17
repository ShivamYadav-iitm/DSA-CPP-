#include <vector>
#include <cmath>

class Solution {
public:
    bool stoneGameIX(std::vector<int>& stones) {
        int cnt[3] = {0, 0, 0};
        
        // Count frequencies of remainders when divided by 3
        for (int stone : stones) {
            cnt[stone % 3]++;
        }
        
        // If the number of 0-mod stones is even
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        } 
        // If the number of 0-mod stones is odd
        else {
            return std::abs(cnt[1] - cnt[2]) > 2;
        }
    }
};  