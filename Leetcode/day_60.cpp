#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int currmax = 0;
        int tomax = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                currmax++;
            }

            if(s[i] == ')'){
                tomax = max(currmax,tomax);
                currmax--;
            }
        }
        return tomax;
    }
};