#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[],int si,int ei,int mid){
    vector<int> temp;
    int i = si;
    int j = mid+1;
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
             temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=ei){
        temp.push_back(arr[j++]);
    }

    //vector --> org arr

    for(int idx=si,x =0;idx<=ei;idx++){
        arr[idx] = temp[x++];
    }

}

void mergesort(int arr[],int si,int ei){
    if(si>=ei){
        return;
    }
    int mid = si + (ei - si) /2;

    mergesort(arr,si,mid); //left 
    mergesort(arr,mid+1,ei); //right 

    merge(arr,si,ei,mid); //conquer
}
void print(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {6,3,7,5,2,4};
    int n = sizeof(arr)/sizeof(int);
    mergesort(arr,0,n-1);
    print(arr,n);
    return 0;
}