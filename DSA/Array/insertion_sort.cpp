#include<iostream>
using namespace std;

void insertion(int *arr,int n){
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int prev = i - 1;
        while(prev>=0 && arr[prev]>curr){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;
    }
}

int main(){
    int arr[] = {5,6,4,8,2,1,3,7};
    int len = sizeof(arr)/sizeof(int);
    insertion(arr,len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<",";
    }
    return 0;
}