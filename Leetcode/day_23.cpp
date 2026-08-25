#include<iostream>
#include<string>
#include <cmath>
using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        double sum1 = 0, sum2 = 0;
        double q1 = 0, q2 = 0;
        int n = num.length();
        
   
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                q1++;
            } else {
                sum1 += (num[i] - '0');
            }
        }


        
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                q2++;
            } else {
                sum2 += (num[i] - '0');
            }
        }

        if (fmod((q1 + q2), 2) != 0) {
            return true;
        }
        
       
        if (sum1 - sum2 == (q2 - q1) * 4.5) {
            return false;
        }
        
        return true;
    }
};