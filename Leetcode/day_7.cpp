#include <algorithm>
#include <string>
#include<iostream>
using namespace std;

class Solution {
    int dp[55][35];
    
    void addFactors(int digit, int &p2, int &p3, int &p5, int &p7) {
        if (digit == 2) p2++;
        else if (digit == 3) p3++;
        else if (digit == 4) p2 += 2;
        else if (digit == 5) p5++;
        else if (digit == 6) { p2++; p3++; }
        else if (digit == 7) p7++;
        else if (digit == 8) p2 += 3;
        else if (digit == 9) p3 += 2;
    }

    void removeFactors(int digit, int &p2, int &p3, int &p5, int &p7) {
        if (digit == 2) p2--;
        else if (digit == 3) p3--;
        else if (digit == 4) p2 -= 2;
        else if (digit == 5) p5--;
        else if (digit == 6) { p2--; p3--; }
        else if (digit == 7) p7--;
        else if (digit == 8) p2 -= 3;
        else if (digit == 9) p3 -= 2;
    }

public:
    string smallestNumber(string num, long long t) {
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        long long temp_t = t;
        while (temp_t % 2 == 0) { req2++; temp_t /= 2; }
        while (temp_t % 3 == 0) { req3++; temp_t /= 3; }
        while (temp_t % 5 == 0) { req5++; temp_t /= 5; }
        while (temp_t % 7 == 0) { req7++; temp_t /= 7; }
        if (temp_t > 1) return "-1";

        for (int i = 0; i < 55; i++) {
            for (int j = 0; j < 35; j++) {
                if (i == 0 && j == 0) { dp[i][j] = 0; continue; }
                int res = 1e9;
                if (i > 0) res = min(res, 1 + dp[max(0, i-1)][j]); 
                if (j > 0) res = min(res, 1 + dp[i][max(0, j-1)]);
                if (i > 0) res = min(res, 1 + dp[max(0, i-2)][j]); 
                if (i > 0 || j > 0) res = min(res, 1 + dp[max(0, i-1)][max(0, j-1)]); 
                if (i > 0) res = min(res, 1 + dp[max(0, i-3)][j]); 
                if (j > 0) res = min(res, 1 + dp[i][max(0, j-2)]);
                dp[i][j] = res;
            }
        }

        int n = num.length();
        bool hasZero = false;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0' || hasZero) {
                num[i] = '1';
                hasZero = true;
            }
        }

        int p2 = 0, p3 = 0, p5 = 0, p7 = 0;
        for (char c : num) addFactors(c - '0', p2, p3, p5, p7);
        
        if (p2 >= req2 && p3 >= req3 && p5 >= req5 && p7 >= req7) return num;

        for (int i = n - 1; i >= 0; i--) {
            removeFactors(num[i] - '0', p2, p3, p5, p7);

            for (int d = num[i] - '0' + 1; d <= 9; d++) {
                int tp2 = p2, tp3 = p3, tp5 = p5, tp7 = p7;
                addFactors(d, tp2, tp3, tp5, tp7);

                int r2 = max(0, req2 - tp2);
                int r3 = max(0, req3 - tp3);
                int r5 = max(0, req5 - tp5);
                int r7 = max(0, req7 - tp7);
                
                int spots = n - 1 - i;

                if (r5 + r7 + dp[r2][r3] <= spots) {
                    num[i] = d + '0';
                    
                    for (int j = i + 1; j < n; j++) {
                        for (int fill = 1; fill <= 9; fill++) {
                            int fp2 = tp2, fp3 = tp3, fp5 = tp5, fp7 = tp7;
                            addFactors(fill, fp2, fp3, fp5, fp7);
                            
                            int rem2 = max(0, req2 - fp2);
                            int rem3 = max(0, req3 - fp3);
                            int rem5 = max(0, req5 - fp5);
                            int rem7 = max(0, req7 - fp7);
                            
                            if (rem5 + rem7 + dp[rem2][rem3] <= n - 1 - j) {
                                num[j] = fill + '0';
                                tp2 = fp2; tp3 = fp3; tp5 = fp5; tp7 = fp7;
                                break; 
                            }
                        }
                    }
                    return num;
                }
            }
        }

        int min_required_length = req5 + req7 + dp[req2][req3];
        int new_len = max(n + 1, min_required_length);
        string res(new_len, '1'); 
        
        p2 = 0; p3 = 0; p5 = 0; p7 = 0;
        
        for (int j = 0; j < new_len; j++) {
            for (int fill = 1; fill <= 9; fill++) {
                int fp2 = p2, fp3 = p3, fp5 = p5, fp7 = p7;
                addFactors(fill, fp2, fp3, fp5, fp7);
                
                int rem2 = max(0, req2 - fp2);
                int rem3 = max(0, req3 - fp3);
                int rem5 = max(0, req5 - fp5);
                int rem7 = max(0, req7 - fp7);
                
                if (rem5 + rem7 + dp[rem2][rem3] <= new_len - 1 - j) {
                    res[j] = fill + '0';
                    p2 = fp2; p3 = fp3; p5 = fp5; p7 = fp7;
                    break;
                }
            }
        }
        return res;
    }
};