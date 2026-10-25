#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;
        for (const auto& pair : knowledge) {
            map[pair[0]] = pair[1];
        }
        string result = "";
        string currentKey = "";
        bool insideBracket = false;
        for (char c : s) {
            if (c == '(') {
                insideBracket = true;
                currentKey = "";
            } 
            else if (c == ')') {
                insideBracket = false;
                if (map.find(currentKey) != map.end()) {
                    result += map[currentKey];
                } else {
                    result += '?';
                }
            } 
            else {
                if (insideBracket) {
                    currentKey += c; 
                } else {
                    result += c;    
                }
            }
        }
        return result;
    }
};