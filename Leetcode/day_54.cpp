
#include<iostream>
#include <vector>
using namespace std;

struct SegmentNode {
    int total_prod;
    vector<int> cnt;
};

class Solution {
private:
    vector<SegmentNode> tree;

    SegmentNode mergeNodes(const SegmentNode& left, const SegmentNode& right, int k) {
        SegmentNode res;
        res.cnt.assign(k, 0);
        res.total_prod = (left.total_prod * right.total_prod) % k;

        for (int i = 0; i < k; i++) {
            res.cnt[i] += left.cnt[i];
        }

        for (int y = 0; y < k; y++) {
            if (right.cnt[y] > 0) {
                int rem = (left.total_prod * y) % k;
                res.cnt[rem] += right.cnt[y];
            }
        }

        return res;
    }

    void build(int node, int l, int r, const vector<int>& nums, int k) {
        tree[node].cnt.assign(k, 0);
        if (l == r) {
            int val = nums[l] % k;
            tree[node].total_prod = val;
            tree[node].cnt[val] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid, nums, k);
        build(2 * node + 1, mid + 1, r, nums, k);
        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1], k);
    }

    void update(int node, int l, int r, int idx, int val, int k) {
        if (l == r) {
            tree[node].cnt.assign(k, 0);
            int rem = val % k;
            tree[node].total_prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * node, l, mid, idx, val, k);
        } else {
            update(2 * node + 1, mid + 1, r, idx, val, k);
        }
        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1], k);
    }

    void query(int node, int l, int r, int ql, int qr, int k, int& current_prod, vector<int>& ans_cnt) {
        if (ql <= l && r <= qr) {
            for (int y = 0; y < k; y++) {
                if (tree[node].cnt[y] > 0) {
                    int rem = (current_prod * y) % k;
                    ans_cnt[rem] += tree[node].cnt[y];
                }
            }
            current_prod = (current_prod * tree[node].total_prod) % k;
            return;
        }
        int mid = l + (r - l) / 2;
        if (ql <= mid) {
            query(2 * node, l, mid, ql, qr, k, current_prod, ans_cnt);
        }
        if (qr > mid) {
            query(2 * node + 1, mid + 1, r, ql, qr, k, current_prod, ans_cnt);
        }
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        tree.resize(4 * n);
        
        build(1, 0, n - 1, nums, k);

        int q = queries.size();
        vector<int> result;
        result.reserve(q);

        for (int i = 0; i < q; i++) {
            int idx = queries[i][0];
            int val = queries[i][1];
            int start = queries[i][2];
            int target_x = queries[i][3];

            update(1, 0, n - 1, idx, val, k);

            int current_prod = 1;
            vector<int> ans_cnt(k, 0);
            query(1, 0, n - 1, start, n - 1, k, current_prod, ans_cnt);

            result.push_back(ans_cnt[target_x]);
        }

        return result;
    }
};