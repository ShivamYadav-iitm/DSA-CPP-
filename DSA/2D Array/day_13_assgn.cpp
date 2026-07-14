#include<iostream>
using namespace std;

//---------------------------------------------ques01----------------------------
//TC = O{N^2}
// int freq(int arr[][3], int n, int m,int key){
//     int num = 0;
//     for(int i = 0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j]==key){
//                 num ++;
//             }
//         }
//     }
//     return num;
// }

// int main(){
//     int arr[2][3] =  { {4,7,8}, {8,8,7} };
//     cout<<freq(arr,2,3,7);
//     return 0;
// }


//---------------------------------------------ques02----------------------------

int sumR(int arr[][3],int n,int m,int row){
    int sum = 0;
        for(int j=0;j<m;j++){
            sum += arr[row][j];
    }
    return sum;
}

int main(){
    int arr[3][3] =   { {1,4,9}, {11,4,3}, {2,2,3} };
    cout<<sumR(arr,3,3,1);
    return 0;
}