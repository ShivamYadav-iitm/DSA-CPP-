#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        
        for (char c : s) {
            count[c - 'a']++;
        }

        int i = 0;
        while (i < n && count[target[i] - 'a'] > 0) {
            count[target[i] - 'a']--;
            i++;
        }

        if (i == n) {
            i--;
            count[target[i] - 'a']++;
        }

        while (i >= 0) {
            for (char c = target[i] + 1; c <= 'z'; c++) {
                if (count[c - 'a'] > 0) {
                    count[c - 'a']--; 

                    string ans = target.substr(0, i) + c;
                    
                    for (int j = 0; j < 26; j++) {
                        ans += string(count[j], j + 'a');
                    }
                    return ans;
                }
            }

            i--;
            if (i >= 0) {
                count[target[i] - 'a']++;
            }
        }

        return "";
    }
};

