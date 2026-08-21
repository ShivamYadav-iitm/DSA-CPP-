#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long min_coin = *min_element(coins.begin(), coins.end());
        long long high = min_coin * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (countValidAmounts(mid, coins) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }

private:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }

    long long countValidAmounts(long long M, const vector<int>& coins) {
        int n = coins.size();
        long long total = 0;
        
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long current_lcm = 1;
            int bits = 0;
            
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    bits++;
                    current_lcm = current_lcm / gcd(current_lcm, coins[i]) * coins[i];
                    
                    if (current_lcm > M) {
                        break; 
                    }
                }
            }
            
            if (current_lcm <= M) {
                if (bits % 2 == 1) {
                    total += M / current_lcm;
                } else {
                    total -= M / current_lcm;
                }
            }
        }
        
        return total;
    }
};