#include<iostream>
using namespace std;

int Binarysearch(int *arr,int n,int key){
    
    int start = 0,end = n-1;
   
    while(start<=end){
        int mid = (start+end) /2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            start = mid+1;
        }
        else{
            end =mid-1;
        }
    }
    return -1; 
}

int main(){
    int arr[] = {1,2,4,7,11,33,45};
    int len = sizeof(arr)/sizeof(int);
    int key =49;
    cout<<Binarysearch(arr,len,key);
    return 0;
}