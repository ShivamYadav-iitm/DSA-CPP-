#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int digsum = 0;
        int numb;
        int lastdig;
        for(int i=0;i<nums.size();i++){
            numb = nums[i];
            while(numb>0){
                lastdig = numb%10;
                digsum += lastdig;
                numb = numb/10;
            }
            if(digsum == i){
                return i;
            }
            digsum =0;
        }
        return -1;
    }
};