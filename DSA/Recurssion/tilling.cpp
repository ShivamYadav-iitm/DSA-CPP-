#include<iostream>
using namespace std;

int tiling(int n){  // for 2xn floor
    if(n==0 || n==1){
        return 1;
    }
    return tiling(n-1) + tiling(n-2); //for 2x1 tile each
}

int main(){
    cout<< tiling(3);
    return 0;
}