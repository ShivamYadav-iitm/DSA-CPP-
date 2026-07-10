#include<iostream>
using namespace std;

void printsub(int *arr,int n){
    for(int start = 0;start<n;start++){
        for(int end = start;end<n;end++){
            for(int i = start;i<=end;i++){
                cout<<arr[i];
            }
            cout<<",";
            // cout<<arr[j];
        }
        cout<<"\n";
    }
}

int main(){
    int arr[] = {0,1,2,3,4};
    int len = sizeof(arr)/sizeof(int);
    printsub(arr,len);
    return 0;
}