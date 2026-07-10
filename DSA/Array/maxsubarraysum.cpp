#include<iostream>
#include<climits>
using namespace std;

void maxsubarraysum1(int *arr,int n){
    int maxSum = INT_MIN;
    for(int start=0;start<n;start++){
        for(int end=start;end<n;end++){
            int currSum = 0;
            for(int i=start;i<=end;i++){
                currSum += arr[i];
            }
            cout<<currSum<<",";
            maxSum = max(maxSum ,currSum);
        }
        cout<<endl;
    }
    cout<<"maximum subarray sum is: "<<maxSum;
}

void maxsubarraysum2(int *arr,int n){
    int maxSum = INT_MIN;
    for(int start=0;start<n;start++){
        int currSum = 0;
        for(int end=start;end<n;end++){
            currSum += arr[end];
            maxSum = max(maxSum ,currSum);
        }
        cout<<endl;
    }
    cout<<"maximum subarray sum is: "<<maxSum;
}

int main(){
    int arr[6] = {2,-3,6,-5,4,2};
    int len = sizeof(arr)/sizeof(int);
    maxsubarraysum2(arr,len);
    return 0;
}
