#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int si = 0;
        int ei = arr.size()-1;
        return searchmax(arr,si,ei);  
    }
private:
    int searchmax(vector<int> &arr,int si,int ei){
        int mid = si + (ei-si)/2;
        if(si==ei){
            return si;
        }
        if(arr[mid]>arr[mid+1]){
            ei=mid;
            return searchmax(arr,si,ei);
        }
        else{
            si = mid+1;
            return searchmax(arr,si,ei);
        }
    }
};