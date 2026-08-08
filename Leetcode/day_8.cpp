#include <vector>
#include <string>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        if (n < m) return {};

        vector<int> R_exact(m + 1, -1);
        R_exact[m] = n;
        int p = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (p >= 0 && word1[p] != word2[j]) {
                p--;
            }
            if (p >= 0) {
                R_exact[j] = p;
                p--;
            } else {
                break; 
            }
        }

        vector<vector<int>> pos(26);
        for (int i = 0; i < n; ++i) {
            pos[word1[i] - 'a'].push_back(i);
        }
        vector<int> ptr(26);
        for (int c = 0; c < 26; ++c) {
            ptr[c] = (int)pos[c].size() - 1;
        }

        auto get_opt2 = [&](char c, int R) {
            int idx = c - 'a';
            while (ptr[idx] >= 0 && pos[idx][ptr[idx]] >= R) {
                ptr[idx]--;
            }
            if (ptr[idx] >= 0) return pos[idx][ptr[idx]];
            return -1;
        };

        vector<int> R_changed(m + 1, -1);
        R_changed[m] = n;
        for (int j = m - 1; j >= 0; --j) {
            int option1 = -1;
            if (R_exact[j + 1] != -1) {
                option1 = R_exact[j + 1] - 1;
            }
            int option2 = -1;
            if (R_changed[j + 1] != -1) {
                option2 = get_opt2(word2[j], R_changed[j + 1]);
            }
            R_changed[j] = max(option1, option2);
        }

        if (R_changed[0] == -1) return {};

        vector<int> ans;
        ans.reserve(m);
        bool changed = false;
        int last_i = -1;

        for (int j = 0; j < m; ++j) {
            bool found = false;
            for (int i = last_i + 1; i < n; ++i) {
                if (!changed) {
                    if (word1[i] == word2[j] && R_changed[j + 1] >= i + 1) {
                        ans.push_back(i);
                        last_i = i;
                        found = true;
                        break;
                    }
                    if (word1[i] != word2[j] && R_exact[j + 1] >= i + 1) {
                        ans.push_back(i);
                        last_i = i;
                        changed = true;
                        found = true;
                        break;
                    }
                } else {
                    if (word1[i] == word2[j] && R_exact[j + 1] >= i + 1) {
                        ans.push_back(i);
                        last_i = i;
                        found = true;
                        break;
                    }
                }
            }
            if (!found) return {}; 
        }
        return ans;
    }
};