#include<iostream>
#include<stack>
#include<climits>
using namespace std; 

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stc;
        stc.push(-1); 
        int max_len = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
               
                stc.push(i);
            } else {
                
                stc.pop();
                
                if (stc.empty()) {
                    
                    stc.push(i);
                } else {
                  
                    max_len = max(max_len, i - stc.top());
                }
            }
        }
        return max_len;
    }
};