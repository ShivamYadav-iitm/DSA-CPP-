#include<iostream>
#include<vector>
using namespace std;


int occ(vector<int> arr,int i,int tar){
    int n = arr.size();

    if(arr[i]==tar){
        return i;
    }
    else if(i==n-1){
        return -1;
    }

    return occ(arr,i+1,tar); 
}
int main(){
    vector<int> arr1 = {1,2,3,6,2,4,5,6,7,8,8};
    cout<<occ(arr1,0,10);
    return 0;
}