#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_servers;
        
        using BusyServer = pair<long long, pair<int, int>>;
        priority_queue<BusyServer, vector<BusyServer>, greater<BusyServer>> busy_servers;
        
        int n = servers.size();
        for (int i = 0; i < n; ++i) {
            free_servers.push({servers[i], i});
        }
        
        int m = tasks.size();
        vector<int> ans(m);
        long long current_time = 0;
        
        for (int j = 0; j < m; ++j) {
            current_time = max(current_time, (long long)j);
            
            if (free_servers.empty()) {
                current_time = busy_servers.top().first;
            }
            
            while (!busy_servers.empty() && busy_servers.top().first <= current_time) {
                free_servers.push(busy_servers.top().second);
                busy_servers.pop();
            }
            
            auto top_server = free_servers.top();
            free_servers.pop();
            
            ans[j] = top_server.second;
            
            busy_servers.push({current_time + tasks[j], top_server});
        }
        
        return ans;
    }
};