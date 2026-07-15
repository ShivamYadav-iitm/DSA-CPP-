#include<iostream>
using namespace std;

int expo(int num,int pow){
    int ans = 1;
    while(pow>0){
        int lastdig = pow & 1;
        if(lastdig == 1){
            ans *= num;
            num = num*num;
        } 
        else{
            num = num * num;
        }
        pow = pow >> 1;
    }
    return ans;
}

int main(){
    int num = 2;
    int pow = 5;
    cout<<expo(num,pow);
    return 0;
}