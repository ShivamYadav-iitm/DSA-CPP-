class Solution {
public:
    bool canAliceWin(int n) {
        bool alicewins = false;
        bool bobwins = false;
        int k = 10;
        int count = 0;
        if(n<k){
            return false;
        }
        while(k<=n){
            n=n-k;
            k--;
            count++;
        }
        if(count%2 == 0){
            return false;
        }
        return true;
    }
};