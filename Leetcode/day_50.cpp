#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) first[idx] = i;
            last[idx] = i;
        }
        
        vector<pair<int, int>> validIntervals; 
        
        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;
            
            int L = first[i];
            int R = last[i];
            bool isValid = true;
            
            for (int j = L; j <= R; ++j) {
                int idx = s[j] - 'a';
                L = min(L, first[idx]);
                R = max(R, last[idx]);
                
               
                if (L < first[i]) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                validIntervals.push_back({R, L});
            }
        }
        
        sort(validIntervals.begin(), validIntervals.end());
        
        vector<string> result;
        int lastEnd = -1;
        
        for (const auto& interval : validIntervals) {
            int R = interval.first;
            int L = interval.second;
            if (L > lastEnd) {
                result.push_back(s.substr(L, R - L + 1));
                lastEnd = R;
            }
        }
        
        return result;
    }
};