#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        long long result=0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                int squa  = nums[i-1]*nums[i-1];
                result += squa;
            }
        }
        return result;
    }
};