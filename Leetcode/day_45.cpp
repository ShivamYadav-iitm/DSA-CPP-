#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) ones1.push_back({r, c});
                if (img2[r][c] == 1) ones2.push_back({r, c});
            }
        }

        unordered_map<int, int> translation_counts;
        int max_overlap = 0;

        for (const auto& p1 : ones1) {
            for (const auto& p2 : ones2) {
                int vec = (p1.first - p2.first + 30) * 100 + (p1.second - p2.second + 30);
                
                translation_counts[vec]++;
                max_overlap = max(max_overlap, translation_counts[vec]);
            }
        }

        return max_overlap;
    }
};