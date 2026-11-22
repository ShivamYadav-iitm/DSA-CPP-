#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int ina = 0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='b'){
                ina = i;
                for(int j=ina+1;j<s.length();j++){
                    if(s[j]=='a'){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
