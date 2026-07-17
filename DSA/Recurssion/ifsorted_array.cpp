#include<iostream>
using namespace std;


bool sorted(int arr[], int n,int i){
    if(i==n-1){
        return true;
    }
    else if(arr[i+1]<arr[i]){
        return false;
    }
    else{
        return sorted(arr,n,i+1);
    } 
}
int main(){
    int arr1[5] = {1,2,3,5,4};
    cout<<sorted(arr1,5,0);
    return 0;
}