#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int position = 0;
        int count = 0;
        for(int i=0 ; i<nums.size();i++){
            if(nums[i] == 0){
                count++;
            }
            if(nums[i] != 0){
                nums[position] = nums[i];
                position++; 
            }
        }
        for(int i=0;i<count;i++){
            nums.pop_back();
        }
        for(int i=0;i<count;i++){
            nums.push_back(0);
        }
    }
};