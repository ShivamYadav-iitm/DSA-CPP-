#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long long> endsWith(26, 0);
        long long total = 0;
        long long mod = 1e9 + 7;
        
        for (char c : s) {
            int index = c - 'a';
            
            long long newEnds = (total + 1) % mod;
            
            
            total = (total + newEnds - endsWith[index] + mod) % mod;
            
            endsWith[index] = newEnds;
        }
        
        return total;
    }
};