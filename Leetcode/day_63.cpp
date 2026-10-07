#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stc;
        if (s.size() % 2 != 0) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stc.push(s[i]);
            } 
            else {
                if (stc.empty()) {
                    return false;
                }
                
                char top = stc.top();
                if ((top == '(' && s[i] == ')') || 
                    (top == '[' && s[i] == ']') || 
                    (top == '{' && s[i] == '}')) {
                    stc.pop();
                } else {
                    return false; 
                }
            }
        }
        return stc.empty();
    }
};