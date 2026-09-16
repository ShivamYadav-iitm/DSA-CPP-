class Solution {
    long long power(long long base, long long exp) {
        long long res = 1;
        long long mod = 1e9 + 7;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, 1e9 + 7 - 2);
    }

public:
    int numberOfSets(int n, int k) {
        long long mod = 1e9 + 7;
        
        int total_points = n + k - 1;
        int points_to_pick = 2 * k;
        
        if (total_points < points_to_pick) return 0; 

        long long numerator = 1;
        long long denominator = 1;

        for (int i = 0; i < points_to_pick; i++) {
            numerator = (numerator * (total_points - i)) % mod;
            denominator = (denominator * (i + 1)) % mod;
        }

        return (numerator * modInverse(denominator)) % mod;
    }
};