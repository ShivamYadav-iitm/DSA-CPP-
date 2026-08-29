#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> counts(26, 0);
        for (char c : s) counts[c - 'a']++;

        int odd_count = 0;
        char mid_char = 0;
        vector<int> avail(26, 0);
        for (int i = 0; i < 26; ++i) {
            if (counts[i] % 2 != 0) {
                odd_count++;
                mid_char = i + 'a';
            }
            avail[i] = counts[i] / 2;
        }

        if (odd_count > 1) return "";

        int m = n / 2;
        int L = (n + 1) / 2;

        vector<int> prefix_counts(26, 0);
        for (int i = 0; i < L - 1; ++i) {
            prefix_counts[target[i] - 'a']++;
        }

        for (int len = L; len >= 0; --len) {
            if (len == L) {
                if (n % 2 != 0 && target[m] != mid_char) continue;
                
                vector<int> required(26, 0);
                bool possible = true;
                for (int i = 0; i < m; ++i) required[target[i] - 'a']++;
                for (int i = 0; i < 26; ++i) {
                    if (required[i] != avail[i]) {
                        possible = false;
                        break;
                    }
                }
                
                if (possible) {
                    string P = target.substr(0, L);
                    string rev_part = target.substr(0, m);
                    reverse(rev_part.begin(), rev_part.end());
                    P += rev_part;
                    
                    if (P > target) return P;
                }
            } else {
                bool possible = true;
                for (int i = 0; i < 26; ++i) {
                    if (prefix_counts[i] > avail[i]) {
                        possible = false;
                        break;
                    }
                }
                
                if (possible) {
                    vector<int> rem_avail = avail;
                    for (int i = 0; i < 26; ++i) rem_avail[i] -= prefix_counts[i];
                    
                    if (len == m) {
                        if (mid_char > target[len]) {
                            string P = target.substr(0, m) + mid_char;
                            string rev_part = target.substr(0, m);
                            reverse(rev_part.begin(), rev_part.end());
                            P += rev_part;
                            return P;
                        }
                    } else {
                        char chosen = 0;
                        for (char c = target[len] + 1; c <= 'z'; ++c) {
                            if (rem_avail[c - 'a'] > 0) {
                                chosen = c;
                                break;
                            }
                        }
                        
                        if (chosen != 0) {
                            rem_avail[chosen - 'a']--;
                            string H = target.substr(0, len) + chosen;
                            for (int i = 0; i < 26; ++i) {
                                H.append(rem_avail[i], i + 'a');
                            }
                            
                            string P = H;
                            if (n % 2 != 0) P += mid_char;
                            string rev_H = H;
                            reverse(rev_H.begin(), rev_H.end());
                            P += rev_H;
                            return P;
                        }
                    }
                }
                
                if (len > 0) {
                    prefix_counts[target[len - 1] - 'a']--;
                }
            }
        }
        return "";
    }
};