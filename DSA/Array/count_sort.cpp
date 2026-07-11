#include<iostream>
#include<climits>
using namespace std;

void count(int *arr,int n){
    int freq[100000] = {0};
    int MIN_VALUE = INT_MAX;
    int MAX_VALUE = INT_MIN;

    for(int i=0;i<n;i++){
        freq[arr[i]]++;
        MIN_VALUE = min(arr[i],MIN_VALUE);
        MAX_VALUE = max(arr[i],MAX_VALUE);
    }

    for(int i=MIN_VALUE,j=0;i<=MAX_VALUE;i++){
        while(freq[i]>0){
            arr[j++] = i;
            freq[i]-- ;
        }
    }

}



int main(){
    int arr[] = {5,6,4,8,2,1,3,7};
    int len = sizeof(arr)/sizeof(int);
    count(arr,len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<",";
    }
    return 0;
}