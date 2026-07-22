#include<iostream>
using namespace std;

int partition(int arr[],int si,int ei){
    int pivot = arr[ei];
    int i = si-1;
    for(int j=si;j<ei;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[ei]);
    return i;

}

void quicksort(int arr[],int si,int ei){
    if(si>=ei){
        return;
    }
    int pivotIdx = partition(arr,si,ei);
    
    quicksort(arr,si,pivotIdx-1);
    quicksort(arr,pivotIdx+1,ei);
}

void print(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {6,3,7,5,2,4};
    int n = sizeof(arr)/sizeof(int);
    quicksort(arr,0,n-1);
    print(arr,n);
    return 0;
}