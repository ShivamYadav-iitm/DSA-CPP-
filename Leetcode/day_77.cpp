#include<iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum_sq = 0;
        long long sum_d = 0;
        long long lazy = 0;
    };

    vector<Node> tree;

    void applyLazy(int node, int start, int end, long long val) {
        long long len = end - start + 1;
        val %= MOD;

        long long add_sq = (2 * val % MOD * tree[node].sum_d % MOD + val * val % MOD * len % MOD) % MOD;
        tree[node].sum_sq = (tree[node].sum_sq + add_sq) % MOD;

        tree[node].sum_d = (tree[node].sum_d + val * len % MOD) % MOD;

        tree[node].lazy = (tree[node].lazy + val) % MOD;
    }

    void push(int node, int start, int end) {
        if (tree[node].lazy != 0) {
            int mid = start + (end - start) / 2;
            applyLazy(2 * node, start, mid, tree[node].lazy);
            applyLazy(2 * node + 1, mid + 1, end, tree[node].lazy);
            tree[node].lazy = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (l <= start && end <= r) {
            applyLazy(node, start, end, val);
            return;
        }

        push(node, start, end);
        int mid = start + (end - start) / 2;

        if (l <= mid) update(2 * node, start, mid, l, r, val);
        if (r > mid) update(2 * node + 1, mid + 1, end, l, r, val);

        tree[node].sum_sq = (tree[2 * node].sum_sq + tree[2 * node + 1].sum_sq) % MOD;
        tree[node].sum_d = (tree[2 * node].sum_d + tree[2 * node + 1].sum_d) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n, Node());
        unordered_map<int, int> last_pos;
        long long total_sum = 0;

        for (int j = 0; j < n; j++) {
            int prev = last_pos.count(nums[j]) ? last_pos[nums[j]] : -1;
            
            update(1, 0, n - 1, prev + 1, j, 1);
            
            total_sum = (total_sum + tree[1].sum_sq) % MOD;
            
            last_pos[nums[j]] = j;
        }
        return total_sum;
    }
};