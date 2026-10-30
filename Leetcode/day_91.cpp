#include<iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;


class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            State state = pq.top();
            int d = get<0>(state);
            int u = get<1>(state);
            int cnt = get<2>(state);
            pq.pop();

            if (u == n - 1) {
                return d;
            }

            if (d > dist[u][cnt]) {
                continue;
            }

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                int next_cnt = (labels[u] == labels[v]) ? cnt + 1 : 1;

                if (next_cnt <= k) {
                    if (d + weight < dist[v][next_cnt]) {
                        dist[v][next_cnt] = d + weight;
                        pq.push(State{dist[v][next_cnt], v, next_cnt});
                    }
                }
            }
        }

        return -1; 
    }
};