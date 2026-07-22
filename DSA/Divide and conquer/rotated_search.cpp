#include<iostream>
using namespace std;

int search(int arr[],int si,int ei,int tar){   //O{logn}
    if(si>ei){
        return -1;
    }
    int mid = si + (ei-si)/2;
    if(arr[mid]==tar){
        return mid;
    }

    if(arr[si]<=arr[mid]){ //L1
        //LEFT
        if(arr[si]<=tar && tar<=arr[mid]){
            search(arr,si,mid-1,tar);
        }
        else{ 
            //RIGHT
            search(arr,mid+1,ei,tar);
        }
    }
    else{ //L2
        if(arr[mid]<=tar && tar<=arr[ei]){
            //RIGHT
            search(arr,mid+1,ei,tar);
        }
        else{
            //LEFT
            search(arr,si,mid-1,tar);
        }
    }
}


int main(){
    int arr[] = {4,5,6,7,0,1,2};
    int n = sizeof(arr)/sizeof(int);
    cout<<search(arr,0,n-1,2)<<endl;
    return 0;
}