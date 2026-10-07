#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;


class Solution {
public:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') count--;
            
            if (count < 0) return false;
        }
        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited; 
        queue<string> q;               
        
        q.push(s);
        visited.insert(s);
        
        bool foundValid = false;
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            
            if (isValid(curr)) {
                ans.push_back(curr);
                foundValid = true; 
            }
            
            
            if (foundValid) {
                continue; 
            }
            
           
            for (int i = 0; i < curr.length(); i++) {
                
                if (curr[i] != '(' && curr[i] != ')') {
                    continue;
                }
                
              
                string nextStr = curr.substr(0, i) + curr.substr(i + 1);
                
              
                if (visited.find(nextStr) == visited.end()) {
                    visited.insert(nextStr);
                    q.push(nextStr);
                }
            }
        }
        
        return ans;
    }
};