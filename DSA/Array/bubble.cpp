#include<iostream>
using namespace std;

void bubblesort(int *arr , int n){
    bool isswap = false;
    for(int i =0;i<n;i++){
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isswap = true;
            }
        }
        if(!isswap){
            return;
        }
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int len = sizeof(arr)/sizeof(int);
    bubblesort(arr,len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<",";
    }
    return 0;
}