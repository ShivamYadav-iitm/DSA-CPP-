#include<iostream>
#include<climits>
using namespace std;

bool duplicate(int *arr,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                return true;
            }
            
        }
    }
    return false;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int len = sizeof(arr)/sizeof(int);
    cout<<duplicate(arr,len);
    return 0;
}