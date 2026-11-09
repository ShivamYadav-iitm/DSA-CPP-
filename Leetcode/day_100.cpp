#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }

        using P = pair<long long, int>;
        priority_queue<P, vector<P>, greater<P>> busy;

        vector<int> count(k, 0);
        int n = arrival.size();

        for (int i = 0; i < n; ++i) {
            long long curr_time = arrival[i];

            while (!busy.empty() && busy.top().first <= curr_time) {
                available.insert(busy.top().second);
                busy.pop();
            }

           
            if (available.empty()) {
                continue;
            }

            
            int target = i % k;
            auto it = available.lower_bound(target);
            if (it == available.end()) {
                it = available.begin();
            }

            int assigned_server = *it;
            available.erase(it);

            busy.push({curr_time + load[i], assigned_server});
            count[assigned_server]++;
        }

        int max_req = *max_element(count.begin(), count.end());
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (count[i] == max_req) {
                result.push_back(i);
            }
        }

        return result;
    }
};