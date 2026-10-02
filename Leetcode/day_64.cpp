#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void backtrack(vector<string>& ans, string current, int openCount, int closeCount, int n) {
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }
        
        if (openCount < n) {
            backtrack(ans, current + "(", openCount + 1, closeCount, n);
        }
        
        if (closeCount < openCount) {
            backtrack(ans, current + ")", openCount, closeCount + 1, n);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }
};