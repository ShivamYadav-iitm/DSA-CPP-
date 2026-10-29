#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
private:
    struct Fenwick {
        int n;
        vector<int> tree;

        Fenwick(int n) : n(n), tree(n + 1, 0) {}

        void update(int i, int val) {
            for (; i <= n; i += i & -i) {
                tree[i] ^= val;
            }
        }

        int query(int i) {
            int sum = 0;
            for (; i > 0; i -= i & -i) {
                sum ^= tree[i];
            }
            return sum;
        }
    };

    vector<vector<int>> adj;
    vector<int> in, out, depth;
    vector<vector<int>> up;
    int timer = 0;
    int LOGN = 18;

    void dfs(int u, int p, int d) {
        in[u] = ++timer;
        depth[u] = d;
        up[u][0] = p;

        for (int i = 1; i < LOGN; i++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
            }
        }

        out[u] = timer;
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        for (int i = LOGN - 1; i >= 0; i--) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        for (int i = LOGN - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        in.resize(n);
        out.resize(n);
        depth.resize(n);
        up.assign(n, vector<int>(LOGN, 0));

        dfs(0, 0, 0);

        Fenwick bit(n);

        auto updateNode = [&](int u, char oldChar, char newChar) {
            int oldBit = 1 << (oldChar - 'a');
            int newBit = 1 << (newChar - 'a');
            int valChange = oldBit ^ newBit;

            bit.update(in[u], valChange);
            bit.update(out[u] + 1, valChange);
        };

        for (int i = 0; i < n; i++) {
            int mask = 1 << (s[i] - 'a');
            bit.update(in[i], mask);
            bit.update(out[i] + 1, mask);
        }

        vector<bool> ans;

        for (const string& qStr : queries) {
            stringstream ss(qStr);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                updateNode(u, s[u], c);
                s[u] = c;
            } else {
                int u, v;
                ss >> u >> v;

                int lca = getLCA(u, v);

                int maskU = bit.query(in[u]);
                int maskV = bit.query(in[v]);
                int maskLCA = bit.query(in[lca]);

                int nodeLCAMask = 1 << (s[lca] - 'a');

                int pathMask = maskU ^ maskV ^ nodeLCAMask;

                int oddCount = __builtin_popcount(pathMask);
                ans.push_back(oddCount <= 1);
            }
        }

        return ans;
    }
};