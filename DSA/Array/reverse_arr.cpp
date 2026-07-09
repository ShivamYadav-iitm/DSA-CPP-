#include<iostream>
using namespace std;

//using extra space

// void Reverse(int arr[] ,int n){
//     int arr2[n];
//     for(int i=0;i<n;i++){
//         int j= n-i-1;
//         arr2[i] = arr[j];
//         }
    
//     for(int i=0;i<n;i++){
//         cout<<arr2[i]<<" ";
//     }
// }

//without using extra space


    


int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    int start = 0;
    int end = n-1;
    while(end>start){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
    return 0;
}