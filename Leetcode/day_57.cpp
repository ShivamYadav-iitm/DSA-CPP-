#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
   
    set<string> combineGroup(const vector<set<string>>& group) {
        set<string> res = {""};
        
        for (const auto& s : group) {
            set<string> next_res;
            for (const string& prefix : res) {
                for (const string& str : s) {
                    next_res.insert(prefix + str);
                }
            }
            res = move(next_res);
        }
        
        return res;
    }

public:
    vector<string> braceExpansionII(string expression) {
        set<string> total_set;
        vector<set<string>> cur_group;
        
        int n = expression.length();
        int i = 0;
        
        while (i < n) {
            if (expression[i] == '{') {
               
                int j = i, brace_count = 0;
                while (j < n) {
                    if (expression[j] == '{') brace_count++;
                    if (expression[j] == '}') brace_count--;
                    if (brace_count == 0) break;
                    j++;
                }
                
                
                string sub_expr = expression.substr(i + 1, j - i - 1);
                vector<string> sub_res = braceExpansionII(sub_expr);
                
                set<string> sub_set(sub_res.begin(), sub_res.end());
                cur_group.push_back(sub_set);
                
                i = j + 1; 
            } 
            else if (isalpha(expression[i])) {
                string word = "";
                while (i < n && isalpha(expression[i])) {
                    word += expression[i];
                    i++;
                }
                cur_group.push_back({word});
            } 
            else if (expression[i] == ',') {
                set<string> prod = combineGroup(cur_group);
                total_set.insert(prod.begin(), prod.end());
                cur_group.clear();
                i++;
            }
        }
        
        set<string> prod = combineGroup(cur_group);
        total_set.insert(prod.begin(), prod.end());
        
        return vector<string>(total_set.begin(), total_set.end());
    }
};