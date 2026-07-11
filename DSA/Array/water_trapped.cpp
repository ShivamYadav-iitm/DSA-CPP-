#include<iostream>
#include<climits>
using namespace std;

int watertrapped(int *heights,int n){
    int left_max[20000];
    int right_max[20000];
    left_max[0] = heights[0];
    right_max[n-1] = heights[n-1];

    for(int i=1;i<n;i++){
        left_max[i] = max(left_max[i-1] , heights[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        right_max[i] = max(right_max[i+1], heights[i+1]);
    }
    int currWater = 0;
    int trappedwater = 0;
    for(int i=0;i<n;i++){
        currWater = min(left_max[i],right_max[i]) - heights[i];
        if(currWater > 0){
            trappedwater += currWater;
        }
    }
    return trappedwater;
}

int main(){
    int arr[10] = {1,6,5,8,3,9,0,7,0,9};
    int len = sizeof(arr)/sizeof(int);
    cout<<watertrapped(arr,len);
    return 0;
}
