#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());
        int ans = 0;
        int totalMasks = 1 << n;

        for (int mask = 1; mask < totalMasks; ++mask) {
            long long cost = 0;
            int minPrice = INT_MAX;
            int boughtTypes = 0;

            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    cost += items[i][1];
                    minPrice = min(minPrice, items[i][1]);
                    ++boughtTypes;
                }
            }

            if (cost > budget) {
                continue;
            }

            long long extraCopies = (budget - cost) / minPrice;
            int freeCopies = 0;

            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    for (int j = 0; j < n; ++j) {
                        if (i != j && items[j][0] % items[i][0] == 0) {
                            ++freeCopies;
                        }
                    }
                }
            }

            int totalItems = static_cast<int>(boughtTypes + extraCopies + freeCopies);
            ans = max(ans, totalItems);
        }

        return ans;
    }
};