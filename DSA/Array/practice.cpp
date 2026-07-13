#include<iostream>
#include<climits>
using namespace std;

void bubble(int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void print(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}

void selection(int *arr,int n){
    for(int i=0;i<n-1;i++){
        int mindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mindex]){
                mindex = j;
            }
            swap(arr[i],arr[mindex]);
        }
    }
}

void insertion(int *arr,int n){
    for(int i=0;i<n;i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev]>curr){
            swap(arr[prev],arr[prev+1]);
            prev-- ;
        }
        arr[prev+1] = curr;
    }
}

void count(int *arr,int n){
    int freq[100000] = {0};
    int minv = INT_MAX;
    int maxv = INT_MIN;
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
        minv = min(arr[i],minv);
        maxv = max(arr[i],maxv);
    }

    for(int i=minv,j=0;i<=maxv;i++){
        arr[j++] = i;
        freq[i]--;
    }
}

int main(){
    int arr[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    int len = sizeof(arr)/sizeof(int);
    selection(arr,len);
    insertion(arr,len);
    bubble(arr,len);
    count(arr,len);
    print(arr,len);

}