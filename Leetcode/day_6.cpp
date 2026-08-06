#include<iostream>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        int i = n;
        while(true){
            int temp = i;
            int prodig = 1;

            while(temp>0){
                prodig *= temp %10;
                temp = temp/10;
            }

            if(prodig % t == 0){
                return i;
            }
            
            i++;
        }
        
    }
};