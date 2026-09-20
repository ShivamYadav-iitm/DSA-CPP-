#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        int currev = 0;
        int indcurr = 0;
        for(int i = 0 ; i<s.length();i++){
            currev = 'z' - s[i] + 1;
            indcurr = currev * (i+1);
            total += indcurr;
        }
        return total;
    }
};