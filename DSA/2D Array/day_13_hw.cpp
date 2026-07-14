#include<iostream>
using namespace std;

//-------------------------------------------------------searching in sorted 2d array{bruteforce method}

// bool ispresent(int arr[][4],int n,int m,int key){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j] == key){
//                 return true;
//             }
//         }
//     }
//     return false;
// }




//-------------------------------------------------------using binary search on 2d array row wise:
// int ispresent(int arr[][4],int n,int m,int key){
//     for(int i =0;i<n;i++){
//         int start = arr[i][0];
//         int end = arr[i][m-1];
//         int mid = (start+end)/2;
//         while(start<=end){
//             if(arr[i][mid] ==  key){
//                 return mid;
//             }
//             else if(arr[i][mid]<key){
//                 start = mid+1;
//             }
//             else{
//                 end = mid-1;
//             }
//         }
//     }
// }


int main(){
    int arr[4][4] = {{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    cout<<(arr,4,4,37);
    return 0;
}