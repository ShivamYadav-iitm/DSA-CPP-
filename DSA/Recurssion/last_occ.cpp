#include<iostream>
#include<vector>
using namespace std;


int occ(vector<int> arr,int i,int tar){
    int n = arr.size();

    if(arr[i]==tar){
        return i;
    }
    else if(i==0){
        return -1;
    }

    return occ(arr,i-1,tar); 
}
int main(){
    vector<int> arr1 = {1,2,3,6,2,4,5,6,7,8,8};
    int n = arr1.size();
    cout<<occ(arr1,n,2);
    return 0;
}