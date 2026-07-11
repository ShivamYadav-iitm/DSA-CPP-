#include<iostream>
using namespace std;

void selectionsort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        int mindex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mindex])
            mindex = j;
        }
        swap(arr[i],arr[mindex]);
    }
}

int main(){
    int arr[] = {5,6,4,8,2,1,3,7};
    int len = sizeof(arr)/sizeof(int);
    selectionsort(arr,len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<",";
    }
    return 0;
}