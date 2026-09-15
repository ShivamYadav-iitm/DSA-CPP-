#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.length();
        int ans = 0;
        int last_end = -1;
        for (int i = 0; i < n; i++) {
            if (i - k + 1 > last_end && isPalindrome(s, i - k + 1, i)) {
                ans++;
                last_end = i;
                continue;
            }
            
            if (i - k > last_end && isPalindrome(s, i - k, i)) {
                ans++;
                last_end = i;
            }
        }

        return ans;
    }
};