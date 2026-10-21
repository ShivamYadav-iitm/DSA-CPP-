#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        int n = s.length();
        if (n == 2) {
            return -1;
        }

        bool can_one_op = false;

        char current_max = s[0];
        for (int R = 0; R < n - 1; R++) {
            current_max = max(current_max, s[R]);
            bool valid = true;
            for (int j = R + 1; j < n; j++) {
                if (s[j] < current_max || (j > R + 1 && s[j] < s[j - 1])) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                can_one_op = true;
                break;
            }
        }

        if (!can_one_op) {
            char current_min = s[n - 1];
            for (int L = n - 1; L > 0; L--) {
                current_min = min(current_min, s[L]);
                bool valid = true;
                for (int j = 0; j < L; j++) {
                    if (s[j] > current_min || (j > 0 && s[j] < s[j - 1])) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    can_one_op = true;
                    break;
                }
            }
        }

        if (can_one_op) {
            return 1;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (s[0] == mx && s[n - 1] == mn) {
            if (count(s.begin(), s.end(), mx) == 1 && count(s.begin(), s.end(), mn) == 1) {
                return 3;
            }
        }

        return 2;
    }
};