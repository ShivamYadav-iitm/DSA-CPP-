#include<iostream>
using namespace std;

bool stair(int arr[][4],int n,int m,int key){
    int i =0 ; 
    int j = m-1;
    while(i<n && j>=0){
        if(arr[i][j]==key){
            cout<<"found at "<< i<<","<<j<<endl;
            return true;
        }
        else if(arr[i][j] > key){
            //left
            j--;
        }
        else{
            //down
            i++;
        }
    }
    return false;
    if(!stair){
        cout<<"not found"<<endl;
    }
}

int main(){
    int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    stair(arr,4,4,12);
    return 0;
}