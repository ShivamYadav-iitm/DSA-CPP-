#include<iostream>
#include<stack>
#include<string>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stc;
        stc.push(0); 
        
        for (char c : s) {
            if (c == '(') {
                stc.push(0); 
            } else {
                int inner_score = stc.top();
                stc.pop();
                
                int current_score = max(2 * inner_score, 1);
                
                stc.top() += current_score;
            }
        }
        
        return stc.top();
    }
};