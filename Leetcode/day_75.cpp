#include<iostream>
#include <string>

using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num || sum < 1) {
            return "";
        }
        
        string res = "";
        
        while (num > 0) {
            if (sum >= 9) {
                res += '9';
                sum -= 9;
            } else if (sum > 0) {
                res += to_string(sum);
                sum = 0;
            } else {
                res += '0';
            }
            num--;
        }
        
        return res;
    }
};