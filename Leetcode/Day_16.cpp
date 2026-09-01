#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool stoneGameIX(std::vector<int>& stones) {
        int cnt[3] = {0, 0, 0};
        
        for (int stone : stones) {
            cnt[stone % 3]++;
        }
        
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        } 
        else {
            return std::abs(cnt[1] - cnt[2]) > 2;
        }
    }
};  