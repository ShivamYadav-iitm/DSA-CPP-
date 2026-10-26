#include <vector>
#include <algorithm>
#include <array>

using namespace std;

class Solution {
public:
    struct Result {
        long long score = 0;
        int sz = 0;
        array<int, 4> ids = {0, 0, 0, 0};

        bool operator<(const Result& other) const {
            if (score != other.score) {
                return score < other.score;
            }
            for (int i = 0; i < min(sz, other.sz); ++i) {
                if (ids[i] != other.ids[i]) {
                    return ids[i] > other.ids[i]; 
                }
            }
            return sz > other.sz; 
        }
    };
    struct Interval {
        int start, end, weight, id;
    };
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        vector<vector<Result>> dp(n + 1, vector<Result>(5));
        for (int i = n - 1; i >= 0; --i) {
            
            int low = i + 1, high = n - 1, next_idx = n;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid].start > arr[i].end) { 
                    next_idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            for (int k = 1; k <= 4; ++k) {
               
                Result skip = dp[i + 1][k];

              
                Result take = dp[next_idx][k - 1];
                take.score += arr[i].weight;
                take.ids[take.sz++] = arr[i].id;
                
                sort(take.ids.begin(), take.ids.begin() + take.sz);

                dp[i][k] = max(skip, take);
            }
        }
        return vector<int>(dp[0][4].ids.begin(), dp[0][4].ids.begin() + dp[0][4].sz);
    }
};