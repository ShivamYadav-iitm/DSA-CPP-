#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int q_size = queries.size();
        vector<pair<int, int>> sorted_queries(q_size);
        for (int i = 0; i < q_size; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end());

        vector<int> res(q_size);
        vector<int> counts(n + 1, 0); 
        int active_servers = 0;
        int left = 0;
        int right = 0;
        int m = logs.size();

        for (const auto& q : sorted_queries) {
            int end_time = q.first;
            int start_time = end_time - x;
            int original_idx = q.second;

            while (right < m && logs[right][1] <= end_time) {
                if (counts[logs[right][0]] == 0) {
                    active_servers++;
                }
                counts[logs[right][0]]++;
                right++;
            }

            while (left < m && logs[left][1] < start_time) {
                counts[logs[left][0]]--;
                if (counts[logs[left][0]] == 0) {
                    active_servers--;
                }
                left++;
            }

            res[original_idx] = n - active_servers;
        }

        return res;
    }
};