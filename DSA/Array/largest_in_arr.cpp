#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,5,16,11};
    int larg = 0;
    int len = sizeof(arr)/sizeof(int);
    for(int i=0;i<len;i++){
        if(arr[i]>larg){
            larg = arr[i];
        }
    }
    cout<<larg;
    return 0;
}
