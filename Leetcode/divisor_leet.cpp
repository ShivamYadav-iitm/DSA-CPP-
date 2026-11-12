#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        long long absDividend = std::abs((long long)dividend);
        long long absDivisor = std::abs((long long)divisor);

        long long quotient = 0;

        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;

            while (absDividend >= (tempDivisor + tempDivisor)) {
                tempDivisor += tempDivisor; 
                multiple += multiple;     
            }

            absDividend -= tempDivisor;
            quotient += multiple;
        }

        if (isNegative) {
            return -quotient;
        }
        return quotient;
    }
};